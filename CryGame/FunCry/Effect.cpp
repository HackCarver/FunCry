/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "FunCry.h"
#include "Effect.h"
using namespace FunCry;
using namespace Effects;

#include "Logging.h"

#include "../CryGame/XPlayer.h"
#include "../CryGame/XVehicle.h"

static GamePosDetail CachedPos;

static Vec3d Temp_FogColor;
static Vec3d Temp_WorldColor;
static float Temp_WorldColorRatio;
static Vec3d Temp_OutdoorAmbientColor;

static int Temp_MaxFPS = 500;

static HudState Temp_Hud;

static float Temp_Bob_Pitch  = 0.0f;
static float Temp_Bob_Roll   = 0.0f;
static float Temp_Bob_Length = 0.0f;

static float Temp_Crouch_Speed = 0.0f;
static float Temp_Prone_Speed = 0.0f;

static int SSx = 0;
static int SSy = 0;
static int SSvx = 2;
static int SSvy = -2;
static int SSSize = 140;
static int SStx = 0;
static int SSty = 0;
static float SSTimeDelay = 0.04f;
static float SSTimeLast = TimeNow;

#include "../Utility/Utility.h"

#include <sstream> /// TEMP

bool Effects::Start( Effect *Target ){
  FunLog::Log( FUNLOG_BASIC , ( "Start( " + Target->Title + " ) | Begin" ).c_str( ) );

  CHECK_SCALEWIDTH( );

  bool Started = false;
  bool NeedSound = true;

  #ifndef FUNCRY_DISABLE_ALL
    if(
      !Target->IsPaused
      ||
      (
        Target->IsPaused
        &&
        Target->IsResumable
      )
    ){
      switch( Target->Identifier ){
        case 526824 : { /// Shady business
          if( Rend ){
            Rend->EF_EnableHeatVision( true );

            Started = true;
          }
        }
        break;
        case 241947 : { /// Life is colorful
          if( Eng ){
            Temp_FogColor = Eng->GetFogColor( );
            Eng->SetFogColor( Vec3d( rand( ) % 256 , rand( ) % 256 , rand( ) % 256 ) );

            Temp_WorldColor = Eng->GetWorldColor( );
            Eng->SetWorldColor( Vec3d( rand( ) % 256 , rand( ) % 256 , rand( ) % 256 ) );

            Started = true;
          }

          Started = true;
        }
        break;
        case 123456 : { /// Zoom zoom
          if( Jack && Carver && Carver->IsAlive( ) ){
            float Ideal = ( ( 90.0f + ( ( ( (float)Rend->GetWidth( ) / (float)Rend->GetHeight( ) ) - ( 4.0f / 3.0f ) ) * 69.75f ) ) * 3.1415962f / 180.0f ) * 57.29571483438897f,
            Randomized = (float)( rand( ) % 179 );

            if(
              Randomized <= Ideal
              &&
              Randomized + 30.0f > Ideal
            ){
              Randomized = Ideal - 30.0f;
            }
            else if(
              Randomized >= Ideal
              &&
              Randomized - 30.0f < Ideal
            ){
              Randomized = Ideal + 30.0f;
            }

            if( Randomized < 40 ){
              Randomized = 40.0f;
            }
            else if( Randomized > 179 ){
              Randomized = 179.0f;
            }

            SetFOV( Randomized );

            Started = true;
          }
        }
        break;
        case 387247 : { /// On the move...
          if( Jack && Carver && Carver->IsAlive( ) ){
            PlaySound( "Languages/missiontalk/mutant/mutant_specific_A_1.wav" );
            NeedSound = false;

            bool FullyRandom = false;
            int OddsOfRandom = 5;
            const char *Level = Game->GetLevelName( );

            strcpy( CachedPos.Level , Level );
            CachedPos.Angle = Jack->GetAngles( );
            CachedPos.Pos = Jack->GetPos( );

            if( stricmp( Level , "Training" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Training[ Utility::getRandomIndex( SpawnSpot_Training.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Carrier" ) == 0 ){
              TeleportToSpecific( &SpawnSpot_Carrier[ Utility::getRandomIndex( SpawnSpot_Carrier.size( ) ) ] );
            }
            else if( stricmp( Level , "Fort" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Fort[ Utility::getRandomIndex( SpawnSpot_Fort.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Pier" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Pier[ Utility::getRandomIndex( SpawnSpot_Pier.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Research" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Research[ Utility::getRandomIndex( SpawnSpot_Research.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Treehouse" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Treehouse[ Utility::getRandomIndex( SpawnSpot_Treehouse.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Bunker" ) == 0 ){
              TeleportToSpecific( &SpawnSpot_Bunker[ Utility::getRandomIndex( SpawnSpot_Bunker.size( ) ) ] );
            }
            else if( stricmp( Level , "Steam" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Steam[ Utility::getRandomIndex( SpawnSpot_Steam.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Regulator" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Regulator[ Utility::getRandomIndex( SpawnSpot_Regulator.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Control" ) == 0 ){
              TeleportToSpecific( &SpawnSpot_Control[ Utility::getRandomIndex( SpawnSpot_Control.size( ) ) ] );
            }
            else if( stricmp( Level , "Rebellion" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Rebellion[ Utility::getRandomIndex( SpawnSpot_Rebellion.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Archive" ) == 0 ){
              TeleportToSpecific( &SpawnSpot_Archive[ Utility::getRandomIndex( SpawnSpot_Archive.size( ) ) ] );
            }
            else if( stricmp( Level , "Cooler" ) == 0 ){
              TeleportToSpecific( &SpawnSpot_Cooler[ Utility::getRandomIndex( SpawnSpot_Cooler.size( ) ) ] );
            }
            else if( stricmp( Level , "Boat" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Boat[ Utility::getRandomIndex( SpawnSpot_Boat.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Catacombs" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Catacombs[ Utility::getRandomIndex( SpawnSpot_Catacombs.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "River" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_River[ Utility::getRandomIndex( SpawnSpot_River.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Swamp" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Swamp[ Utility::getRandomIndex( SpawnSpot_Swamp.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Factory" ) == 0 ){
              TeleportToSpecific( &SpawnSpot_Factory[ Utility::getRandomIndex( SpawnSpot_Factory.size( ) ) ] );
            }
            else if( stricmp( Level , "Dam" ) == 0 ){
              if( Chance( OddsOfRandom ) ){
                FullyRandom = true;
              }
              else{
                TeleportToSpecific( &SpawnSpot_Dam[ Utility::getRandomIndex( SpawnSpot_Dam.size( ) ) ] );
              }
            }
            else if( stricmp( Level , "Volcano" ) == 0 ){
              TeleportToSpecific( &SpawnSpot_Volcano[ Utility::getRandomIndex( SpawnSpot_Volcano.size( ) ) ] );
            }
            else{
              FullyRandom = true;
            }

            if( FullyRandom ){
              TeleportTo( rand( ) % 2048 , rand( ) % 2048 );
            }

            Started = true;
          }
        }
        break;
        case 184542 : { /// What Hud?
          if( Script ){
            Script->SetGlobalValue( "cl_display_hud" , "0" );

            Started = true;
          }
        }
        break;
        case 924814 : { /// Is it really real?
          
          Started = true;
        }
        break;
        case 341034 : { /// Where you going?
          if( Jack && Carver ){
            if( Chance( 3 ) && PlaySound( Chance( 2 ) ? "Sounds/animals/monkey1.wav" : "Sounds/animals/monkey2.wav" ) ){
              NeedSound = false;
            }

            CVehicle *Vehicle = Carver->GetVehicle( );
            Vec3 Ang = Vehicle ? Vehicle->GetEntity( )->GetAngles( ) : Jack->GetAngles( );
            Ang.z = ( rand( ) % 360 );
            if( Vehicle ){
              Vehicle->GetEntity( )->SetAngles( Ang );
            }
            else{
              Jack->SetAngles( Ang );
            }

            Started = true;
          }
        }
        break;
        case 441904 : { /// Laggy cuteness
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "ca_RuntimeScale" );
          if( TVar ){
            TVar->ForceSet( Chance( 3 ) ? ( Chance( 2 ) ? "2.0" : "1.5" ) : "0.5" );

            Started = true;
          }
        }
        break;
        case 239823 : { /// Floaters
          ICVar *TVar1 = GetISystem( )->GetIConsole( )->GetCVar( "ca_NoAnim" );
          if( TVar1 ){
            TVar1->ForceSet( "1" );

            Started = true;
          }
        }
        break;
        case 264982 : { /// Mercs n boxes
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "ca_DrawBBox" );
          if( TVar ){
            TVar->ForceSet( "1" );

            Started = true;
          }
        }
        break;
        case 158294 : { /// Ghosts with guns
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "ca_NoDraw" );
          if( TVar ){
            TVar->ForceSet( "1" );

            Started = true;
          }
        }
        break;
        case 632673 : { /// Lag over 9000
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "g_maxfps" );
          if( TVar ){
            Temp_MaxFPS = TVar->GetIVal( );
            TVar->ForceSet( "5" );

            Started = true;
          }
        }
        break;
        case 825115 : { /// Wires and stuff
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "r_PolygonMode" );
          if( TVar ){
            TVar->ForceSet( "2" );

            Started = true;
          }
        }
        break;
        case 002742 : { /// Hurry up Jack!
          if( Script && Jack && Carver ){
            CVehicle *Vehicle = Carver->GetVehicle( );
            if( !Vehicle ){
              Script->SetGlobalValue( "fixed_time_step" , "0.0005" );
              FunCry::PlaySound( "Languages/voicepacks/MISSION_GENERIC/Mission_generic_A_17.wav" );
              NeedSound = false;

              Started = true;
            }
          }
        }
        break;
        case 782452 : { /// Why so fast?
          if( Script ){
            Script->SetGlobalValue( "fixed_time_step" , "0.008" );
            FunCry::PlaySound( "Languages/missiontalk/training/training_specific_D_26.wav" );
            NeedSound = false;

            Started = true;
          }
        }
        break;
        case 928374 : { /// Full health!
          if( Carver && Carver->IsAlive( ) ){
            Carver->m_stats.health = Carver->m_stats.maxHealth;

            Started = true;
          }
        }
        break;
        case 656834 : { /// Full armor!
          if( Carver && Carver->IsAlive( ) ){
            Carver->m_stats.armor = Carver->m_stats.maxArmor;

            Started = true;
          } 
        }
        break;
        case 812093 : { /// Full stamina
          if( Carver && Carver->IsAlive( ) ){
            Carver->m_stats.stamina = 100;

            Started = true;
          }
        }
        break;
        case 426374 : { /// Random health and armor
          if( Carver && Carver->IsAlive( ) ){
            Carver->m_stats.armor = rand( ) % Carver->m_stats.maxArmor;
            Carver->m_stats.health = rand( ) % Carver->m_stats.maxHealth;

            Started = true;
          }
        }
        break;
        case 837643 : { /// Last 20 rounds
          if( Carver && Carver->IsAlive( ) ){
            int aic = Carver->m_stats.ammo_in_clip;
            if( aic > 20 ){
              Carver->m_stats.ammo_in_clip = 20;
              Carver->m_stats.ammo = 0;
            }
            else{
              Carver->m_stats.ammo = 20 - aic;
            }

            Started = true;
          }
        }
        break;
        case 365653 : { /// Full ammo!
          if( Carver && Carver->IsAlive( ) ){
            Carver->m_stats.ammo = 300;

            Started = true;
          }
        }
        break;
        case 894254 : { /// Remove all weapons
          
          Started = true;
        }
        break;
        case 244310 : { /// Screensaver
          if( !Target->IsPaused ){
            SSx = ( rand( ) % 400 ) + 200;
            SSy = ( rand( ) % 300 ) + 150;
          }
          IsScreenSaver = true;

          Started = true;
        }
        break;
        case 656564 : { /// Negativity
          SimpleFilterActive = true;
          SimpleFilterCode = 656564;

          Started = true;
        }
        break;
        case 343221 : { /// Black Ops
          if( Script ){
            HSCRIPTFUNCTION CHair = Script->GetFunctionPtr( "FunCry" , "DoCrosshair" );
            HSCRIPTFUNCTION TRad = Script->GetFunctionPtr( "FunCry" , "CIAWork" );
            if( CHair && TRad ){
              ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "p_bob_weapon" );
              if( TVar ){
                TVar->ForceSet( "0.001" );
              }

              Script->BeginCall( CHair );
              Script->PushFuncParam( NULL );
              Script->PushFuncParam( 0 );
              Script->EndCall( );

              Script->BeginCall( TRad );
              Script->PushFuncParam( NULL );
              Script->PushFuncParam( 1 );
              Script->EndCall( );

              IsInfiniteStamina = true;
              CIAWork = true;
              NeedWeapShaderUpdate = true;
              Started = true;
            }

            if( CHair ){ Script->ReleaseFunc( CHair ); }
            if( TRad ){ Script->ReleaseFunc( TRad ); }

            CHair = 0;
            TRad = 0;
          }
        }
        break;
        case 224546 : { /// Frozen!
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "game_Allow_AI_Movement" );
          if( TVar ){
            TVar->ForceSet( "0" );

            Started = true;
          }
        }
        break;
        case 221111 : { /// Faded Hud
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "hud_fadeamount" );
          if( TVar ){
            TVar->ForceSet( "0.1" );

            Started = true;
          }
        }
        break;
        case 832984 : { /// Size matters
          SizeMatters = true;

          Started = true;
        }
        break;
        case 775643 : { /// Who needs widescreen?
          if( Script ){
            HSCRIPTFUNCTION FOWS = Script->GetFunctionPtr( "FunCry" , "DoFOWS" );
            if( FOWS ){
              Script->BeginCall( FOWS );
              Script->PushFuncParam( NULL );
              Script->PushFuncParam( 0 );
              Script->EndCall( );
              Script->ReleaseFunc( FOWS );
              FOWS = 0;

              WidescreenEnabled = false;
              Started = true;
            }
          }
        }
        break;
        case 172634 : { /// Alternative HUD
          if( Script ){
            HSCRIPTFUNCTION FOWS = Script->GetFunctionPtr( "FunCry" , "AltHUD" );
            if( FOWS ){
              Script->BeginCall( FOWS );
              Script->PushFuncParam( NULL );
              Script->PushFuncParam( 0 );
              Script->PushFuncParam( -460 );
              Script->PushFuncParam( -530 - ( ( ( 3.0f / 4.0f ) - ( (float)Rend->GetHeight( ) / (float)Rend->GetWidth( ) ) ) * 360.0f ) );
              Script->PushFuncParam( 0 );
              Script->EndCall( );
              Script->ReleaseFunc( FOWS );
              FOWS = 0;

              Started = true;
            }
          }
        }
        break;
        case 765354 : { /// Funky Hud
          if( Script ){
            HSCRIPTFUNCTION FOWS = Script->GetFunctionPtr( "FunCry" , "AltHUD" );
            if( FOWS ){
              Script->BeginCall( FOWS );
              Script->PushFuncParam( NULL );

              if( Target->IsPaused && Temp_Hud.IsSet( ) ){
                Script->PushFuncParam( Temp_Hud.LeftX );
                Script->PushFuncParam( Temp_Hud.LeftY );
                Script->PushFuncParam( Temp_Hud.RightX );
                Script->PushFuncParam( Temp_Hud.RightY );
                Script->PushFuncParam( Temp_Hud.ScaleX );
                Script->PushFuncParam( Temp_Hud.ScaleW );
              }
              else{
                Temp_Hud.Set(
                  rand( ) % 500,
                  -( rand( ) % 460 ),
                  -rand( ) % 590,
                  -( rand( ) % 460 ),
                  (float)( rand( ) % 150 + 20 ) / 100.0f,
                  (float)( rand( ) % 150 + 20 ) / 100.0f
                );

                Script->PushFuncParam( Temp_Hud.LeftX );
                Script->PushFuncParam( Temp_Hud.LeftY );
                Script->PushFuncParam( Temp_Hud.RightX );
                Script->PushFuncParam( Temp_Hud.RightY );
                Script->PushFuncParam( Temp_Hud.ScaleX );
                Script->PushFuncParam( Temp_Hud.ScaleW );
              }

              Script->EndCall( );

              Script->ReleaseFunc( FOWS );
              FOWS = 0;

              ScaleW_Temp = Temp_Hud.ScaleW;
              IsFunkyHud = true;
              Started = true;
            }
          }
        }
        break;
        case 774423 : { /// Funky Weapon
          IsFunkyWeapon = true;

          Started = true;
        }
        break;
        case 783332 : { /// Healthy life
          IsInfiniteHealth = true;

          Started = true;
        }
        break;
        case 424234 : { /// Custom
          if( Eng ){
            IsCustomExperiment = true;

            Started = true;
          }
        }
        break;
        case 692114 : { /// Ghost town
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_brushes" );
          if( TVar ){
            TVar->ForceSet( "0" );

            Started = true;
          }
        }
        break;
        case 986689 : { /// Jitter
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "ca_UpdateSpeed" );
          if( TVar ){
            TVar->ForceSet( "15" );

            Started = true;
          }
        }
        break;
        case 457633 : { /// "Boxes
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_bboxes" );
          if( TVar ){
            TVar->ForceSet( "1" );

            Started = true;
          }
        }
        break;
        case 111344 : { /// Blurry terrain
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_detail_texture" );
          if( TVar ){
            TVar->ForceSet( "0" );

            Started = true;
          }
        }
        break;
        case 555343 : { /// What terrain?
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_terrain" );
          if( TVar ){
            TVar->ForceSet( "0" );

            Started = true;
          }
        }
        break;
        case 999552 : { /// Matrix
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_terrain_draw_this_sector_only" );
          if( TVar ){
            if( PlaySound( rand( ) % 2 == 1 ? "Languages/missiontalk/treetop/treetop_specific_A_3.wav" : "Languages/missiontalk/treetop/treetop_specific_A_11.wav" ) ){ // yea exploding comm centers will do that : you're kidding me 
              NeedSound = false;
            }
            TVar->ForceSet( "1" );

            Started = true;
          }
        }
        break;
        case 321333 : { /// Tomato
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_terrain_texture_bind" );
          if( TVar ){
            TVar->ForceSet( "0" );

            Started = true;
          }
        }
        break;
        case 555232 : { /// Agent Orange
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_vegetation" );
          if( TVar ){
            TVar->ForceSet( "0" );

            Started = true;
          }
        }
        break;
        case 213123 : { /// Big jump
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "p_gravity_modifier" );
          if( TVar ){
            TVar->ForceSet( "0.2" );

            Started = true;
          }
        }
        break;
        case 112222 : { /// Hangover
          if( Carver ){
            Temp_Bob_Pitch  = Carver->m_walkParams.runPitch;
            Temp_Bob_Roll   = Carver->m_walkParams.runRoll;
            Temp_Bob_Length = Carver->m_walkParams.stepLength;
            Carver->SetCameraBob( 1 , 1 , 15.0f );

            IsDrunk = true;
            Started = true;
          }
        }
        break;
        case 442457 : { /// Speedy crouch
          if( Carver ){
            Temp_Crouch_Speed = Game->p_speed_crouch->GetFVal( );
            Carver->SetCrouchSpeed( Temp_Crouch_Speed * 5.0f );

            Started = true;
          }
        }
        break;
        case 842435 : { /// Speedy prone
          if( Carver ){
            Temp_Prone_Speed = Game->p_speed_prone->GetFVal( );
            Carver->SetProneSpeed( Temp_Prone_Speed * 15.0f );

            Started = true;
          }
        }
        break;
        case 455746 : { /// In the matrix
          if( D3D ){
            IsMatrixV2 = true;

            Started = true;
          }
        }
        break;
        case 985949 : { /// CyberCry 2077
          IsCyberCry = true;
          NeedWeapShaderUpdate = true;
          Started = true;
        }
        break;
        case 633212 : { /// Nothing
          Started = true;
        }
        break;
        case 887678 : { /// Remove armor
          if( Carver && Carver->IsAlive( ) ){
            Carver->m_stats.armor = 0;
            Started = true;
          }
        }
        break;
        case 634332 : { /// Out of breath
          IsZeroStamina = true;

          Started = true;
        }
        break;
        case 234442 : { /// Infinite armor
          IsInfiniteArmor = true;

          Started = true;
        }
        break;
        case 534543 : { /// Is that you, Val?
          if( FancySoundCapability ){
            IsValVoice = true;

            Started = true;
          }
        }
        break;
        case 435647 : { /// Pulse
          IsPulsingHud = true;
          PulsingHudMultiplier = 1;

          Started = true;
        }
        break;
        
        
        /*
        case 444333 : { /// Guns have feelings
          if( FancySoundCapability ){
            IsPainfulWeapon = true;

            Started = true;
          }
        }
        break;
        */
      }
    }
    else if( Target->IsPaused ){
      Started = true;
      NeedSound = false;
    }
  #else
    Started = true;
  #endif

  CHECK_SCALEWIDTH( );

  if( Started ){
    FunLog::Log( FUNLOG_BASIC , ( "Start( " + Target->Title + " ) | Success" ).c_str( ) );

    if(
      !Target->IsPaused
      &&
      NeedSound
    ){
      PlaySound( );
    }

    Target->TimeStarted = TimeNow;
    if(
      Target->IsPaused
      &&
      Target->TimeActive > 0
      &&
      Target->TimeEffective > Target->TimeActive
    ){
      Target->TimeStarted -= Target->TimeActive;
      Target->TimeActive = 0;
    }
    Target->IsStale = false;
    Target->IsPaused = false;
    Target->IsActive = true;

    if( Target->IsRare ){
      TimeRareStarted = TimeNow;

      if( Target->IsVeryRare ){
        LastVeryRareIdentifier = Target->Identifier;
      }
    }
  }
  else{
    FunLog::Log( FUNLOG_BASIC , ( "Start( " + Target->Title + " ) | Failure" ).c_str( ) );

    Target->IsActive = false;
    Target->IsStale = true;
  }

  return true;
}

void Effects::Stop( Effect *Target , bool Pause ){
  FunLog::Log( FUNLOG_BASIC , ( "Stop( " + Target->Title + " ) | Begin" ).c_str( ) );

  CHECK_SCALEWIDTH( );

  #ifndef FUNCRY_DISABLE_ALL
    if(
      !Pause
      ||
      (
        Pause
        &&
        Target->IsPausable
      )
    ){
      switch( Target->Identifier ){
        case 526824 : { /// Shady business
          if( Rend ){
            Rend->EF_EnableHeatVision( false );
          }
        }
        break;
        case 241947 : { /// Life is colorful
          if( Eng ){
            Eng->SetFogColor( Temp_FogColor );
            Eng->SetWorldColor( Temp_WorldColor );
          }
        }
        break;
        case 123456 : { /// Zoom zoom
          if( Rend ){
            SetFOV( ( ( 90.0f + ( ( ( (float)Rend->GetWidth( ) / (float)Rend->GetHeight( ) ) - ( 4.0f / 3.0f ) ) * 69.75f ) ) * 3.1415962f / 180.0f ) * 57.29571483438897f );
          }
        }
        break;
        case 387247 : { /// On the move...
          if(
            Jack
            &&
            Chance( 5 )
          ){
            if( stricmp( Game->GetLevelName( ) , CachedPos.Level ) == 0 ){
              TeleportToSpecific( &CachedPos );
            }
          }
        }
        break;
        case 184542 : { /// What Hud?
          if( Script ){
            Script->SetGlobalValue( "cl_display_hud" , "1" );
          }
        }
        break;
        case 924814 : { /// Is it really real?
          
        }
        break;
        case 341034 : { /// Where you going?
          if(
            Jack
            &&
            Chance( 2 )
          ){
            Vec3 Ang = Jack->GetAngles( );
            Ang.z = ( rand( ) % 360 );
            Jack->SetAngles( Ang );
          }
        }
        break;
        case 441904 : { /// Laggy cuteness
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "ca_RuntimeScale" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 239823 : { /// Floaters
          ICVar *TVar1 = GetISystem( )->GetIConsole( )->GetCVar( "ca_NoAnim" );
          if( TVar1 ){
            TVar1->ForceSet( "0" );
          }
        }
        break;
        case 264982 : { /// Mercs n boxes
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "ca_DrawBBox" );
          if( TVar ){
            TVar->ForceSet( "0" );
          }
        }
        break;
        case 158294 : { /// Ghosts with guns
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "ca_NoDraw" );
          if( TVar ){
            TVar->ForceSet( "0" );
          }
        }
        break;
        case 632673 : { /// Lag over 9000
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "g_maxfps" );
          if( TVar ){
            TVar->Set( Temp_MaxFPS );
          }
        }
        break;
        case 825115 : { /// Wires and stuff
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "r_PolygonMode" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 002742 : { /// Hurry up Jack!
          if( Script ){
            Script->SetGlobalValue( "fixed_time_step" , "0" );
          }
        }
        break;
        case 782452 : { /// Why so fast?
          if( Script ){
            Script->SetGlobalValue( "fixed_time_step" , "0" );
          }
        }
        break;
        case 928374 : { /// Full health!
          // N/A
        }
        break;
        case 656834 : { /// Full armor!
          // N/A
        }
        break;
        case 812093 : { /// Full stamina
          // N/A
        }
        break;
        case 426374 : { /// Random health and armor
          // N/A
        }
        break;
        case 837643 : { /// Last 20 rounds
          // N/A
        }
        break;
        case 365653 : { /// Full ammo!
          // N/A
        }
        break;
        case 894254 : { /// Remove all weapons
          
        }
        break;
        case 244310 : { /// Screensaver
          SSTimeLast = 0;
          IsScreenSaver = false;
        }
        break;
        case 656564 : { /// Negativity
          SimpleFilterActive = false;
        }
        break;
        case 343221 : { /// Black Ops
          if( Script ){
            HSCRIPTFUNCTION CHair = Script->GetFunctionPtr( "FunCry" , "DoCrosshair" );
            HSCRIPTFUNCTION TRad = Script->GetFunctionPtr( "FunCry" , "CIAWork" );
            if( CHair && TRad ){
              ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "p_bob_weapon" );
              if( TVar ){
                TVar->ForceSet( "0.005" );
              }

              Script->BeginCall( CHair );
              Script->PushFuncParam( NULL );
              Script->PushFuncParam( 1 );
              Script->EndCall( );

              Script->BeginCall( TRad );
              Script->PushFuncParam( NULL );
              Script->PushFuncParam( 0 );
              Script->EndCall( );

              IsInfiniteStamina = false;
              CIAWork = false;
              NeedWeapShaderUpdate = true;
            }

            if( CHair ){ Script->ReleaseFunc( CHair ); }
            if( TRad ){ Script->ReleaseFunc( TRad ); }

            CHair = 0;
            TRad = 0;
          }
        }
        break;
        case 224546 : { /// Frozen!
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "game_Allow_AI_Movement" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 221111 : { /// Faded Hud
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "hud_fadeamount" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 832984 : { /// Size matters
          SizeMatters = false;
        }
        break;
        case 775643 : { /// Who needs widescreen?
          if( Script ){
            HSCRIPTFUNCTION FOWS = Script->GetFunctionPtr( "FunCry" , "DoFOWS" );
            if( FOWS ){
              Script->BeginCall( FOWS );
              Script->PushFuncParam( NULL );
              Script->PushFuncParam( 1 );
              Script->EndCall( );
              Script->ReleaseFunc( FOWS );
              FOWS = 0;

              WidescreenEnabled = true;
            }
          }
        }
        break;
        case 172634 : { /// Alternative HUD
          if( Script ){
            HSCRIPTFUNCTION FOWS = Script->GetFunctionPtr( "FunCry" , "AltHUD" );
            if( FOWS ){
              Script->BeginCall( FOWS );
              Script->PushFuncParam( NULL );
              Script->PushFuncParam( 0 );
              Script->PushFuncParam( 0 );
              Script->PushFuncParam( 0 );
              Script->PushFuncParam( 0 );
              Script->EndCall( );
              Script->ReleaseFunc( FOWS );
              FOWS = 0;
            }
          }
        }
        break;
        case 765354 : { /// Funky Hud
          if( Script ){
            HSCRIPTFUNCTION FOWS = Script->GetFunctionPtr( "FunCry" , "AltHUD" );
            if(
              FOWS
              &&
              Rend
            ){
              Script->BeginCall( FOWS );
              Script->PushFuncParam( NULL );
              Script->PushFuncParam( 0 );
              Script->PushFuncParam( 0 );
              Script->PushFuncParam( 0 );
              Script->PushFuncParam( 0 );
              Script->PushFuncParam( ( 3.0f / 4.0f ) - ( (float)Rend->GetHeight( ) / (float)Rend->GetWidth( ) ) );
              Script->PushFuncParam( ( 4.0f / 3.0f ) / ( (float)Rend->GetWidth( ) / (float)Rend->GetHeight( ) ) );
              Script->EndCall( );

              ScaleW_Temp = 0;
            }

            if( FOWS ){ Script->ReleaseFunc( FOWS ); }
            FOWS = 0;

            if( !Pause ){
              Temp_Hud.Clear( );
            }

            IsFunkyHud = false;
          }
        }
        break;
        case 774423 : { /// Funky Weapon
          IsFunkyWeapon = false;
        }
        break;
        case 783332 : { /// Healthy life
          IsInfiniteHealth = false;
        }
        break;
        case 424234 : { /// Custom

          IsCustomExperiment = false;

        }
        break;
        case 692114 : { /// Ghost town
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_brushes" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 986689 : { /// Jitter
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "ca_UpdateSpeed" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 457633 : { /// Boxes
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_bboxes" );
          if( TVar ){
            TVar->ForceSet( "0" );
          }
        }
        break;
        case 111344 : { /// Blurry terrain
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_detail_texture" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 555343 : { /// What terrain?
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_terrain" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 999552 : { /// Matrix 
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_terrain_draw_this_sector_only" );
          if( TVar ){
            TVar->ForceSet( "0" );
          }
        }
        break;
        case 321333 : { /// Tomato
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_terrain_texture_bind" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 555232 : { /// Agent Orange
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_vegetation" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 213123 : { /// Big jump
          ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "p_gravity_modifier" );
          if( TVar ){
            TVar->ForceSet( "1" );
          }
        }
        break;
        case 112222 : { /// Hangover
          if( Carver ){
            Carver->SetCameraBob( Temp_Bob_Pitch , Temp_Bob_Roll , Temp_Bob_Length );
            IsDrunk = false;
          }
        }
        break;
        case 442457 : { /// Speedy crouch
          if( Carver ){
            Carver->SetCrouchSpeed( Temp_Crouch_Speed );
          }
        }
        break;
        case 842435 : { /// Speedy prone
          if( Carver ){
            Carver->SetProneSpeed( Temp_Prone_Speed );
          }
        }
        break;
        case 455746 : { /// In the matrix
          if( D3D ){
            IsMatrixV2 = true;
            Effects::DXAfterRender( );
          }
          IsMatrixV2 = false;
        }
        break;
        case 985949 : { /// CyberCry 2077
          IsCyberCry = false;
          NeedWeapShaderUpdate = true;
        }
        break;
        case 633212 : { /// Nothing
          
        }
        break;
        case 887678 : { /// Remove armor
          
        }
        break;
        case 634332 : { /// Out of breath
          IsZeroStamina = false;
        }
        break;
        case 234442 : { /// Infinite armor
          IsInfiniteArmor = false;
        }
        break;
        case 534543 : { /// Is that you, Val?
          if( FancySoundCapability ){
            IsValVoice = false;
          }
        }
        break;
        case 435647 : { /// Pulse
          IsPulsingHud = false;
          PulsingHudMultiplier = 1;
        }
        break;
        
        /*
        case 444333 : { /// Guns have feelings
          if( FancySoundCapability ){
            IsPainfulWeapon = false;
          }
        }
        break;
        */
      }
    }
  #endif

  Target->IsActive = false;
  Target->IsStale = true;

  CHECK_SCALEWIDTH( );

  FunLog::Log( FUNLOG_BASIC , ( "Stop( " + Target->Title + " ) | Finish" ).c_str( ) );
}

bool Effects::Chance( unsigned int Odds ){
  if( Odds < 1 ){
    return true;
  }
  return rand( ) % Odds == Odds - 1;
}

void Effects::TeleportTo( float x , float y ){
  FunLog::Log( FUNLOG_DETAIL , "TeleportTo( )" );

  if(
    Jack
    &&
    Carver
    &&
    Carver->IsAlive( )
  ){
    Vec3 Pos( x , y , Eng->GetTerrainElevation( x , y ) + 5.0f );
    CVehicle *Vehicle = Carver->GetVehicle( );
    if( Vehicle ){
      IEntity *Specific = Vehicle->GetEntity( );
      Specific->SetPos( Pos );
    }
    else{
      Jack->SetPos( Pos );
    }
  }
  else{
    FunLog::Log( FUNLOG_PROBLEM , "TeleportTo( ) | FAILED" );
  }
}

void Effects::TeleportToSpecific( GamePos *Dest ){
  FunLog::Log( FUNLOG_DETAIL , "TeleportToSpecific( )" );

  if(
    Jack
    &&
    Carver
    &&
    Carver->IsAlive( )
  ){
    CVehicle *Vehicle = Carver->GetVehicle( );
    if( Vehicle ){
      IEntity *Specific = Vehicle->GetEntity( );
      Specific->SetAngles( Dest->Angle );
      Specific->SetPos( Dest->Pos );
    }
    else{
       Jack->SetAngles( Dest->Angle );
       Jack->SetPos( Dest->Pos );
    }
  }
  else{
    FunLog::Log( FUNLOG_PROBLEM , "TeleportToSpecific( ) | FAILED" );
  }
}

void Effects::SetFOV( float Target ){
  FunLog::Log( FUNLOG_DETAIL , "SetFOV( )" );

  if( Target < 40.0f ){
    Target = 40.0f;
  }
  else if( Target > 179.5f ){
    Target = 179.5f;
  }

  Target = ( Target * 3.1415962f ) / 180.0f;
  if( Target > 3.13f ){
    Target = 3.13f;
  }

  HSCRIPTFUNCTION FOV = Script->GetFunctionPtr( "FunCry" , "SetFOV" );
  if( FOV ){
    Script->BeginCall( FOV );
    Script->PushFuncParam( NULL );
    Script->PushFuncParam( Target );
    Script->EndCall( );
    Script->ReleaseFunc( FOV );
    FOV = 0;
  }
}

void Effects::SimpleFilter( ){
  if( SimpleFilterActive ){
    if( SimpleFilterCode == 656564 ){ /// Negativity
      Rend->SetState( GS_DEPTHFUNC_GREAT | GS_NODEPTHTEST | GS_BLDST_ONEMINUSSRCALPHA | GS_BLSRC_ONEMINUSDSTCOL );
      Rend->Draw2dImage( 0 , 0 , 800 , 600 , DEF_TEXARG0 , 0 , 1 , 1 , 0 , 0 , 1 , 1 , 1 , 1 );
    }
  }
}

void Effects::DoAimedEffect( ){
  if(
    SizeMatters
    ||
    CIAWork
  ){
    if( Jack && Carver ){
      bool BodyHit = false;
      bool BodyDead = true;
      bool IsVehicle = Carver->GetVehicle( ) ? true : false;
      if(
        IsVehicle
        ||
        Carver->m_stats.aiming
      ){
        IEntityCamera *JackCam = Jack->GetCamera( );
        Vec3 CamPos = JackCam->GetPos( );
        Vec3 JackPos = Jack->GetPos( );
        Vec3 Pos( ( CamPos.x - JackPos.x ) + JackPos.x , ( CamPos.y - JackPos.y ) + JackPos.y , ( CamPos.z - JackPos.z ) + JackPos.z );

        Matrix44 tm;
        tm.SetIdentity( );
        tm = Matrix44::CreateRotationZYX( -Jack->GetAngles( ) * gf_DEGTORAD ) * tm;
        Vec3 DirVec = GetTransposed44( tm ) * Vec3( 0 , -1 , 0 );

        Vec3 VOffs = DirVec * 3.5f;
        DirVec *= IsVehicle ? 3000.0f : 2000.0f;

        IPhysicalEntity *skip = Jack->GetPhysics( );
        ray_hit hit;
        int res = Game->GetSystem( )->GetIPhysicalWorld( )->RayWorldIntersection( (const vectorf)( IsVehicle ? Pos + VOffs : Pos ) , (const vectorf)DirVec , ent_all , rwi_ignore_noncolliding | rwi_stop_at_pierceable , &hit , 1 , skip );

        if( res ){
          if( hit.pCollider ){
            IEntity *centycontact = (IEntity *)hit.pCollider->GetForeignData( );
            if( centycontact ){
              if(
                centycontact->GetClassId( ) >= 71
                &&
                centycontact->GetClassId( ) <= 83
              ){
                BodyHit = true;
                CPlayer *Enemy;

                if(
                  centycontact->GetContainer( )->QueryContainerInterface( CIT_IPLAYER , (void **)&Enemy )
                  &&
                  Enemy->m_stats.health > 0
                ){
                  BodyDead = false;
                } 
              }

              if( SizeMatters ){
                IScriptObject *pObj = centycontact->GetScriptObject( );
                if( pObj ){
                  centycontact->SetScale( 1.5f );
                }
              }
            }
          }
        }

        if( CIAWork && Rend ){
          if( BlackOpsCrosshair ){
            float r, g, b, a;
            float RetSize = 7.0f;
            if( BodyHit ){
              if( BodyDead ){
                r = 255;
                g = 0;
                b = 255;
                a = 255;
              }
              else{
                r = 255;
                g = 255;
                b = 0;
                a = 255;
              }
            }
            else{
              r = 1;
              g = 1;
              b = 1;
              a = 255;
            }
            Rend->SetState( GS_BLSRC_ONEMINUSDSTCOL | GS_BLSRC_SRCALPHA | GS_BLDST_ONEMINUSSRCCOL );
            Rend->Draw2dImage( 400.0f - ( ( RetSize / 2.0f ) * ScaleW ) , 300.0f - ( RetSize / 2.0f ) , RetSize * ScaleW , RetSize , BlackOpsCrosshair , 0 , 1 , 1 , 0 , 0 , r , g , b , a );
            Rend->Draw2dImage( 400.0f - ( ( RetSize / 2.0f ) * ScaleW ) , 300.0f - ( RetSize / 2.0f ) , RetSize * ScaleW , RetSize , BlackOpsCrosshair , 0 , 1 , 1 , 0 , 0 , r , g , b , a );
          }
          else{
            float r, g, b, a;
            if( BodyHit ){
              r = 255;
              g = 255;
              b = 0;
              a = 0.75f;
            }
            else{
              r = 1;
              g = 1;
              b = 1;
              a = 0.75f;
            }
            Rend->SetState( GS_BLSRC_SRCALPHA | GS_BLDST_ONEMINUSSRCALPHA | GS_NODEPTHTEST );
            Rend->Draw2dImage( 400.0f - ( 1.0f * ScaleW ) , 300.0f - 1.0f , 2.0f * ScaleW , 2 , DEF_TEXARG0 , 0 , 1 , 1 , 0 , 0 , r , g , b , a );
          }
        }
      }
    }
  }
}

void Effects::DoScreensaver( ){
  if( IsScreenSaver ){
    bool Advance = false;
    float TWidth = SSSize * ScaleW;

    if(
      SSTimeLast == 0
      ||
      TimeNow - SSTimeLast > SSTimeDelay
    ){
      Advance = true;
    }

    if( Advance ){
      SStx = SSx + SSvx;
      SSty = SSy + SSvy;
      if( SStx - TWidth <= 0 || SStx + TWidth >= 800 ){
        SSvx = -SSvx;
      }
      if( SSty - SSSize <= 0 || SSty + SSSize >= 600 ){
        SSvy = -SSvy;
      }
      SSTimeLast = TimeNow;
    }

    Rend->SetState( GS_NODEPTHTEST );
    Rend->Draw2dImage( SSx - 800 - TWidth , 0 , 800 , 600 , DEF_TEXARG0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 1 );
    Rend->Draw2dImage( SSx + TWidth , 0 , 800 , 600 , DEF_TEXARG0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 1 );
    Rend->Draw2dImage( 0 , SSy - 600 - SSSize , 800 , 600 , DEF_TEXARG0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 1 );
    Rend->Draw2dImage( 0 , SSy + SSSize , 800 , 600 , DEF_TEXARG0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 1 );

    if( Advance ){
      SSx += SSvx;
      SSy += SSvy;
    }
  }
}

void Effects::EnforcedStats( ){
  if( IsPulsingHud ){
    static float TimedDelay = 0.07f;
    static float TimeLast = FunCry::TimeNow - ( TimedDelay * 2.0f );

    if( FunCry::TimeNow - TimeLast >= TimedDelay ){
      TimeLast = TimeNow;
      static bool PulseUp = true;
      if( PulsingHudMultiplier > 2 ){
        PulseUp = false;
      }
      else if( PulsingHudMultiplier < 0 ){
        PulseUp = true;
      }
      PulseUp ? PulsingHudMultiplier += 0.1f : PulsingHudMultiplier -= 0.1f;
    }
  }

  if( IsZeroStamina ){
    if( Carver && Carver->IsAlive( ) ){
      Carver->m_stats.stamina = 0;
    }
  }
  else if( IsInfiniteStamina ){
    if( Carver && Carver->IsAlive( ) ){
      Carver->m_stats.stamina = 100;
    }
  }

  if( IsInfiniteHealth ){
    if( Carver && Carver->IsAlive( ) ){
      Carver->m_stats.health = Carver->m_stats.maxHealth;
    }
  }

  if( IsInfiniteArmor ){
    if( Carver && Carver->IsAlive( ) ){
      Carver->m_stats.armor = Carver->m_stats.maxArmor;
    }
  }

}
