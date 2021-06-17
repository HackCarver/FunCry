/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "FunCry.h"
#include "Effect.h"
#include "Color.h"
using namespace FunCry;
using namespace Effects;

#include "Logging.h"

static float DurationTimeOverride = 0.0f;
float FunCry::TimeNow = 0;
float FunCry::TimeRareStarted = 0;
static float TimeDelayRare = 60.0f;
unsigned int FunCry::LastVeryRareIdentifier = 0;
char FunCry::LastLevelName[ 256 ];

static bool FirstCall = true;
static bool LastCutscene = false;
static bool LastGameplay = false;
static bool LastLoading = false;
static bool LastPaused = false;

static unsigned int EffectActiveCount = 1;       /// amount of items that will be IN the active list
static unsigned int EffectPendingCount = 8;      /// amount of items that will be IN the pending list
static unsigned int EffectPendingShownCount = 0; /// amount of items in the pending list that will be SHOWN
static std::vector<Effect> EffectList;
static std::vector<Effect> EffectActive;
static std::vector<Effect> EffectPending;
static bool EffectListValidate( );

std::vector<GamePos> Effects::SpawnSpot_Training;
std::vector<GamePos> Effects::SpawnSpot_Carrier;
std::vector<GamePos> Effects::SpawnSpot_Fort;
std::vector<GamePos> Effects::SpawnSpot_Pier;
std::vector<GamePos> Effects::SpawnSpot_Research;
std::vector<GamePos> Effects::SpawnSpot_Treehouse;
std::vector<GamePos> Effects::SpawnSpot_Bunker;
std::vector<GamePos> Effects::SpawnSpot_Steam;
std::vector<GamePos> Effects::SpawnSpot_Regulator;
std::vector<GamePos> Effects::SpawnSpot_Control;
std::vector<GamePos> Effects::SpawnSpot_Rebellion;
std::vector<GamePos> Effects::SpawnSpot_Archive;
std::vector<GamePos> Effects::SpawnSpot_Cooler;
std::vector<GamePos> Effects::SpawnSpot_Boat;
std::vector<GamePos> Effects::SpawnSpot_Catacombs;
std::vector<GamePos> Effects::SpawnSpot_River;
std::vector<GamePos> Effects::SpawnSpot_Swamp;
std::vector<GamePos> Effects::SpawnSpot_Factory;
std::vector<GamePos> Effects::SpawnSpot_Dam;
std::vector<GamePos> Effects::SpawnSpot_Volcano;

std::vector<char *> Effects::Skybox_Shader;

bool Effects::WidescreenEnabled          = true;
int Effects::BlackOpsCrosshair           = -1;
float Effects::ScaleW_Temp               = 0;
bool Effects::SimpleFilterActive         = false;
unsigned int Effects::SimpleFilterCode   = 0;
bool Effects::SizeMatters                = false;
bool Effects::CIAWork                    = false;
bool Effects::IsScreenSaver              = false;
bool Effects::IsAltHud                   = false;
bool Effects::IsFunkyHud                 = false;
bool Effects::IsFunkyWeapon              = false;
bool Effects::IsInfiniteHealth           = false;
bool Effects::IsInfiniteArmor            = false;
bool Effects::IsInfiniteStamina          = false;
bool Effects::IsZeroStamina              = false;
bool Effects::IsDrunk                    = false;
bool Effects::IsMatrixV2                 = false;
bool Effects::IsCyberCry                 = false;
bool Effects::IsPulsingHud               = false;
float Effects::PulsingHudMultiplier      = 1.0f;
bool Effects::IsValVoice                 = false;
bool Effects::IsConversationRandomizer   = false;
bool Effects::IsLanguagesRandomizer      = false;
/// bool Effects::IsPainfulWeapon            = false;
bool Effects::IsInGameCutSceneRandomizer = false;
bool Effects::IsAICharacterRandomizer    = false;
bool Effects::IsAIWeaponRandomizer       = false;
bool Effects::IsAIWeaponDropOriginal     = false;

unsigned int Effects::VideoPlayEffect;

static bool FUNCRY_ALT_DISPLAY = false;
static bool FUNCRY_NO_DISPLAY  = false;

bool FunCry::IsCustomExperiment = false;

#ifdef FUNCRY_MANUAL_MODE
  static unsigned int DebugSlotPos = 53;
  static bool DebugSlotDisplay = true;
#endif

#include <sstream>

