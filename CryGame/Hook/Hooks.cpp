/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#pragma warning( disable : 4731 )

#include "../FunCry/FunCry.h"
#include "../FunCry/Logging.h"
#include "../FunCry/Effect.h"

#include <psapi.h>
#pragma comment( lib , "Psapi.lib" )
static char *GetModuleBase( const char *Name ){
  HMODULE hModule = GetModuleHandleA( Name );
  MODULEINFO module_info;
  memset( &module_info , 0 , sizeof( module_info ) );
  if( GetModuleInformation( GetCurrentProcess( ) , hModule , &module_info , sizeof( module_info ) ) ){
    return (char *)module_info.lpBaseOfDll;
  }
  return NULL;
}

#include "LoadSound.h"
typedef ISound *(WINAPI *LoadSound)( const char * , int );
LoadSound fpLoadSound = NULL;
static LPVOID *pLoadSound;
static unsigned int LoadSound_ecx;
ISound *WINAPI trLoadSound( const char *szFile , int flags ){
  __asm{
    mov LoadSound_ecx, ecx;
  }

  const char *AdjustedSound = hkLoadSound::ProcessSound( szFile );

  __asm{
    mov ecx, LoadSound_ecx;
  }

  return fpLoadSound( AdjustedSound , flags );
}

#include "SpawnEntity.h"
typedef IEntity *(WINAPI *SpawnEntity)( CEntityDesc & , bool );
SpawnEntity fpSpawnEntity = NULL;
static LPVOID *pSpawnEntity;
static unsigned int SpawnEntity_ecx;
IEntity *WINAPI trSpawnEntity( CEntityDesc &ed , bool bAutoInit ){
  __asm{
    mov SpawnEntity_ecx, ecx;
  }

  hkSpawnEntity::ProcessEntity( ed );

  __asm{
    mov ecx, SpawnEntity_ecx;
  }

  return fpSpawnEntity( ed , bAutoInit );
}

#include "../MinHook/include/MinHook.h"
void FunCry::StartupHooks( ){
  FunLog::Log( FUNLOG_BASIC , "Start secondary system" );

  if( MH_Initialize( ) != MH_OK ){
    Effects::FancySoundCapability = false;
    Effects::FancyCharacterObjectCapability = false;

    FunLog::Log( FUNLOG_PROBLEM , "code 115" );
  }
  else{
    char *Base;

    if( Effects::FancySoundCapability ){
      Base = GetModuleBase( "CrySoundSystem.dll" );
      if( Base != NULL ){
        pLoadSound = reinterpret_cast<LPVOID *>( Base + 0x884A );
        if(
          MH_CreateHook( pLoadSound , &trLoadSound , reinterpret_cast<LPVOID *>( &fpLoadSound ) ) != MH_OK
          ||
          MH_EnableHook( pLoadSound ) != MH_OK
        ){
          FunLog::Log( FUNLOG_PROBLEM , "code 116" );
          Effects::FancySoundCapability = false;
        }
      }
      else{
        FunLog::Log( FUNLOG_PROBLEM , "code 117" );
        Effects::FancySoundCapability = false;
      }
    }

    if( Effects::FancyCharacterObjectCapability ){
      Base = GetModuleBase( "CryEntitySystem.dll" );
      if( Base != NULL ){
        pSpawnEntity = reinterpret_cast<LPVOID *>( Base + 0x22233 );
        if(
          MH_CreateHook( pSpawnEntity , &trSpawnEntity , reinterpret_cast<LPVOID *>( &fpSpawnEntity ) ) != MH_OK
          ||
          MH_EnableHook( pSpawnEntity ) != MH_OK
        ){
          FunLog::Log( FUNLOG_PROBLEM , "code 116" );
          Effects::FancyCharacterObjectCapability = false;
        }
      }
      else{
        FunLog::Log( FUNLOG_PROBLEM , "code 117" );
        Effects::FancyCharacterObjectCapability = false;
      }
    }
  }
}


void FunCry::ShutdownHooks( ){
  FunLog::Log( FUNLOG_BASIC , "Stop secondary system" );

  MH_DisableHook( pLoadSound );
  MH_DisableHook( pSpawnEntity );
  MH_Uninitialize( );
}
