/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

class Effect{
  public:
    //! title
    string Title;
    //! unique ID
    unsigned int Identifier;
    //! target duration
    float TimeEffective;
    //! true if the target time may not be over-ridden
    bool TimeEffectiveFixed;
    //! time started
    float TimeStarted;
    //! time spent active when paused
    float TimeActive;

    /////

    //! current state
    bool IsActive;
    //! true if the effect may be used
    bool IsEnabled;
    //! true if the effect may be stopped when it is being "paused"
    bool IsPausable;
    //! current state
    bool IsPaused;
    //! true if the effect may be started when resuming after being "paused"
    bool IsResumable;
    //! true if needs to be replaced
    bool IsStale;
    //! frequency control
    bool IsRare;
    //! frequency control
    bool IsVeryRare;

    /////

    Effect( ){
      Title              = "NO TITLE";
      Identifier         = 999999;
      TimeEffective      = 0;
      TimeEffectiveFixed = false;
      TimeStarted        = 0;
      TimeActive         = 0;
      IsActive           = false;
      IsEnabled          = true;
      IsPausable         = true;
      IsPaused           = false;
      IsResumable        = true;
      IsStale            = true;
      IsRare             = false;
      IsVeryRare         = false;
    }

    Effect( string _Title , unsigned int _Identifier , bool _IsEnabled , bool _IsPausable , bool _IsResumable , float _TimeEffective , bool _TimeEffectiveFixed , bool _IsRare , bool _IsVeryRare ){
      Title              = _Title;
      Identifier         = _Identifier;
      TimeEffective      = _TimeEffective;
      TimeEffectiveFixed = _TimeEffectiveFixed;
      TimeStarted        = 0;
      TimeActive         = 0;
      IsActive           = false;
      IsEnabled          = _IsEnabled;
      IsPausable         = _IsPausable;
      IsPaused           = false;
      IsResumable        = _IsResumable;
      IsStale            = false;
      IsRare             = _IsRare;
      IsVeryRare         = _IsVeryRare;
    }
};

class GamePos{
  public:
    //! camera angle
    Vec3 Angle;
    //! player location
    Vec3 Pos;

    /////

    GamePos( ){
      Angle = Vec3( 0 , 0 , 0 );
      Pos = Vec3( 0 , 0 , 0 );
    }

    GamePos( float pX , float pY , float pZ , float aX , float aY , float aZ ){
      Angle = Vec3( aX , aY , aZ );
      Pos = Vec3( pX , pY , pZ );
    }
};

class GamePosDetail : public GamePos{
  public:
    //! level name
    char Level[ 256 ];

    /////

    GamePosDetail( ) : GamePos( ){ }
};

class HudState{
  public:
    float LeftX;
    float LeftY;
    float RightX;
    float RightY;
    float ScaleX;
    float ScaleW;

    ///////////

    HudState( ){
      LeftX  = 0;
      LeftY  = 0;
      RightX = 0;
      RightY = 0;
      ScaleX = 0;
      ScaleW = 0;

      Active = false;
    }

    void Clear( ){
      LeftX  = 0;
      LeftY  = 0;
      RightX = 0;
      RightY = 0;
      ScaleX = 0;
      ScaleW = 0;

      Active = false;
    }

    bool IsSet( ){
      return Active;
    }

    void Set( float _LeftX , float _LeftY , float _RightX , float _RightY , float _ScaleX , float _ScaleW ){
      LeftX  = _LeftX;
      LeftY  = _LeftY;
      RightX = _RightX;
      RightY = _RightY;
      ScaleX = _ScaleX;
      ScaleW = _ScaleW;

      Active = true;
    }

  private:
    bool Active;
};

namespace Effects{
  //! update effects
  extern void UpdateEffects( bool , bool , bool , bool );

  ////////////////