void FunCry::StartupEffects( ){
  FunLog::Log( FUNLOG_BASIC , "StartupEffects( )" );

  /* Config file | Start */
  string TPref = ReadCfg( "DurationTimeOverride" );
  if( TPref != "" ){
    int TInt = atoi( TPref.c_str( ) );
    if( TInt >= 0 ){
      DurationTimeOverride = (float)TInt;
    }
  }

  TPref = ReadCfg( "TimeDelayRare" );
  if( TPref != "" ){
    int TInt = atoi( TPref.c_str( ) );
    if( TInt >= 0 ){
      TimeDelayRare = (float)TInt;
    }
  }

  TPref = ReadCfg( "EffectActiveCount" );
  if( TPref != "" ){
    int TInt = atoi( TPref.c_str( ) );
    if( TInt >= 1 ){
      EffectActiveCount = (float)TInt;
    }
  }

  TPref = ReadCfg( "EffectPendingCount" );
  if( TPref != "" ){
    int TInt = atoi( TPref.c_str( ) );
    if( TInt >= 0 ){
      EffectPendingCount = (float)TInt;
    }
  }

  TPref = ReadCfg( "EffectPendingShownCount" );
  if( TPref != "" ){
    int TInt = atoi( TPref.c_str( ) );
    if( TInt >= 0 ){
      EffectPendingShownCount = (float)TInt;
    }
  }

  if( EffectPendingShownCount > EffectPendingCount ){
    EffectPendingShownCount = EffectPendingCount;
  }

  if( stricmp( ReadCfg( "AltDisplay" ).c_str( ) , "true" ) == 0 ){
    FUNCRY_ALT_DISPLAY = true;
  }

  if( stricmp( ReadCfg( "NoInterface" ).c_str( ) , "true" ) == 0 ){
    FUNCRY_NO_DISPLAY = true;
  }

  if( stricmp( ReadCfg( "ConversationRandomizer" ).c_str( ) , "true" ) == 0 ){
    IsConversationRandomizer = true;
  }

  if( stricmp( ReadCfg( "LanguagesRandomizer" ).c_str( ) , "true" ) == 0 ){
    IsLanguagesRandomizer = true;
  }

  if( stricmp( ReadCfg( "CutSceneInGameEffects" ).c_str( ) , "true" ) == 0 ){
    IsInGameCutSceneRandomizer = true;
  }

  if( stricmp( ReadCfg( "AICharacterRandomizer" ).c_str( ) , "true" ) == 0 ){
    IsAICharacterRandomizer = true;
  }

  if( stricmp( ReadCfg( "AIWeaponRandomizer" ).c_str( ) , "true" ) == 0 ){
    IsAIWeaponRandomizer = true;
  }

  if( stricmp( ReadCfg( "AIWeaponDropOriginal" ).c_str( ) , "true" ) == 0 ){
    IsAIWeaponDropOriginal = true;
  }

  /* Config file | End */

  if( FUNCRY_ALT_DISPLAY ){
    EffectPendingShownCount = 0;
  }

  for( unsigned int j = 0; j < EffectActiveCount; j++ ){
    EffectActive.reserve( j + 1 );
    EffectActive.push_back( Effect( ) );
  }

  for( unsigned int j = 0; j < EffectPendingCount; j++ ){
    EffectPending.reserve( j + 1 );
    EffectPending.push_back( Effect( ) );
  }

  strcpy( LastLevelName , "NoLevel" );

  unsigned int i = 0;
  /**                                                           title                   ID     enabled  pause  resume   time  time fixed rare  very rare **/
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Shady business"          , 526824 , true  , true  , true  , 5.0f   , true  , false , false ) ); /* 0  */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Life is colorful"        , 241947 , false , false , true  , 31.3f  , false , false , false ) ); /* 1  */ // This was/is a crash issue. Crashes later, when trying to load next level
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Zoom zoom"               , 123456 , true  , false , true  , 12.6f  , false , false , false ) ); /* 2  */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "On the move..."          , 387247 , true  , false , false , 22.7f  , false , true  , true  ) ); /* 3  */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "What Hud?"               , 184542 , true  , true  , true  , 21.33f , false , true  , false ) ); /* 4  */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Is it really real?"      , 924814 , false , true  , true  , 32.0f  , false , true  , true  ) ); /* 5  */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Where you going?"        , 341034 , true  , false , true  , 6.0f   , false , false , false ) ); /* 6  */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Laggy cuteness"          , 441904 , true  , true  , true  , 16.0f  , false , true  , true  ) ); /* 7  */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Floaters"                , 239823 , true  , true  , true  , 43.2f  , false , false , false ) ); /* 8  */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Mercs n boxes"           , 264982 , true  , true  , true  , 22.0f  , false , false , false ) ); /* 9  */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Ghosts with guns"        , 158294 , true  , true  , true  , 26.6f  , false , false , false ) ); /* 10 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Lag over 9000"           , 632673 , true  , true  , true  , 11.2f  , true  , true  , false ) ); /* 11 */ // Need a way to stop this from running beside certain other speed or lag effects
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Wires and stuff"         , 825115 , true  , true  , true  , 62.2f  , false , true  , true  ) ); /* 12 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Hurry up Jack!"          , 002742 , true  , true  , true  , 12.5f  , true  , true  , false ) ); /* 13 */ // Need a (decent) way to stop this from running beside certain other speed or lag effects
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Why so fast?"            , 782452 , true  , true  , true  , 15.7f  , true  , true  , false ) ); /* 14 */ // Need a (decent) way to stop this from running beside certain other speed or lag effects
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Full health!"            , 928374 , true  , false , false , 10.0f  , false , true  , false ) ); /* 15 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Full armor!"             , 656834 , true  , false , false , 10.1f  , false , true  , false ) ); /* 16 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Full stamina"            , 812093 , true  , false , false , 10.2f  , false , false , false ) ); /* 17 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Random health and armor" , 426374 , true  , false , false , 15.3f  , false , true  , false ) ); /* 18 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Last 20 rounds"          , 837643 , true  , false , false , 10.4f  , false , true  , true  ) ); /* 19 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Full ammo!"              , 365653 , true  , false , false , 10.5f  , false , true  , true  ) ); /* 20 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Remove all weapons"      , 894254 , false , false , false , 10.6f  , false , true  , true  ) ); /* 21 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Screensaver"             , 244310 , true  , true  , true  , 16.1f  , false , true  , true  ) ); /* 22 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Negativity"              , 656564 , true  , true  , true  , 21.2f  , false , true  , false ) ); /* 23 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Black Ops"               , 343221 , true  , true  , true  , 100.1f , false , true  , false ) ); /* 24 */ // Does not show all mercs under all circumstances
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Frozen!"                 , 224546 , true  , true  , true  , 20.3f  , false , true  , false ) ); /* 25 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Faded Hud"               , 221111 , true  , true  , true  , 25.5f  , false , false , false ) ); /* 26 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Size matters"            , 832984 , true  , true  , true  , 40.3f  , false , true  , false ) ); /* 27 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Who needs widescreen?"   , 775643 , true  , true  , true  , 18.4f  , false , true  , false ) ); /* 28 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Alternative Hud"         , 172634 , true  , true  , true  , 25.2f  , false , false , false ) ); /* 29 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Funky Hud"               , 765354 , true  , true  , true  , 25.1f  , false , true  , false ) ); /* 30 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Funky Weapon"            , 774423 , true  , true  , true  , 27.55f , false , true  , true  ) ); /* 31 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Healthy life"            , 783332 , true  , true  , true  , 22.1f  , false , true  , true  ) ); /* 32 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Custom"                  , 424234 , false , false , true  , 40.6f  , false , true  , true  ) ); /* 33 */ // FOR CUSTOM EXPERIMENTS
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Ghost town"              , 692114 , true  , true  , true  , 40.6f  , false , true  , true  ) ); /* 34 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Jitter"                  , 986689 , true  , true  , true  , 60.1f  , false , true  , false ) ); /* 35 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Boxes"                   , 457633 , true  , true  , true  , 50.8f  , false , true  , false ) ); /* 36 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Blurry terrain"          , 111344 , true  , true  , true  , 50.5f  , false , true  , false ) ); /* 37 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "What terrain?"           , 555343 , true  , true  , true  , 50.2f  , false , true  , true  ) ); /* 38 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Matrix"                  , 999552 , true  , true  , true  , 50.9f  , false , true  , false ) ); /* 39 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Tomato"                  , 321333 , true  , true  , true  , 30.6f  , false , true  , false ) ); /* 40 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Agent Orange"            , 555232 , true  , true  , true  , 30.6f  , false , true  , false ) ); /* 41 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Big jump"                , 213123 , true  , true  , true  , 30.6f  , false , false , false ) ); /* 42 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Hangover"                , 112222 , true  , false , true  , 15.8f  , false , true  , true  ) ); /* 43 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Speedy crouch"           , 442457 , true  , true  , true  , 20.2f  , false , true  , false ) ); /* 44 */ /* Must be paused .. and resumed both, or the effect becomes permanent */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Speedy prone"            , 842435 , true  , true  , true  , 20.3f  , false , true  , false ) ); /* 45 */ /* Must be paused .. and resumed both, or the effect becomes permanent */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "In the matrix"           , 455746 , true  , true  , true  , 35.7f  , false , true  , false ) ); /* 46 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Futuristic"              , 985949 , true  , true  , true  , 139.7f , false , true  , false ) ); /* 47 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Nothing"                 , 633212 , true  , false , false , 41.22f , false , false , false ) ); /* 48 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Remove armor"            , 887678 , true  , false , false , 25.12f , false , true  , false ) ); /* 49 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Out of breath"           , 634332 , true  , false , false , 25.12f , false , true  , false ) ); /* 50 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Infinite armor"          , 234442 , true  , false , false , 30.0f  , false , true  , true  ) ); /* 51 */
  EffectList.reserve( ++i ); EffectList.push_back( Effect( "Pulse"                   , 435647 , true  , false , false , 40.44f , false , false , false ) ); /* 52 */

  if( FancySoundCapability ){
    /**                                                           title                   ID     enabled  pause  resume   time  time fixed rare  very rare **/
    EffectList.reserve( ++i ); EffectList.push_back( Effect( "Is that you, Val?"       , 534543 , true  , false , false , 40.0f , false , true  , false ) ); /* 53 */
    /// EffectList.reserve( ++i ); EffectList.push_back( Effect( "Guns have feelings"      , 444333 , true  , false , false , 15.0f , false , false , false ) ); /* 54 */
    
  }
  if( FancyCharacterObjectCapability ){
    /**                                                           title                   ID     enabled  pause  resume   time  time fixed rare  very rare **/
    
  }

  for( unsigned int j = 0; j < EffectList.size( ); j++ ){
    for( unsigned int k = 0; k < EffectList.size( ); k++ ){
      if(
        j != k
        &&
        EffectList[ j ].Identifier == EffectList[ k ].Identifier
      ){
        FunLog::Log( FUNLOG_PROBLEM , "Effect list has duplicate ID" );
        ASSERT( false );
        break;
      }
    }
  }

  #ifdef FUNCRY_MANUAL_MODE
    if( DebugSlotPos < 0 ){
      DebugSlotPos = 0;
    }
    else if( DebugSlotPos >= EffectList.size( ) ){
      DebugSlotPos = EffectList.size( ) - 1;
    }
  #endif

  std::ostringstream Stream;
  for( unsigned int j = 0; j < EffectList.size( ); j++ ){
    Stream.str( "" );
    Stream << "Effect_";
    Stream << EffectList[ j ].Identifier;
    if( stricmp( ReadCfg( Stream.str( ) ).c_str( ) , "false" ) == 0 ){
      EffectList[ j ].IsEnabled = false;
      FunLog::Log( FUNLOG_ALWAYS , ( "Disabled [ " + EffectList[ j ].Title + " ]" ).c_str( ) );
    }
  }

  i = 0;
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "01_Training" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "02_Carrier" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "03_Fort" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "04_Research" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "05_Bunker" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "06_Steam" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "07_Regulator" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "08_Control" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "09_Archive" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "10_Boat" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "11_Temple" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "12_Mutant" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "13_Dam" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "14_Lab" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "15_Swamp" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "16_Treehouse" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "17_MP_Dune" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "18_Pier" );
  //Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "18_Pier_HDR" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "SkyExample_MovingCloudLayers" );
  Skybox_Shader.reserve( ++i ); Skybox_Shader.push_back( "SkyExample_BlinkingStars" );

  i = 0;
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 286.037f , 1038.66f , 24.5024f , 0.449542f , 0 , 181.781f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 213.255f , 636.043f , 25.7445f , -5.85065f , 0 , 275.153f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 557.028f , 802.157f , 51.5167f , 19.3492f , 0 , 470.902f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 785.396f , 1037.2f , 78.1684f , 13.9492f , 0 , 649.78f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 913.16f , 944.965f , 98.6376f , 15.5246f , 0 , 443.447f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 1278.26f , 938.756f , 29.5451f , 7.19956f , 0 , 123.045f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 1047.84f , 650.513f , 40.5775f , 6.52329f , 0 , 293.598f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 903.822f , 723.813f , 67.615f , -79.5999f , 0 , 317.451f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 445.823f , 585.576f , 17.2813f , 3.42721f , 0 , -317.5f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 503.901f , 869.637f , 9.51413f , -10.2161f , -5.72938f , -239.875f ) );
  SpawnSpot_Training.reserve( ++i ); SpawnSpot_Training.push_back( GamePos( 99.6965f , 1615.43f , 15.302f , -18.938f , 0 , -192.18f ) );

  i = 0;
  SpawnSpot_Carrier.reserve( ++i ); SpawnSpot_Carrier.push_back( GamePos( 1199.78f , 918.395f , 26.6242f , 30.1699f , 0 , -497.102f ) );
  SpawnSpot_Carrier.reserve( ++i ); SpawnSpot_Carrier.push_back( GamePos( 1227.35f , 919.771f , 15.1f , 13.6406f , 0 , 180.6f ) );
  SpawnSpot_Carrier.reserve( ++i ); SpawnSpot_Carrier.push_back( GamePos( 1226.71f , 931.025f , 19.151f , 77.2026f , 0 , 91.1977f ) );
  SpawnSpot_Carrier.reserve( ++i ); SpawnSpot_Carrier.push_back( GamePos( 1240.67f , 923.587f , 31.1f , 16.3753f , 0 , 269.613f ) );
  SpawnSpot_Carrier.reserve( ++i ); SpawnSpot_Carrier.push_back( GamePos( 1153.39f , 919.599f , 24.84f , 11.649f , 0 , 449.163f ) );
  SpawnSpot_Carrier.reserve( ++i ); SpawnSpot_Carrier.push_back( GamePos( 1244.31f , 902.094f , 46.0623f , 5.57407f , 0 , 629.167f ) );
  SpawnSpot_Carrier.reserve( ++i ); SpawnSpot_Carrier.push_back( GamePos( 1286.07f , 941.9f , 36.5278f , 28.5253f , 0 , 627.366f ) );
  SpawnSpot_Carrier.reserve( ++i ); SpawnSpot_Carrier.push_back( GamePos( 1259.9f , 938.394f , 16.2632f , 1.97471f , 0 , 481.569f ) );

  i = 0;
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 49.7978f , 1157.23f , 17.3017f , 5.21671f , 0 , 38.9759f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 346.591f , 798.357f , 15.4285f , -13.558f , 0 , 7.47593f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 384.038f , 626.511f , 16.9141f , 3.78979f , 0 , 108.824f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 586.108f , 832.954f , 55.1284f , -16.8491f , 0 , 633.975f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 752.721f , 992.473f , 81.2f , 3.91588f , 0 , 449.067f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 753.061f , 980.244f , 122.521f , 4.10031f , 0 , -499.533f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 716.001f , 1046.81f , 122.763f , -5.79675f , 0 , -1077.63f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 710.011f , 1094.75f , 122.757f , 2.90294f , 0 , -1438.83f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 598.208f , 1035.76f , 59.1632f , -6.64667f , 0 , -1033.88f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 701.693f , 846.312f , 27.7789f , -15.491f , 0 , -1595.57f ) );
  SpawnSpot_Fort.reserve( ++i ); SpawnSpot_Fort.push_back( GamePos( 516.294f , 998.69f , 60.4144f , 17.3865f , 0 , -2219.76f ) );

  i = 0;
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 799.906f , 1130.84f , 131.838f , 15.5732f , 0 , 119.56f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1602.43f , 1154.33f , 23.3141f , -2.79126f , 0 , -122.488f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1542.08f , 1129.6f , 27.259f , 38.6096f , 0 , 176.913f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1546.86f , 581.355f , 18.8215f , 4.4685f , 0 , -620.926f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1605.82f , 142.458f , 19.5313f , 10.1017f , 0 , -920.787f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1838.34f , 285.857f , 63.8636f , -2.76175f , 0 , -879.731f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1724.38f , 610.416f , 31.0037f , 0.313723f , 0 , -875.229f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1487.82f , 1004.28f , 41.7156f , 13.7641f , 0 , -993.405f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1502.92f , 1158.42f , 35.0171f , 7.36602f , 0 , -1033.52f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1358.53f , 1257.71f , 38.1581f , -6.38342f , 0 , -1091.19f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 906.627f , 1103.7f , 28.6132f , -8.1998f , 0 , -1310.78f ) );
  SpawnSpot_Pier.reserve( ++i ); SpawnSpot_Pier.push_back( GamePos( 1137.57f , 1170.47f , 36.9176f , 19.7016f , 0 , -1134.06f ) );

  i = 0;
  SpawnSpot_Research.reserve( ++i ); SpawnSpot_Research.push_back( GamePos( 1518.74f , 1031.83f , 16.5321f , 0 , 0 , -119.87f ) );
  SpawnSpot_Research.reserve( ++i ); SpawnSpot_Research.push_back( GamePos( 1674.68f , 1121.69f , 24.3172f , 38.0998f , 0 , -247.066f ) );
  SpawnSpot_Research.reserve( ++i ); SpawnSpot_Research.push_back( GamePos( 1451.99f , 1240.16f , 24.4092f , 10.202f , 0 , -702.141f ) );
  SpawnSpot_Research.reserve( ++i ); SpawnSpot_Research.push_back( GamePos( 1429.16f , 1292.7f , 17.7921f , -15.4467f , -5.67497f , -988.941f ) );
  SpawnSpot_Research.reserve( ++i ); SpawnSpot_Research.push_back( GamePos( 1434.49f , 1364.39f , 38.4511f , 35.1443f , 0 , -1797.47f ) );
  SpawnSpot_Research.reserve( ++i ); SpawnSpot_Research.push_back( GamePos( 1451.08f , 1348.08f , 33.375f , 11.4452f , 0 , -1948.1f ) );
  SpawnSpot_Research.reserve( ++i ); SpawnSpot_Research.push_back( GamePos( 1423.84f , 1345.77f , 26.8863f , 1.2452f , 0 , -1621.69f ) );
  SpawnSpot_Research.reserve( ++i ); SpawnSpot_Research.push_back( GamePos( 1446.8f , 1362.45f , 50.6f , -1.30313f , 0 , -1442.56f ) );

  i = 0;
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1421.38f , 1391.05f , 52.4875f , 28.3754f , 0 , 91.2005f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1515.53f , 1449.28f , 49.2539f , 3.68479f , 0 , 634.842f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1373.51f , 1496.12f , 58.0754f , -9.01971f , 0 , 806.673f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1267.93f , 1294.36f , 59.3585f , 11.6354f , 0 , -181.8f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1311.52f , 1382.4f , 36.5521f , -0.811646f , 0 , 44.1062f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1200.25f , 1532.77f , 88.7467f , 11.1888f , 0 , -90.5944f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1040.47f , 1536.11f , 90.79f , 5.5818f , 0 , -93.0144f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1116 , 1613.23f , 46.4754f , -5.59991f , 0 , -50.7135f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 975.502f , 1458.99f , 61.437f , 0.700073f , 0 , -446.273f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 959.951f , 1384.87f , 83.382f , 10.6f , 0 , -207.176f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1051.19f , 1407.9f , 84 , 18.7955f , 0 , -207.688f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 951.22f , 1536.51f , 99.1985f , 9.79566f , 0 , 74.0118f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 982.342f , 1562.64f , 79.0627f , 18.1001f , 0 , -319.288f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1058.8f , 1506.45f , 57.75f , 4.05173f , 0 , -453.577f ) );
  SpawnSpot_Treehouse.reserve( ++i ); SpawnSpot_Treehouse.push_back( GamePos( 1066.42f , 1414.37f , 73.6837f , -23.8003f , 0 , -547.779f ) );

  i = 0;
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1171.79f , 1398.06f , 74.5f , 7.19999f , 0 , -180 ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1158.43f , 1381.6f , 54 , 19.8f , 0 , -871.493f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1160.61f , 1364.77f , 43.5f , 21.9003f , 0 , -394.21f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1154.42f , 1334.46f , 40 , 15.0004f , 0 , -1207.5f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1149.35f , 1314.58f , 44.1529f , 22.1255f , 0 , -1312.66f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1194.59f , 1308.83f , 38 , 6.82586f , 0 , -1172.55f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1154.11f , 1303.09f , 37 , -1.27408f , 0 , -1351.65f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1145.98f , 1318.54f , 35.1153f , -7.27307f , 0 , -1342.34f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1134.34f , 1312.07f , 33 , 25.4283f , 0 , -2253.48f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1102.69f , 1299.18f , 36 , 28.7283f , 0 , -2429.59f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1084.3f , 1297.45f , 36.7746f , 2.29992f , 0 , -1890.47f ) );
  SpawnSpot_Bunker.reserve( ++i ); SpawnSpot_Bunker.push_back( GamePos( 1087.89f , 1282.82f , 42.7f , 2.30115f , 0 , -2113.07f ) );

  i = 0;
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1413.81f , 1180.05f , 57.4665f , 6.91227f , 0 , 2.2317f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1472.39f , 883.641f , 64.9859f , -6.87787f , 0 , 124.88f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1551.32f , 808.409f , 64.6931f , 4.42046f , 0 , 47.0009f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1621.98f , 795.106f , 62.0261f , 14.6205f , 0 , 32.001f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1702.77f , 764.207f , 66.6127f , 3.52056f , 0 , -4.29833f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1636.05f , 547.323f , 69.9505f , 0.821387f , 0 , -275.797f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1526.87f , 433.154f , 65.5849f , 0.520715f , 0 , -573.091f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1425.77f , 749.919f , 128.029f , 26.5009f , 0 , -1119.38f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1527.15f , 722.377f , 53.4063f , 5.80105f , 0 , -1356.41f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1639.83f , 773.611f , 53.0298f , 5.4004f , 0 , -1139.75f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1638.45f , 738.692f , 44.875f , 7.53256f , 0 , -1261.45f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1709.38f , 649.357f , 53.1463f , 9.70071f , 0 , -853.753f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1297.07f , 627.228f , 75.0905f , 22.0013f , 0 , -870.86f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1248.71f , 814.7f , 52.836f , -13.9964f , 0 , -995.356f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1248.09f , 1015.78f , 59.5497f , 6.29262f , 0 , -1395 ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1063.44f , 714.032f , 42.7269f , -4.50751f , 0 , -1313.56f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1278.99f , 831.009f , 55.7814f , 23.0753f , 0 , -1735.34f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1363.88f , 795.479f , 61.125f , 8.36366f , 0 , -1904.5f ) );
  SpawnSpot_Steam.reserve( ++i ); SpawnSpot_Steam.push_back( GamePos( 1255.3f , 549.868f , 47.5537f , 3.86359f , 0 , -2052.11f ) );

  i = 0;
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1521 , 821.675f , 35.5375f , 5.62499f , 0 , -2.70174f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1510.84f , 674.499f , 45.2826f , 3.40245f , 0 , -634.357f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1476.51f , 728.845f , 33.4297f , -2.59744f , 0 , -329.555f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1766.98f , 541.739f , 50.8957f , 6.70255f , 0 , -539.254f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1719.94f , 588.482f , 47.1328f , 13.0026f , 0 , -629.253f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1699.54f , 691.431f , 38.6125f , 5.50295f , 0 , -812.553f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1682.2f , 777.713f , 50.3167f , 8.21227f , 0 , -412.277f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1658.34f , 866.669f , 43.107f , 0.412439f , 0 , 2.62372f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1592.1f , 680.528f , 16.647f , -7.08618f , 3.771f , 98.9238f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1818.46f , 660.453f , 53.1378f , 12.6721f , 0 , -499.276f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1970.71f , 774.818f , 67.9001f , -16.4266f , 0 , -750.364f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1856.07f , 664.714f , 49.4998f , 6.99996f , 0 , -1531.21f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1885.19f , 670.057f , 41.5f , 15.3999f , 0 , -1980.01f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1866.57f , 655.583f , 49.3998f , 17.8f , 0 , -2071.82f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1898.35f , 676.248f , 44 , 1.60018f , 0 , -2340.61f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1899.02f , 772.925f , 56.075f , -3.33157f , 0 , -2522.04f ) );
  SpawnSpot_Regulator.reserve( ++i ); SpawnSpot_Regulator.push_back( GamePos( 1917.52f , 726.898f , 62.075f , 2.46888f , 0 , -2610.24f ) );

  i = 0;
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 845.938f , 561.25f , 134.75f , 0 , 0 , -90.0001f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 856.723f , 635.304f , 127.375f , 3.88914f , 0 , -630.322f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 818.547f , 651.129f , 130.5f , 4.3974f , 0 , -1440.35f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 847.444f , 628.236f , 142.125f , -1.59897f , 0 , -1529.72f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 849.327f , 656.605f , 131.5f , 15.1791f , 0 , -2035.04f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 867.232f , 713.659f , 113.75f , 11.9469f , 0 , -2228.42f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 893.419f , 668.075f , 115 , 20.947f , 0 , -2697.05f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 852.666f , 691.041f , 120 , 3.84757f , 0 , -2521.84f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 955.147f , 621.052f , 117.125f , 19.4476f , 0 , -2611.24f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 957.334f , 656.965f , 117.125f , 10.7476f , 0 , -2742.94f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 948.294f , 671.332f , 117.125f , 13.1476f , 0 , -2880.33f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 914.506f , 658.699f , 124.125f , 13.0965f , 0 , -3102.37f ) );
  SpawnSpot_Control.reserve( ++i ); SpawnSpot_Control.push_back( GamePos( 921.708f , 684.973f , 115.125f , 8.29647f , 0 , -3239.78f ) );

  i = 0;
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 918.12f , 662.714f , 115.125f , 8.99999f , 0 , 269.176f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 892.313f , 741.628f , 127.875f , 11.7006f , 0 , 91.8769f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 982.015f , 763.461f , 115.47f , -0.298218f , 0 , 88.8769f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1017.77f , 826.922f , 108.725f , 14.0069f , 0 , 218.944f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 942.881f , 864.838f , 148.306f , 14.0085f , 0 , 73.7429f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 848.971f , 1272.3f , 119.748f , 18.8086f , 0 , 269.043f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1236.95f , 1149.6f , 80.7905f , 11.3102f , 0 , 54.8436f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1540.53f , 809.039f , 65.9984f , -4.28882f , 0 , -141.056f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1587.31f , 981.304f , 78.8428f , 13.1117f , 0 , 25.4445f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1693.17f , 881.313f , 107.628f , 8.01177f , 0 , 181.146f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1900.59f , 805.581f , 135.041f , 8.29727f , 0 , 269.945f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1752.47f , 992.456f , 68.2938f , -6.08322f , 0 , 207.209f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1693.65f , 1316.65f , 67.3007f , -1.88348f , 0 , 478.409f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1602.23f , 1240.67f , 104.698f , 26.2991f , 0 , 630.506f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1556.39f , 1304.97f , 94.3773f , -0.799316f , 0 , 460.706f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1531.19f , 1381.05f , 108.415f , 4.30296f , 0 , 374.309f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1722.69f , 1122.03f , 147.156f , 16.9019f , 0 , -467.659f ) );
  SpawnSpot_Rebellion.reserve( ++i ); SpawnSpot_Rebellion.push_back( GamePos( 1685.68f , 1264.99f , 115.861f , 6.85739f , 0 , -470.472f ) );

  i = 0;
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 640.401f , 1034.67f , 131 , 40.3499f , 0 , -170.325f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 619.033f , 1029.09f , 131 , 5.82515f , 0 , -360.357f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 620.603f , 1005.81f , 136.313f , 35.9011f , 0 , -452.444f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 635.811f , 1005.8f , 123.362f , -12.8422f , -5.82854f , -623.442f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 594.249f , 985.044f , 131 , 18.6252f , 0 , -1040.24f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 545.833f , 1073.2f , 87 , 11.4254f , 0 , -1167.45f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 539.3f , 1116.73f , 93.615f , 7.52558f , 0 , -1033.04f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 568.529f , 1135.78f , 86.5496f , 25.2256f , 0 , -894.143f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 527.941f , 1072.25f , 67.5f , 2.72566f , 0 , -694.347f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 458.219f , 1069.41f , 68 , 4.22625f , 0 , -1171.95f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 454.838f , 977.171f , 81.2407f , 11.727f , 0 , -1348.35f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 529.061f , 1102.51f , 93.5f , 14.4272f , 0 , -777.144f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 366.513f , 1020.67f , 114.559f , 36.3272f , 0 , -1318.95f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 457.504f , 975.093f , 81.2407f , 1.82723f , 0 , -1247.85f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 346.345f , 1065.61f , 98 , 14.2343f , 0 , -1372.34f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 315.983f , 1013.03f , 89.3864f , 3.73435f , 0 , -1147.93f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 337.361f , 1006.15f , 99.5212f , 10.3353f , 0 , -900.134f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 317.776f , 1063.47f , 87.056f , 10.0353f , 0 , -900.432f ) );
  SpawnSpot_Archive.reserve( ++i ); SpawnSpot_Archive.push_back( GamePos( 331.655f , 1130.49f , 87 , 3.89206f , 0 , -629.975f ) );

  i = 0;
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 328.473f , 1116.98f , 70.875f , 6.22502f , 0 , -11.0998f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 300.467f , 1098.83f , 73.375f , 45.2257f , 0 , 446.099f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 303 , 1119.5f , 71 , 12.5257f , 0 , 269.701f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 297.309f , 1043.26f , 70 , 12.5257f , 0 , 268.801f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 308.049f , 1024.05f , 75.6233f , 58.8998f , 0 , -2.39874f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 325.952f , 1010.3f , 75.6952f , 9.10159f , 0 , 90.0031f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 372.394f , 1016.22f , 63 , 16.6016f , 0 , -319.798f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 336.955f , 983.319f , 71 , 11.5021f , 0 , -270.602f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 377.139f , 1023.82f , 71.375f , 8.50229f , 0 , -252.301f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 384.496f , 1053.55f , 69.8433f , -14.2971f , 0 , 88.8f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 364.003f , 1040.56f , 70.9471f , 2.20261f , 0 , -359.999f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 313.88f , 975.761f , 47 , 5.50274f , 0 , -270.599f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 333.369f , 1074.97f , 42.75f , 2.5028f , 0 , -89.0991f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 323.573f , 1013.47f , 34 , 26.8027f , 0 , 157.801f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 288.305f , 1047.05f , 60.625f , 4.60111f , 0 , 0.000188231f ) );
  SpawnSpot_Cooler.reserve( ++i ); SpawnSpot_Cooler.push_back( GamePos( 269.201f , 1074.47f , 60.125f , 2.14865f , 0 , 85.5215f ) );

  i = 0;
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 1498.23f , 1278.83f , 26.5434f , -2.04321f , 0 , 464.8f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 1604.05f , 1171.57f , 32.046f , 19.2568f , 0 , 319.3f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 1658.4f , 1098.52f , 24.3721f , 12.6569f , 0 , 225.1f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 1273.19f , 999.403f , 35.6571f , 18.9569f , 0 , 392.499f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 1255.47f , 1173.25f , 50.333f , 6.35726f , 0 , 448.599f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 1217.65f , 1299.4f , 35 , 24.3573f , 0 , 547.6f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 931.612f , 944.351f , 26.3461f , 20.7575f , 0 , 314.8f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 851.899f , 993.989f , 25.8852f , 8.75741f , 0 , 269.5f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 822.645f , 961.859f , 52.625f , 18.0596f , 0 , 572.501f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 553.276f , 944.163f , 76.418f , 11.4604f , 0 , 438.399f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 353.039f , 1116.75f , 61.9225f , 6.96049f , 0 , 467.199f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 389.184f , 1237.01f , 59.9238f , 19.2612f , 0 , -22.3997f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 573.103f , 1238.47f , 55.099f , 8.7614f , 0 , 437.802f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 466.985f , 805.791f , 23.5283f , -4.73828f , 0 , 609.099f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 701.514f , 655.536f , 25.2402f , 0.661688f , 0 , 776.201f ) );
  SpawnSpot_Boat.reserve( ++i ); SpawnSpot_Boat.push_back( GamePos( 610.546f , 712.288f , 62.6586f , 16.862f , 0 , 951.104f ) );

  i = 0;
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 934.019f , 575.561f , 87.1665f , 7.19999f , 0 , -177.6f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 883.374f , 603.174f , 83.2571f , 20.5621f , 0 , -222.74f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 1002.53f , 734.903f , 85.51f , -11.8575f , 0 , -385.977f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 1080.19f , 602.943f , 84.8949f , -2.69415f , 0 , -384.214f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 797.622f , 812.618f , 95.699f , 41.1074f , 0 , -1046.91f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 892.754f , 658.743f , 68.937f , 31.5073f , 0 , -1029.51f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 797.117f , 828.375f , 88.875f , 9.90762f , 0 , -903.217f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 806.475f , 896.66f , 71.5f , 32.2789f , 0 , -995.326f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 783.877f , 975.816f , 69 , 5.49632f , 0 , -1266.45f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 807.435f , 978.149f , 78.9086f , 59.1252f , 0 , -1528.04f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 806.881f , 987.761f , 79.375f , 22.8251f , 0 , -1755.22f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 833.415f , 970.229f , 75.2891f , 6.92656f , 0 , -1631.61f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 834.706f , 1049.91f , 83.0025f , 51.0263f , 0 , -1577.9f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 787.244f , 1019.38f , 74.13f , -25.3218f , 0 , -1441.71f ) );
  SpawnSpot_Catacombs.reserve( ++i ); SpawnSpot_Catacombs.push_back( GamePos( 792.019f , 1002.02f , 71.5f , 19.9334f , 0 , -1120.89f ) );

  i = 0;
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 283.38f , 421.979f , 66.375f , 0 , 0 , -180 ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 371.83f , 579.013f , 43.2785f , -2.99985f , 0 , -251.999f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 637.547f , 515.831f , 33.9288f , 14.4999f , 0 , -100.8f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 694.682f , 710.031f , 56.9474f , 21.1007f , 0 , -457.798f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 585.328f , 735.832f , 77.95f , 24.1007f , 0 , -680.998f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 746.054f , 976.763f , 27.9398f , 17.8011f , 0 , -590.394f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 1067.85f , 1005.52f , 41.6927f , 20.5007f , 0 , -438.293f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 1456.52f , 1079.24f , 38.6519f , 1.30115f , 0 , -869.382f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 1282.32f , 1155.85f , 52.343f , 13.6017f , 0 , 74.1001f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 1295.67f , 1393.66f , 27.7582f , 3.67551f , 0 , 71.0999f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 1753.72f , 1752.2f , 60.5518f , 11.1753f , 0 , 288.001f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 1852.05f , 1874.47f , 33.6758f , -3.52338f , 0 , 710.398f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 1890 , 1827.2f , 27.9257f , 5.47765f , 0 , 294.897f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 1623.44f , 1764.45f , 30.6097f , 10.8777f , 0 , 44.3964f ) );
  SpawnSpot_River.reserve( ++i ); SpawnSpot_River.push_back( GamePos( 1931.47f , 1508.46f , 31.2589f , -4.12253f , 0 , -136.804f ) );

  i = 0;
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1670.29f , 494.784f , 37.7813f , 0.0750067f , 0 , -119.95f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1869.27f , 532.052f , 24.75f , -7.12473f , 0 , -173.351f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1819.98f , 526.171f , 31.4264f , 0 , 0 , 0 ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1819.98f , 526.171f , 31.4264f , 0 , 0 , 0 ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1819.98f , 526.171f , 31.4264f , 0 , 0 , 0 ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 767.406f , 1005.05f , 32.25f , 19.8517f , 0 , 360.101f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 919.117f , 1076.37f , 24.5081f , 2.15168f , 0 , 241.597f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1089.37f , 898.474f , 25.9037f , -10.1475f , 0 , 513.096f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1370.85f , 938.264f , 32.2114f , -1.04169f , 0 , 757.35f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 691.398f , 1073.48f , 25.5326f , 0.457696f , 0 , 680.218f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 611.519f , 947.959f , 26.2383f , 0 , 0 , 0 ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1704.44f , 510.82f , 38.1962f , 0 , 0 , 136.996f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1705.77f , 511.6f , 38.1962f , 4.05f , 0 , 84.5711f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1705.77f , 511.6f , 38.1962f , 4.05f , 0 , 84.5711f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 1705.77f , 511.6f , 38.1962f , 4.05f , 0 , 84.5711f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 786.047f , 1002.76f , 37.5047f , 18.352f , 0 , 102.178f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 571.548f , 1089.15f , 31.875f , 1.0674f , 0 , 267.516f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 624.426f , 1064.96f , 32.7115f , 0.168591f , 0 , -92.7839f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 586.504f , 1090.4f , 30 , 9.46914f , 0 , -139.884f ) );
  SpawnSpot_Swamp.reserve( ++i ); SpawnSpot_Swamp.push_back( GamePos( 638.867f , 1131.13f , 32.4089f , 6.76907f , 0 , 193.718f ) );

  i = 0;
  SpawnSpot_Factory.reserve( ++i ); SpawnSpot_Factory.push_back( GamePos( 433.288f , 866.821f , 28.5233f , 7.04312f , 0 , -178.759f ) );
  SpawnSpot_Factory.reserve( ++i ); SpawnSpot_Factory.push_back( GamePos( 591.256f , 883.375f , 38 , 16.3431f , 0 , -201.856f ) );
  SpawnSpot_Factory.reserve( ++i ); SpawnSpot_Factory.push_back( GamePos( 602.179f , 848.275f , 21.375f , 7.84358f , 0 , -900.87f ) );
  SpawnSpot_Factory.reserve( ++i ); SpawnSpot_Factory.push_back( GamePos( 640.404f , 758.358f , 12 , 9.34365f , 0 , -1170.87f ) );
  SpawnSpot_Factory.reserve( ++i ); SpawnSpot_Factory.push_back( GamePos( 632.045f , 794.985f , 12 , 18.3436f , 0 , -1228.46f ) );
  SpawnSpot_Factory.reserve( ++i ); SpawnSpot_Factory.push_back( GamePos( 614.604f , 782.775f , 12 , 23.1f , 0 , 399.898f ) );
  SpawnSpot_Factory.reserve( ++i ); SpawnSpot_Factory.push_back( GamePos( 640.744f , 740.814f , 12 , 9.0666f , 0 , 604.258f ) );
  SpawnSpot_Factory.reserve( ++i ); SpawnSpot_Factory.push_back( GamePos( 614.049f , 734.678f , 12 , 8.76659f , 0 , 629.759f ) );
  SpawnSpot_Factory.reserve( ++i ); SpawnSpot_Factory.push_back( GamePos( 611.642f , 720.651f , 33 , 12.7999f , 0 , -491.634f ) );

  i = 0;
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 1331.59f , 757.234f , 87.6289f , 2.40022f , 0 , -161.46f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 1276.65f , 910.724f , 28.4839f , 9.30049f , 0 , -482.758f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 1194.34f , 843.802f , 33.0254f , 8.40171f , 0 , -902.453f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 1113.1f , 922.899f , 14.1741f , 12.0002f , 0 , 140.1f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 955.732f , 991.279f , 65.3703f , 21.8854f , 0 , 73.887f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 925.798f , 1019.33f , 50.3624f , -1.51447f , 0 , -134.912f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 961.454f , 1130.24f , 35.7226f , 15.885f , 0 , -192.512f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 760.273f , 1317.01f , 76.0989f , 16.1861f , 0 , 5.78893f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 704.211f , 1389.2f , 54.1569f , -4.39975f , 0 , -362.902f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 695.382f , 1329.78f , 89.4657f , 27.7011f , 0 , -571.096f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 1116.97f , 1253.83f , 88.589f , 10.9014f , 0 , -463.395f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 848.951f , 1464.02f , 18.2197f , 2.20163f , 0 , -513.197f ) );
  SpawnSpot_Dam.reserve( ++i ); SpawnSpot_Dam.push_back( GamePos( 946.432f , 1006.04f , 45.6124f , 29.8032f , 0 , -144.196f ) );

  i = 0;
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 706.478f , 1424.16f , 51 , 25.05f , 0 , 47.0005f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 596.144f , 1416.59f , 52.75f , 37.119f , 0 , -304.91f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 607.761f , 1412.09f , 57.025f , 35.0198f , 0 , -45.7098f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 564.458f , 1436.99f , 80.75f , 16.3973f , 0 , 313.388f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 575.888f , 1419.64f , 86.7f , 11.2993f , 0 , 360.19f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 572.395f , 1405.59f , 86.725f , 2.29966f , 0 , -142.009f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 536.197f , 1417.41f , 82.125f , 10.9002f , 0 , -181.61f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 473.409f , 1361.22f , 77.375f , 18.4005f , 0 , -178.309f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 414.852f , 1422.4f , 68.12f , 4.00038f , 0 , -270.709f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 473.409f , 1422.02f , 83.5113f , 25.603f , 0 , -495.704f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 462.22f , 1475.72f , 73.125f , 12.4037f , 0 , -756.709f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 406.35f , 1422.74f , 56.125f , 10.0036f , 0 , -661.915f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 458.205f , 1422.53f , 64.8699f , 16.9047f , 0 , -629.515f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 369.124f , 1422.73f , 91.25f , 6.03024f , 0 , -643.64f ) );
  SpawnSpot_Volcano.reserve( ++i ); SpawnSpot_Volcano.push_back( GamePos( 388.87f , 1413.19f , 97.2431f , 28.8999f , 0 , -608.992f ) );

  ITexPic *TPic = Rend->EF_LoadTexture( "Textures/lights/gk_spotlight_04.dds" , FT_NORESIZE , 0 , eTT_Base );
  if( TPic ){
    BlackOpsCrosshair = TPic->GetTextureID( );
  }

  VideoPlayEffect = rand( ) % 5;

  ICVar *TVar = GetISystem( )->GetIConsole( )->GetCVar( "e_flocks_hunt" );
  if( TVar ){
    TVar->Set( 1 );
  }
}

