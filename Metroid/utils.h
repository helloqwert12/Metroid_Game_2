#ifndef __UTILS_H_
#define __UTILS_H_

#include <d3d9.h>
#include "Collider.h"

LPDIRECT3DSURFACE9 CreateSurfaceFromFile(LPDIRECT3DDEVICE9 d3ddv, LPWSTR FilePath);
void DrawCollider(LPDIRECT3DDEVICE9 d3ddv, float x, float y, Collider* collider, D3DCOLOR color);
LPDIRECT3DTEXTURE9 LoadTexture(LPWSTR imgPath, LPD3DXSPRITE spriteHandler);
void Output(float t);

struct CUSTOMVERTEX
{
	FLOAT x, y, z, weight;
	DWORD color;
};

#endif