  extern std::vector<GamePos> SpawnSpot_Training;
  extern std::vector<GamePos> SpawnSpot_Carrier;
  extern std::vector<GamePos> SpawnSpot_Fort;
  extern std::vector<GamePos> SpawnSpot_Pier;
  extern std::vector<GamePos> SpawnSpot_Research;
  extern std::vector<GamePos> SpawnSpot_Treehouse;
  extern std::vector<GamePos> SpawnSpot_Bunker;
  extern std::vector<GamePos> SpawnSpot_Steam;
  extern std::vector<GamePos> SpawnSpot_Regulator;
  extern std::vector<GamePos> SpawnSpot_Control;
  extern std::vector<GamePos> SpawnSpot_Rebellion;
  extern std::vector<GamePos> SpawnSpot_Archive;
  extern std::vector<GamePos> SpawnSpot_Cooler;
  extern std::vector<GamePos> SpawnSpot_Boat;
  extern std::vector<GamePos> SpawnSpot_Catacombs;
  extern std::vector<GamePos> SpawnSpot_River;
  extern std::vector<GamePos> SpawnSpot_Swamp;
  extern std::vector<GamePos> SpawnSpot_Factory;
  extern std::vector<GamePos> SpawnSpot_Dam;
  extern std::vector<GamePos> SpawnSpot_Volcano;

  ////////////////

  extern std::vector<char *> Skybox_Shader;

  ////////////////

  //! copy
  extern void Copy( Effect * , Effect * );
  //! find
  extern Effect *Find( std::vector<unsigned int> * , float );
  //! start
  extern bool Start( Effect * );
  //! pause
  extern void Pause( Effect * );
  //! stop
  extern void Stop( Effect * , bool Pause = false );

  ////////////////

  //! texture for Black Ops
  extern int BlackOpsCrosshair;
  //! widescreen effect
  extern bool WidescreenEnabled;
  //! widescreen scaling
  extern float ScaleW;
  //! temporary scalewidth over-ride for the radar
  extern float ScaleW_Temp;

  ////////////////

  extern bool Chance( unsigned int );

  ////////////////

  //! teleport to specified map position
  extern void TeleportTo( float , float );
  //! teleport to specified map position and angle
  extern void TeleportToSpecific( GamePos * );
  //! set Field of View
  extern void SetFOV( float );
  //! show a simple overlay effect
  extern void SimpleFilter( );
  //! controls rendering of simple filters
  extern bool SimpleFilterActive;
  //! identifier of current simple filter
  extern unsigned int SimpleFilterCode;
  //! special aimed effects
  extern void DoAimedEffect( );
  //! control over the real time scaling feature
  extern bool SizeMatters;
  //! control over the Black Ops effect
  extern bool CIAWork;
  //! screen-saver effect
  extern void DoScreensaver( );
  //! control over the screen-saver effect
  extern bool IsScreenSaver;
  //! control over the alt Hud feature
  extern bool IsAltHud;
  //! control over the Funky Hud effect
  extern bool IsFunkyHud;
  //! control over the Funky Weapon effect
  extern bool IsFunkyWeapon;
  //! enforce certain player stats
  extern void EnforcedStats( );
  //! force infinite health
  extern bool IsInfiniteHealth;
  //! force infinite armor
  extern bool IsInfiniteArmor;
  //! force infinite stamina
  extern bool IsInfiniteStamina;
  //! force no stamina
  extern bool IsZeroStamina;
  //! control drink camera
  extern bool IsDrunk;
  //! Matrix V2 effect
  extern bool IsMatrixV2;
  //! CyberCry 2077
  extern bool IsCyberCry;
  //! controls updating of weapon shaders [not every frame..]
  extern bool NeedWeapShaderUpdate;
  //! controls updating of weapon shaders [not every frame..]
  extern bool NeedWeapShaderForce;
  //! controls pulsing hud feature
  extern bool IsPulsingHud;
  extern float PulsingHudMultiplier;

  ////////////////

  //! status of audio randomizer capability
  extern bool FancySoundCapability;

  //! controls voices being changed to Val
  extern bool IsValVoice;
  //! controls conversation randomization
  extern bool IsConversationRandomizer;
  //! controls languages randomization
  extern bool IsLanguagesRandomizer;

  /// //! controls weapons screaming
  /// extern bool IsPainfulWeapon;




  ////////////////

  //! status of Character/Object randomizer capability
  extern bool FancyCharacterObjectCapability;

  //! controls in-game cutscene effects
  extern bool IsInGameCutSceneRandomizer;
  //! controls AI character randomizer
  extern bool IsAICharacterRandomizer;
  //! controls AI weapon randomizer
  extern bool IsAIWeaponRandomizer;
  //! make AI drop normal weapon regardless of what is in their hands
  extern bool IsAIWeaponDropOriginal;

  ////////////////

  //! video playback effect
  extern unsigned int VideoPlayEffect;

  ////////////////

  //! effects just before render
  extern void DXBeforeRender( );
  //! effects just after render
  extern void DXAfterRender( );
}