void FunCry::ShutdownEffects( ){
  FunLog::Log( FUNLOG_BASIC , "ShutdownEffects( )" );

  FunColor::StopColor( );

  for( unsigned int i = 0; i < EffectActive.size( ); i++ ){
    if( EffectList[ i ].IsActive ){
      Effects::Stop( &EffectList[ i ] , false );
    }
  }

  DurationTimeOverride           = NULL;
  FunCry::TimeNow                = NULL;
  FunCry::TimeRareStarted        = NULL;
  TimeDelayRare                  = NULL;
  FunCry::LastVeryRareIdentifier = NULL;

  FirstCall    = NULL;
  LastCutscene = NULL;
  LastGameplay = NULL;
  LastLoading  = NULL;
  LastPaused   = NULL;

  EffectActiveCount = NULL;
  EffectPendingCount = NULL;
  EffectPendingShownCount = NULL;
  EffectList.clear( );
  EffectActive.clear( );
  EffectPending.clear( );

  SpawnSpot_Training.clear( );
  SpawnSpot_Carrier.clear( );
  SpawnSpot_Fort.clear( );
  SpawnSpot_Pier.clear( );
  SpawnSpot_Research.clear( );
  SpawnSpot_Treehouse.clear( );
  SpawnSpot_Bunker.clear( );
  SpawnSpot_Steam.clear( );
  SpawnSpot_Regulator.clear( );
  SpawnSpot_Control.clear( );
  SpawnSpot_Rebellion.clear( );
  SpawnSpot_Archive.clear( );
  SpawnSpot_Cooler.clear( );
  SpawnSpot_Boat.clear( );
  SpawnSpot_Catacombs.clear( );
  SpawnSpot_River.clear( );
  SpawnSpot_Swamp.clear( );
  SpawnSpot_Factory.clear( );
  SpawnSpot_Dam.clear( );
  SpawnSpot_Volcano.clear( );

  Skybox_Shader.clear( );

  WidescreenEnabled          = NULL;
  BlackOpsCrosshair          = NULL;
  ScaleW_Temp                = NULL;
  SimpleFilterActive         = NULL;
  SimpleFilterCode           = NULL;
  SizeMatters                = NULL;
  CIAWork                    = NULL;
  IsScreenSaver              = NULL;
  IsAltHud                   = NULL;
  IsFunkyWeapon              = NULL;
  IsInfiniteHealth           = NULL;
  IsInfiniteStamina          = NULL;
  IsZeroStamina              = NULL;
  IsDrunk                    = NULL;
  IsMatrixV2                 = NULL;
  IsCyberCry                 = NULL;
  IsValVoice                 = NULL;
  IsConversationRandomizer   = NULL;
  IsInGameCutSceneRandomizer = NULL;
  IsAICharacterRandomizer    = NULL;
  IsAIWeaponRandomizer       = NULL;

  VideoPlayEffect = NULL;

  FUNCRY_ALT_DISPLAY = NULL;

  #ifdef FUNCRY_MANUAL_MODE
    DebugSlotPos = NULL;
    DebugSlotDisplay = NULL;
  #endif
}

