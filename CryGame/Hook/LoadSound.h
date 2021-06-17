/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

namespace hkLoadSound{
  extern void StartupSoundDB( bool = false );

  extern void ShutdownSoundDB( );

  extern const char *ProcessSound( const char * = NULL );
  extern const char *RandomSound_Any( );
  extern const char *RandomSound_Languages( );
  extern const char *RandomSound_Sounds( );
}
