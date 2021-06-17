/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

//! very basic logging [probably always on]
#define FUNCRY_BASIC_LOG

//! detailed logging [basic debugging]
//#define FUNCRY_DETAIL_LOG

//! debugging logging [targeted debugging]
//#define FUNCRY_DEBUG_LOG
#ifdef FUNCRY_DEBUG_LOG
  #include <sstream>
#endif

//! disable automatic effects [so they can be tested manually, most likely]
//#define FUNCRY_DISABLE_AUTO

//! disable effects regardless of circumstance [they will report being started, but no action will be taken]
//#define FUNCRY_DISABLE_ALL

//! disable all sounds [temporarily, for compile speed]
//#define FUNCRY_NO_SOUND

//! enables control over the effects manually [for debugging] [via arrow keys]
//#define FUNCRY_MANUAL_MODE

#include "../CryGame/StdAfx.h"

#include "../DX9SDK/include/d3dx9.h"

namespace FunCry{
  //! start FunCry
  extern void Start( CXGame * );
  //! stop FunCry
  extern void Stop( );
  //! reset FunCry
  extern void Reset( CXGame * );
  //! update FunCry
  extern void Update( bool );

  ///////////////

  //! start effect system
  extern void StartupEffects( );
  //! stop effect system
  extern void ShutdownEffects( );
  //! start hook system
  extern void StartupHooks( );
  //! stop hook system
  extern void ShutdownHooks( );

  ///////////////

  extern CXGame            *Game;
  extern IRenderer         *Rend;
  extern I3DEngine         *Eng;
  extern ITimer            *Time;
  extern IScriptSystem     *Script;
  extern ISoundSystem      *Sound;
  extern IFFont            *FunText;
  extern IEntity           *Jack;
  extern CPlayer           *Carver;
  extern LPDIRECT3DDEVICE9  D3D;

  ///////////////

  //! game cutscene
  extern bool IsCutscene;
  //! game play
  extern bool IsGameplay;
  //! game loading
  extern bool IsLoading;
  //! game paused
  extern bool IsPaused;
  //! current time
  extern float TimeNow;
  //! last rare effect time
  extern float TimeRareStarted;
  //! last rare effect identifier
  extern unsigned int LastVeryRareIdentifier;
  //! last level name
  extern char LastLevelName[ 256 ];

  ///////////////

  //! pause all effects
  extern void PauseAll( );
  //! play a sound
  extern bool PlaySound( const char *Target = NULL );

  ///////////////

  //! reads the config file
  extern string ReadCfg( string );
  //! control ability to use Funlog tool
  extern bool CanFunlog;
  //! seed the random number generator
  extern void SeedRand( );

  ///////////////

  //! display effect lists
  extern void DisplayList( );
  //! display progress bar
  extern void DrawProgress( float , float , float );
  //! display effect lists [large text, three maximum shown]
  extern void DisplayAltList( );

  ///////////////

  #ifdef FUNCRY_MANUAL_MODE
    //! read currently selected slot
    extern unsigned int GetCurrentSlot( );
    //! start an effect manually
    extern bool StartManually( unsigned int Sel , bool CopyToList = false );
    //! decrement manual slot
    extern void DecrementSlot( );
    //! increment manual slot
    extern void IncrementSlot( );
    //! toggle display of slot info
    extern void ToggleSlot( );
  #endif

  ///////////////

  extern void CHECK_SCALEWIDTH( );

  ///////////////

  extern void Experiment( );
  extern bool IsCustomExperiment;
}