void Effects::UpdateEffects( bool Cutscene , bool Gameplay , bool Loading , bool Paused ){
  FunLog::Log( FUNLOG_DETAIL , ( string( "UpdateEffects( " ) + ( Cutscene ? "cutscene" : "" ) + string( " , " ) + ( Gameplay ? "gameplay" : "" ) + string( " , " ) + ( Loading ? "loading" : "" ) + string( " , " ) + ( Paused ? "paused" : "" ) + string( " )" ) ).c_str( ) );

  TimeNow = Time->GetAsyncCurTime( );

  FunColor::UpdateColors( );

  #ifndef FUNCRY_DISABLE_AUTO
    if( !FirstCall ){
      if(
        ( !LastPaused && !LastLoading )
        &&
        ( Paused || Loading )
      ){
        PauseAll( );
      }
      if( Paused ){
        if( !LastPaused ){
          VideoPlayEffect = rand( ) % 5;
        }
      }
      else if( Loading ){

      }
      else{
        if( Game ){
          const char *Level = Game->GetLevelName( );
          if( Level ){
            if( stricmp( Level , LastLevelName ) != 0 ){
              SeedRand( );

              strcpy( LastLevelName , Level );
              if( Eng && Chance( 4 ) ){
                unsigned int Slot = rand( ) % ( Skybox_Shader.size( ) -1 );
                Eng->SetSkyBox( Skybox_Shader[ Slot ] );
              }
            }
          }
        }

        if( EffectListValidate( ) ){
          FunLog::Log( FUNLOG_DETAIL , "List is valid" );

          for( unsigned int i = 0; i < EffectActive.size( ); i++ ){
            if(
              EffectActive[ i ].IsPaused
              ||
              (
                !EffectActive[ i ].IsActive
                &&
                !EffectActive[ i ].IsStale
              )
            ){
              if( !Start( &EffectActive[ i ] ) ){
                EffectActive[ i ].IsStale = true;

                FunLog::Log( FUNLOG_BASIC , ( "Could not start: " + EffectActive[ i ].Title ).c_str( ) );
              }
            }
            else if(
              EffectActive[ i ].IsActive
              &&
              ( TimeNow - EffectActive[ i ].TimeStarted > EffectActive[ i ].TimeEffective )
            ){
              Stop( &EffectActive[ i ] );
            }
          }

        }
        else{
          FunLog::Log( FUNLOG_BASIC , "List is not valid" );
        }

        if( FUNCRY_ALT_DISPLAY ){
          DisplayAltList( );
        }
        else{
          DisplayList( );
        }
        EnforcedStats( );
        SimpleFilter( );
        Experiment( );
      }
    }
    else{
      FirstCall = false;
    }
  #endif

  #ifdef FUNCRY_MANUAL_MODE
    if(
      EffectActive[ 0 ].IsActive
      &&
      ( TimeNow - EffectActive[ 0 ].TimeStarted > EffectActive[ 0 ].TimeEffective )
    ){
      Stop( &EffectActive[ 0 ] );
    }

    if( DebugSlotDisplay ){
      char buffer[ 10 ];
      itoa( DebugSlotPos , buffer , 10 );
      FunText->Reset( );
      FunText->UseRealPixels( false );
      FunText->SetColor( color4f( 1 , 1 , 1 , 1.0f ) );
      FunText->SetSize( vector2f( 10.0f * ScaleW , 14.0f ) );

      FunText->DrawString( 300 , 10 , ( string( "SLOT [ " ) + buffer + string( " ] " ) + ( !EffectList[ DebugSlotPos ].IsEnabled ? "[ DISABLED ] " : "" ) + string( EffectList[ DebugSlotPos ].Title ) ).c_str( ) , false );
      FunText->DrawString( 300 , 20 , EffectList[ DebugSlotPos ].IsActive ? "ENABLED" : "DISABLED" , false );
    }

    EnforcedStats( );
    SimpleFilter( );
    Experiment( );
  #endif

  LastCutscene = Cutscene;
  LastGameplay = Gameplay;
  LastLoading  = Loading;
  LastPaused   = Paused;
}

