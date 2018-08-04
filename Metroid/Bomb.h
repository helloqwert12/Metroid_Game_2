#pragma once
#ifndef _BOMB_H_
#define _BOMB_H_

#include "GameObject.h"
#include "Sprite.h"
#include "Parameters.h"
#include "BulletObject.h"

#define BOMB_SPRITE_PATH L"sprites\\bullet\\Bomb.png"
#define BOMB_SPRITE "sprites\\bullet\\BOMB.txt"

#define BOMB_WIDTH 20
#define BOMB_HEIGHT 20

#define BOMB_COUNT 2
#define SPRITE_PER_ROW 1


class Bomb : public BulletObject
{
protected:
	Sprite * bomb;
	float time_exist;

public:
	Bomb(LPD3DXSPRITE spriteHandler, World * manager);
	Bomb(LPD3DXSPRITE spriteHandler, World * manager, int x_holder, int y_holder);
	~Bomb();

	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 image);

	void Update(float t);
	void Render();
};

#endif // !_BOMB_H