/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "FunCry.h"
#include "Color.h"

static std::vector<CColor *> ColorList;

CColor::CColor( ){
  r_255 = (float)(rand( ) % 255);
  g_255 = (float)(rand( ) % 255);
  b_255 = (float)(rand( ) % 255);

  r_1 = r_255 / 255.0f;
  g_1 = g_255 / 255.0f;
  b_1 = b_255 / 255.0f;  

  Increment = true;
  CurrentColor = 1;

  ColorList.reserve( ColorList.size( ) + 1 ); ColorList.push_back( this );
}

CColor::~CColor( ){
  
}

static float TimedDelay = 0.002f;
static float TimeLast = FunCry::TimeNow - ( TimedDelay * 2.0f );

void FunColor::UpdateColors( ){
  if( FunCry::TimeNow - TimeLast >= TimedDelay ){
    float IncSize = 0.3f;
    for( unsigned int i = 0; i < ColorList.size( ); i++ ){
      if( ColorList[ i ]->CurrentColor == 1 ){ // r
        if( ColorList[ i ]->Increment ){
          ColorList[ i ]->r_255 += IncSize;
          if( ColorList[ i ]->r_255 > 255 ){
            ColorList[ i ]->r_255 = 255;
            ColorList[ i ]->Increment = false;
            ColorList[ i ]->CurrentColor = 2;
          }
        }
        else{
          ColorList[ i ]->r_255 -= IncSize;
          if( ColorList[ i ]->r_255 < 0 ){
            ColorList[ i ]->r_255 = 0;
            ColorList[ i ]->Increment = true;
            ColorList[ i ]->CurrentColor = 2;
          }
        }
      }
      else if( ColorList[ i ]->CurrentColor == 2 ){ // g
        if( ColorList[ i ]->Increment ){
          ColorList[ i ]->g_255 += IncSize;
          if( ColorList[ i ]->g_255 > 255 ){
            ColorList[ i ]->g_255 = 255;
            ColorList[ i ]->Increment = false;
            ColorList[ i ]->CurrentColor = 3;
          }
        }
        else{
          ColorList[ i ]->g_255 -= IncSize;
          if( ColorList[ i ]->g_255 < 0 ){
            ColorList[ i ]->g_255 = 0;
            ColorList[ i ]->Increment = true;
            ColorList[ i ]->CurrentColor = 3;
          }
        }
      }
      else if( ColorList[ i ]->CurrentColor == 3 ){ // b
        if( ColorList[ i ]->Increment ){
          ColorList[ i ]->b_255 += IncSize;
          if( ColorList[ i ]->b_255 > 255 ){
            ColorList[ i ]->b_255 = 255;
            ColorList[ i ]->Increment = false;
            ColorList[ i ]->CurrentColor = 1;
          }
        }
        else{
          ColorList[ i ]->b_255 -= IncSize;
          if( ColorList[ i ]->b_255 < 0 ){
            ColorList[ i ]->b_255 = 0;
            ColorList[ i ]->Increment = true;
            ColorList[ i ]->CurrentColor = 1;
          }
        }
      }

      ColorList[ i ]->r_1 = ColorList[ i ]->r_255 / 255.0f;
      ColorList[ i ]->g_1 = ColorList[ i ]->g_255 / 255.0f;
      ColorList[ i ]->b_1 = ColorList[ i ]->b_255 / 255.0f;
    }
  }
  TimeLast = FunCry::TimeNow;
}

void FunColor::StopColor( ){
  ColorList.clear( );
}