void Effects::Copy( Effect *Src , Effect *Dest ){
  Dest->Title              = Src->Title;
  Dest->Identifier         = Src->Identifier;
  Dest->TimeEffective      = ( Src->TimeEffectiveFixed == false && DurationTimeOverride > 0 ) ? DurationTimeOverride : Src->TimeEffective;
  Dest->TimeEffectiveFixed = Src->TimeEffectiveFixed;
  Dest->TimeStarted        = Src->TimeStarted;
  Dest->TimeActive         = Src->TimeActive;
  Dest->IsActive           = Src->IsActive;
  Dest->IsEnabled          = Src->IsEnabled;
  Dest->IsPausable         = Src->IsPausable;
  Dest->IsPaused           = Src->IsPaused;
  Dest->IsResumable        = Src->IsResumable;
  Dest->IsStale            = false;
  Dest->IsRare             = Src->IsRare;
  Dest->IsVeryRare         = Src->IsVeryRare;

  Src->TimeStarted = 0;
  Src->TimeActive  = 0;
  Src->IsActive    = false;
  Src->IsPaused    = false;
  Src->IsStale     = true;
}

Effect *Effects::Find( std::vector<unsigned int> *Forbidden , float SinceLastRare ){
  FunLog::Log( FUNLOG_BASIC , "Find( )" );

  bool Duplicate = false;
  unsigned int Attempts = 0;
  unsigned int Sel;
  int Last = -1;

  while( Attempts++ <= 100 ){
    Sel = rand( ) % EffectList.size( );

    if(
      Sel != Last
      &&
      EffectList[ Sel ].IsEnabled
    ){
      Duplicate = false;
      for( unsigned int i = 0; i < Forbidden->size( ); i++ ){
        if( Forbidden->at( i ) == EffectList[ Sel ].Identifier ){
          Duplicate = true;
          break;
        }
      }

      if(
        !Duplicate
        &&
        ( ( EffectList[ Sel ].IsRare || EffectList[ Sel ].IsVeryRare ) ? ( SinceLastRare > TimeDelayRare ) : true )
        &&
        ( ( EffectList[ Sel ].IsRare && EffectList[ Sel ].IsVeryRare ) ? ( EffectList[ Sel ].Identifier != LastVeryRareIdentifier && ( TimeDelayRare != 0 ? Chance( 4 ) : true ) ) : true )
      ){
        FunLog::Log( FUNLOG_BASIC , ( "Find( ) | Found: \"" + EffectList[ Sel ].Title + "\"" ).c_str( ) );

        return &EffectList[ Sel ];
      }
    }

    Last = Sel;
  }

  FunLog::Log( FUNLOG_BASIC , "Find( ) | Could not find effect" );
  return NULL;
}

