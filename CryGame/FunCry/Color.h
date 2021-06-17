/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "../CryGame/StdAfx.h"

class CColor{
  public:
    //! red
    float r_1;
    float r_255;
    //! green
    float g_1;
    float g_255;
    //! blue
    float b_1;
    float b_255;
    //! ID
    unsigned int ID;

    bool Increment;
    unsigned int CurrentColor;

    CColor( );
    ~CColor( );
};

namespace FunColor{
  //! update colors
  extern void UpdateColors( );
  //! stop colors
  extern void StopColor( );

  /////////////////

  //! color over-ride for the HUD
  extern CColor FuturisticColor;
}
