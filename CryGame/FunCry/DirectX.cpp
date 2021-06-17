/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "FunCry.h"
#include "Effect.h"

#pragma comment( lib , "../DX9SDK/Lib/d3dx9.lib" )

void Effects::DXBeforeRender( ){
  if( Effects::IsMatrixV2 ){
    D3DXMATRIX Matrix;
    D3DXMatrixIdentity( &Matrix );
    D3DXMatrixScaling( &Matrix  , 1.5f , 1 , 1 );
    FunCry::D3D->SetTransform( D3DTS_WORLD , &Matrix );
  }
}

void Effects::DXAfterRender( ){
  if( Effects::IsMatrixV2 ){
    D3DXMATRIX Matrix;
    D3DXMatrixIdentity( &Matrix );
    D3DXMatrixScaling( &Matrix  , 1 , 1 , 1 );
    FunCry::D3D->SetTransform( D3DTS_WORLD , &Matrix );
  }
}