void Effects::Pause( Effect *Target ){
  if( Target->IsActive ){
    FunLog::Log( FUNLOG_BASIC , ( "Pausing [ " + Target->Title + " ]" ).c_str( ) );

    Stop( Target , true );
    Target->IsStale = false;
    Target->IsPaused = true;
    Target->TimeActive = TimeNow - Target->TimeStarted;
  }
}

void FunCry::PauseAll( ){
  #ifdef FUNCRY_DETAIL_LOG
    FunLog::Log( FUNLOG_DETAIL , "PauseAll( )" );
  #else
    FunLog::Log( FUNLOG_DEBUG , "-----------------" );
    FunLog::Log( FUNLOG_DEBUG , "PAUSE ALL EFFECTS" );
  #endif

  for( unsigned int i = 0; i < EffectActive.size( ); i++ ){
    Pause( &EffectActive[ i ] );
  }
}

static bool EffectListValidate( ){
  FunLog::Log( FUNLOG_DETAIL , "EffectListValidate( )" );

  std::vector<unsigned int> EffectInUse;
  float SinceLastRare = TimeRareStarted == 0 ? TimeNow : TimeRareStarted;
  bool result = true;

  /** get ID of all previously chosen effects **/
  /** get time since last rare effect **/
  for( unsigned int i = 0; i < EffectActive.size( ); i++ ){
    EffectInUse.reserve( EffectInUse.size( ) + 1 );
    EffectInUse.push_back( EffectActive[ i ].Identifier );

    if( !EffectActive[ i ].IsStale ){
      if(
        EffectActive[ i ].IsRare
        ||
        EffectActive[ i ].IsVeryRare
      ){
        SinceLastRare = EffectActive[ i ].IsActive ? ( TimeNow - EffectActive[ i ].TimeStarted ) : TimeNow;
      }
      else{
        SinceLastRare += EffectActive[ i ].IsActive ? ( EffectActive[ i ].TimeEffective - ( TimeNow - EffectActive[ i ].TimeStarted ) ) : EffectActive[ i ].TimeEffective;
      }
    }
  }
  for( unsigned int i = 0; i < EffectPending.size( ); i++ ){
    EffectInUse.reserve( EffectInUse.size( ) + 1 );
    EffectInUse.push_back( EffectPending[ i ].Identifier );

    if( !EffectPending[ i ].IsStale ){
      if(
        EffectPending[ i ].IsRare
        ||
        EffectPending[ i ].IsVeryRare
      ){
        SinceLastRare = TimeNow;
      }
      else{
        SinceLastRare += EffectPending[ i ].TimeEffective;
      }
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////

  // very sloppy hack to prevent time based things from messing with each other
  bool HandledLagOver9000 = false,
  HandledHurryUp = false,
  HandledWhySoFast = false;

  for( unsigned int i = 0; i < EffectInUse.size( ); i++ ){
    if( EffectInUse[ i ] == 632673 ){ /// Lag over 9000
      if( !HandledHurryUp ){
        EffectInUse.reserve( EffectInUse.size( ) + 1 );
        EffectInUse.push_back( 002742 ); /// Hurry up Jack!
        HandledHurryUp = true;
      }

      if( !HandledWhySoFast ){
        EffectInUse.reserve( EffectInUse.size( ) + 1 );
        EffectInUse.push_back( 782452 ); /// Why so fast?
        HandledWhySoFast = true;
      }
    }
    else if( EffectInUse[ i ] == 002742 ){ /// Hurry up Jack!
      if( !HandledLagOver9000 ){
        EffectInUse.reserve( EffectInUse.size( ) + 1 );
        EffectInUse.push_back( 632673 ); /// Lag over 9000
        HandledLagOver9000 = true;
      }

      if( !HandledWhySoFast ){
        EffectInUse.reserve( EffectInUse.size( ) + 1 );
        EffectInUse.push_back( 782452 ); /// Why so fast?
        HandledWhySoFast = true;
      }
    }
    else if( EffectInUse[ i ] == 782452 ){ /// Why so fast?
      if( !HandledLagOver9000 ){
        EffectInUse.reserve( EffectInUse.size( ) + 1 );
        EffectInUse.push_back( 632673 ); /// Lag over 9000
        HandledLagOver9000 = true;
      }
      
      if( !HandledHurryUp ){
        EffectInUse.reserve( EffectInUse.size( ) + 1 );
        EffectInUse.push_back( 002742 ); /// Hurry up Jack!
        HandledHurryUp = true;
      }
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////

  bool ok;
  for( unsigned int i = 0; i < EffectActive.size( ); i++ ){
    if( EffectActive[ i ].IsStale ){
      ok = false;

      for( unsigned int j = i + 1; j < EffectActive.size( ); j++ ){
        if(
          EffectActive[ j ].IsActive
          ||
          !EffectActive[ j ].IsStale
        ){
          Copy( &EffectActive[ j ] , &EffectActive[ i ] );
          ok = true;
          break;
        }
      }

      if( !ok ){
        for( unsigned int j = 0; j < EffectPending.size( ); j++ ){
          if( !EffectPending[ j ].IsStale ){
            Copy( &EffectPending[ j ] , &EffectActive[ i ] );
            ok = true;
            break;
          }
        }

        if( !ok ){
          Effect *TEffect = Find( &EffectInUse , SinceLastRare );
          if( TEffect != NULL ){
            Copy( TEffect , &EffectActive[ i ] );
            EffectInUse.reserve( EffectInUse.size( ) + 1 );
            EffectInUse.push_back( TEffect->Identifier );
            ok = true;
          }
        }
      }

      if( !ok ){
        result = false;
      }
    }
  }

  for( unsigned int i = 0; i < EffectPending.size( ); i++ ){
    if( EffectPending[ i ].IsStale ){
      ok = false;

      for( unsigned int j = i + 1; j < EffectPending.size( ); j++ ){
        if( !EffectPending[ j ].IsStale ){
          Copy( &EffectPending[ j ] , &EffectPending[ i ] );
          ok = true;
          break;
        }
      }

      if( !ok ){
        Effect *TEffect = Find( &EffectInUse , SinceLastRare );
        if( TEffect != NULL ){
          Copy( TEffect , &EffectPending[ i ] );
          EffectInUse.reserve( EffectInUse.size( ) + 1 );
          EffectInUse.push_back( TEffect->Identifier );
          ok = true;
        }
      }

      if( !ok ){
        result = false;
      }
    }
  }

  EffectInUse.clear( );

  return result;
}

void FunCry::DisplayList( ){
  if( !FUNCRY_NO_DISPLAY ){
    #ifndef FUNCRY_DISABLE_AUTO
      float PosTop = 200.0f;
      Rend->SetState( GS_BLSRC_SRCALPHA | GS_BLDST_ONEMINUSSRCALPHA | GS_NODEPTHTEST );
      Rend->Draw2dImage( 10.0f * ScaleW , PosTop + 10.0f , 200.0f * ScaleW , ( ( EffectActive.size( ) + ( EffectPendingShownCount < EffectPending.size( ) ? EffectPendingShownCount : EffectPending.size( ) ) ) * 20.0f ) + 6.0f , DEF_TEXARG0 , 0 , 0.1f , 0.1f , 0 , 0 , 0 , 0 , 0 , 0.25f );

      FunText->Reset( );
      FunText->UseRealPixels( false );
      FunText->SetColor( color4f( 1 , 1 , 1 , 1.0f ) );
      FunText->SetSize( vector2f( 10.0f * ScaleW , 14.0f ) );

      unsigned int Active = 0;
      for( unsigned int i = 0; i < EffectActive.size( ); i++ ){
        FunText->DrawString( 20.0f * ScaleW , PosTop + 15.0f + ( Active * 20.0f ) , EffectActive[ i ].Title.c_str( ) , false );
        DrawProgress( 160.0f * ScaleW , PosTop + 10.0f + ( Active * 20.0f ) , 100.0f - ( ( TimeNow - EffectActive[ i ].TimeStarted ) / EffectActive[ i ].TimeEffective ) * 100.0f );
        Active++;
      }

      FunText->SetColor( color4f( 1 , 1 , 1 , 0.5f ) );
      for( unsigned int i = 0; i < EffectPending.size( ) && i < EffectPendingShownCount; i++ ){
        FunText->DrawString( 20.0f * ScaleW , PosTop + 15.0f + ( Active * 20.0f ) , EffectPending[ i ].Title.c_str( ) , false );
        Active++;
      }

      FunText->SetColor( color4f( 1 , 1 , 1 , 1.0f ) );
    #endif
  }
}

void FunCry::DrawProgress( float x , float y , float prog ){
  float h = 10.0f,
  w = 40.0f * ScaleW;
  y += h * 0.8f;
  Rend->Draw2dImage( x , y , w , h , DEF_TEXARG1 , 0 , 0.1f , 0.1f , 0 , 0 , 1 , 1 , 1 , 0.25f );
  float W = w * ( prog / 100.0f );

  if( W > w ){
    W = w;
  }
  else if( W < 0 ){
    W = 0;
  }

  Rend->Draw2dImage( x + ( ( w - W ) * 0.5f ) , y , W , h , DEF_TEXARG1 , 0 , 0.1f , 0.1f , 0 , 0 , 1 , 1 , 1 , 0.75f );
}

void FunCry::DisplayAltList( ){
  if( !FUNCRY_NO_DISPLAY ){

    FunText->Reset( );
    FunText->UseRealPixels( false );
    FunText->SetColor( color4f( 1 , 1 , 1 , 1.0f ) );
    FunText->SetSize( vector2f( 20.0f * ScaleW , 26.0f ) );

    unsigned int Active = 0;
    for( unsigned int i = 0; i < EffectActive.size( ) /* && i <= 2 */; i++ ){
      FunText->DrawString( 40.0f * ScaleW , 325.0f + ( i * 30.0f ) , EffectActive[ i ].Title.c_str( ) , false );
    }
  }
}

#ifdef FUNCRY_MANUAL_MODE
  unsigned int FunCry::GetCurrentSlot( ){
    FunLog::Log( FUNLOG_BASIC , "GetCurrentSlot( )" );

    return DebugSlotPos;
  }

  bool FunCry::StartManually( unsigned int Sel , bool CopyToList ){
    FunLog::Log( FUNLOG_BASIC , "StartManually( )" );

    if( CopyToList ){
      //if( EffectList[ Sel ].IsEnabled ){
        if( EffectActive[ 0 ].IsActive ){
          Effects::Stop( &EffectActive[ 0 ] );
        }
        Effects::Copy( &EffectList[ Sel ] , &EffectActive[ 0 ] );
        return Effects::Start( &EffectActive[ 0 ] );
      //}
      //return false;
    }
    else{
      //if( EffectList[ Sel ].IsEnabled ){
        if(
          EffectList[ Sel ].IsActive
          //&&
          //EffectList[ Sel ].IsResumable
        ){
          Effects::Stop( &EffectList[ Sel ] );
          return true;
        }
        else{
          return Effects::Start( &EffectList[ Sel ] );
        }
      //}
      //return false;
    }
  }

  void FunCry::DecrementSlot( ){
    FunLog::Log( FUNLOG_BASIC , "DecrementSlot( )" );

    if( DebugSlotPos > 0 ){
      DebugSlotPos--;
    }
  }

  void FunCry::IncrementSlot( ){
    FunLog::Log( FUNLOG_BASIC , "IncrementSlot( )" );

    DebugSlotPos++;
    if( DebugSlotPos > EffectList.size( ) - 1 ){
      DebugSlotPos = EffectList.size( ) - 1;
    }
  }

  void FunCry::ToggleSlot( ){
    FunLog::Log( FUNLOG_BASIC , "ToggleSlot( )" );

    DebugSlotDisplay = !DebugSlotDisplay;
  }
#endif
