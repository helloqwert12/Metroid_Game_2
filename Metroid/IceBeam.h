#pragma once
#ifndef _ICEBEAM_H_
#define _ICEBEAM_H_

#include "GameObject.h"
#include "Sprite.h"
#include "Parameters.h"
#include "BulletObject.h"

#define ICEBEAM_SPRITE_PATH L"sprites\\bullet\\icebeam.png"
#define ICEBEAM_UP_SPRITE "sprites\\bullet\\ICEBEAM_UP.txt"
#define ICEBEAM_LEFT_SPRITE "sprites\\bullet\\ICEBEAM_LEFT.txt"
#define ICEBEAM_RIGHT_SPRITE "sprites\\bullet\\ICEBEAM_RIGHT.txt"

#define ICEBEAM_WIDTH 24
#define ICEBEAM_HEIGHT 16


#define ICEBEAM_UP_WIDTH 16
#define ICEBEAM_UP_HEIGHT 24

#define ICEBEAM_COUNT 1
#define SPRITE_PER_ROW 1

#define SPEED 0.3f
#define LIMIT_DISTANCE 100


class IceBeam : public BulletObject
{
private:

	Sprite * icebeam_up;
	Sprite * icebeam_left;
	Sprite * icebeam_right;

public:

	IceBeam(World * manager);
	IceBeam(World * manager, int x_holder, int y_holder);
	~IceBeam();

	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);

	void Render();
};

#endif // !_ICEBEAM_H

