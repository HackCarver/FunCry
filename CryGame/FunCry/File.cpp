/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "FunCry.h"
using namespace FunCry;

#include "../CryGame/GameMods.h"

static string STrim( string s ){
  string::const_iterator it = s.begin( );
  while( it != s.end( ) && isspace( *it ) ){
    it++;
  }
  string::const_reverse_iterator rit = s.rbegin( );
  while( rit.base( ) != it && isspace( *rit ) ){
    rit++;
  }
  return string( it , rit.base( ) );
}

// pretty terrible
string FunCry::ReadCfg( string Target ){
  string Mod( Game->GetModsList( )->GetCurrentMod( ) );
  if( Mod != "" ){
    FILE *File = fopen( ( "Mods/" + Mod + string( "/Config.cfg" ) ).c_str( ) , "r" );
    if( File ){
      char line[ 1024 ] = { 0 };

      string key;
      int delimiter;
      string RLine;
      string value;

      while( fgets( line , 1024 , File ) ){
        RLine = string( line );
        delimiter = RLine.find_last_of( ":" );
        key = STrim( RLine.substr( 0 , delimiter ) );
        value = STrim( RLine.substr( delimiter + 1 ) );
        if( key == Target ){
          return string( value );
        }
      }

      fclose( File );
    }
  }
  return "";
}
