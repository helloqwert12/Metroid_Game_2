#pragma once
#include "BulletObject.h"
#include "Parameters.h"

class RidleyBoomerang : public BulletObject
{
protected:

	Sprite * right;

public:
	RidleyBoomerang(World * manager);
	~RidleyBoomerang();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void Update(float t);
	void Render();
	void Shoot(BULLET_DIRECTION dir, float posX, float posY);
};