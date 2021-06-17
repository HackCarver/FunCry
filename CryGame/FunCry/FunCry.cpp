/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "FunCry.h"
using namespace FunCry;
#include "Effect.h"
using namespace Effects;

#include "Logging.h"
#include <time.h>

#include "../Hook/LoadSound.h"
#include "../Hook/SpawnEntity.h"

CXGame            *FunCry::Game    = NULL;
IRenderer         *FunCry::Rend    = NULL;
I3DEngine         *FunCry::Eng     = NULL;
ITimer            *FunCry::Time    = NULL;
IScriptSystem     *FunCry::Script  = NULL;
ISoundSystem      *FunCry::Sound   = NULL;
IFFont            *FunCry::FunText = NULL;
IEntity           *FunCry::Jack    = NULL;
CPlayer           *FunCry::Carver  = NULL;
LPDIRECT3DDEVICE9  FunCry::D3D     = NULL;

bool FunCry::IsCutscene = false;
bool FunCry::IsGameplay = false;
bool FunCry::IsLoading  = false;
bool FunCry::IsPaused   = false;

bool FunCry::CanFunlog = false;

float Effects::ScaleW = 0;

bool Effects::FancySoundCapability           = false;
bool Effects::FancyCharacterObjectCapability = false;

void FunCry::Start( CXGame *FC ){
  Game = FC;
  CanFunlog = stricmp( FunCry::ReadCfg( "EnableDedicatedLogging" ).c_str( ) , "true" ) == 0;

  FunLog::Log( FUNLOG_ALWAYS , "Begin startup" );

  FancySoundCapability           = stricmp( FunCry::ReadCfg( "SoundCapability" ).c_str( ) , "false" ) != 0;
  FancyCharacterObjectCapability = stricmp( FunCry::ReadCfg( "CharacterObjectCapability" ).c_str( ) , "false" ) != 0;

  FunLog::Log( FUNLOG_ALWAYS , "_Reset_Log_" );
  FunLog::Log( FUNLOG_BASIC , "Begin startup" );

  Reset( FC );
  if( FancySoundCapability || FancyCharacterObjectCapability ){
    StartupHooks( );
  }
  hkLoadSound::StartupSoundDB( );
  if( FancyCharacterObjectCapability ){
    hkSpawnEntity::StartupEntities( );
  }
  StartupEffects( );
  Script->ExecuteFile( "Scripts\\FunCry.lua" );

  FunLog::Log( FUNLOG_BASIC , "Finish startup" );
}

void FunCry::Stop( ){
  FunLog::Log( FUNLOG_BASIC , "Begin shutdown" );

  ShutdownEffects( );
  hkLoadSound::ShutdownSoundDB( );
  hkSpawnEntity::ShutdownEntities( );
  ShutdownHooks( );

  Game    = NULL;
  Rend    = NULL;
  Eng     = NULL;
  Time    = NULL;
  Script  = NULL;
  Sound   = NULL;
  FunText = NULL;
  Jack    = NULL;
  Carver  = NULL;

  IsCutscene = NULL;
  IsGameplay = NULL;
  IsLoading  = NULL;
  IsPaused   = NULL;

  FunLog::Log( FUNLOG_BASIC , "Finish shutdown" );
  FunLog::Log( FUNLOG_ALWAYS , "_Dump_Log_" );
}

void FunCry::Reset( CXGame *FC ){
  FunLog::Log( FUNLOG_DETAIL , "Begin reset" );

  Game    = FC;
  Rend    = FC->GetSystem( )->GetIRenderer( );
  Eng     = FC->GetSystem( )->GetI3DEngine( );
  Time    = FC->GetSystem( )->GetITimer( );
  Script  = FC->GetScriptSystem( );
  Sound   = FC->GetSystem( )->GetISoundSystem( );
  FunText = FC->GetSystem( )->GetICryFont( )->GetFont( "radiosta" );
  Jack    = FC->GetMyPlayer( );
  D3D     = (LPDIRECT3DDEVICE9)Rend->EF_Query( EFQ_D3DDevice );

  if( Jack ){
    Jack->GetContainer( )->QueryContainerInterface( CIT_IPLAYER , (void **)&Carver );
  }

  ScaleW = ( 4.0f / 3.0f ) / ( (float)Rend->GetWidth( ) / (float)Rend->GetHeight( ) );

  srand( time( NULL ) );

  FunLog::Log( FUNLOG_DETAIL , "Finish reset" );
}

void FunCry::Update( bool Paused ){
  FunLog::Log( FUNLOG_DETAIL , "----- Begin update" );

  Jack = Game->GetMyPlayer( );

  if( Jack ){
    FunLog::Log( FUNLOG_DETAIL , "Got Jack" );

    if( Jack->GetContainer( )->QueryContainerInterface( CIT_IPLAYER , (void **)&Carver ) ){
      FunLog::Log( FUNLOG_DETAIL , "Got Carver" );
    }
    else{
      Carver = NULL;

      FunLog::Log( FUNLOG_DETAIL , "Could not get Carver" );
    }
  }
  else{
    FunLog::Log( FUNLOG_DETAIL , "Could not get Jack" );
  }

  ScaleW = ( 4.0f / 3.0f ) / ( (float)Rend->GetWidth( ) / (float)Rend->GetHeight( ) );

  IsPaused = Paused;
  if( IsPaused ){
    IsCutscene = false;
    IsGameplay = false;
    IsLoading = false;
  }
  else if(
    !IsCutscene
    &&
    !IsLoading
    &&
    Jack
    &&
    Carver
  ){
    IsGameplay = true;
  }

  UpdateEffects( IsCutscene , IsGameplay , IsLoading , IsPaused );

  Rend->SetState( GS_NODEPTHTEST );

  #ifdef FUNCRY_DETAIL_LOG
    FunText->Reset( );
    FunText->UseRealPixels( false );
    FunText->SetColor( color4f( 1 , 1 , 1 , 1.0f ) );
    FunText->SetSize( vector2f( 10.0f * ScaleW , 14.0f ) );

    FunText->DrawString( 700 , 100 , IsCutscene ? "CUTSCENE" : "-" , false );
    FunText->DrawString( 700 , 120 , IsGameplay ? "GAMEPLAY" : "-" , false );
    FunText->DrawString( 700 , 140 , IsLoading ? "LOADING" : "-" , false );
    FunText->DrawString( 700 , 160 , IsPaused ? "PAUSED" : "-" , false );

    SetWindowText( (HWND)Rend->GetHWND( ) , ( string( "Game is " ) + ( IsPaused ? "" : "not " ) + string( "paused, is " ) + ( IsLoading ? "" : "not " ) + string( "loading, is " ) + ( IsCutscene ? "" : "not " ) + string( "in cutscene, is " ) + ( IsGameplay ? "" : "not " ) + string( "in gameplay" ) ).c_str( ) );
  #endif

  FunLog::Log( FUNLOG_DETAIL , "----- Finish update" );
}

void FunCry::SeedRand( ){
  if( rand( ) % 2 == 1 ){
    srand( rand( ) );
    srand( rand( ) );
  }
  else{
    srand( time( NULL ) );
  }
}

void FunCry::CHECK_SCALEWIDTH( ){

  if( Script ){
    HSCRIPTFUNCTION FOWS = Script->GetFunctionPtr( "FunCry" , "CHECK_SW" );
    if( FOWS ){
      Script->BeginCall( FOWS );
      Script->EndCall( );
  
      Script->ReleaseFunc( FOWS );
      FOWS = 0;
    }
  }

};
