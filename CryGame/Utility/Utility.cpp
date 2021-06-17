/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "Utility.h"
#include <stdlib.h>

/// IMPROVE THE RANDOMNESS OF THESE THINGS

unsigned int Utility::getRandomIndex( const int vSize ){
  if( vSize <= 1 ){
    return 0;
  }

  return rand( ) % vSize;
}

unsigned int Utility::getRandomInRange( const unsigned int l , const unsigned int u ){
  return l + ( rand( ) % ( u - l ) );
}
