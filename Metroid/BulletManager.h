﻿#pragma once
#ifndef _BULLETMANAGER_H_
#define _BULLETMANAGER_H_
#include "Bullet.h"
#include "Missile.h"
#include "IceBeam.h"
#include "Bomb.h"
#include "Parameters.h"
#define BULLET_COUNT 5

class BulletManager
{
private:
	World * manager;
	BulletObject ** bullet_list;
	int pos_x_holder;
	int pos_y_holder;
	int _Index;
	DWORD now_shoot;
	DWORD start_shoot;
	DWORD tick_per_frame;
	int frame_rate;
	int num;		// số lượng đạn tạo sẵn, tùy theo mỗi loại đạn mà có số lượng khác nhau
	LPDIRECT3DTEXTURE9 image;
	LPD3DXSPRITE spriteHandler;
	
public:
	//BulletManager();
	BulletManager(LPD3DXSPRITE spriteHandler, World * manager, BULLET_TYPE bullet_type);
	//BulletManager(int posX, int posY);
	~BulletManager();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void InitPosition(int posX, int posY);
	void ResetAll();
	//void Next(BULLET_DIRECTION dir);
	void Next(BULLET_DIRECTION dir, float posX, float posY);
	void Update(float t);
	void Render();
	void RenderDebug(LPDIRECT3DDEVICE9 d3ddv, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 0));
	void setNum(int numBullet);
	int getNum();
	//void Shoot(BULLET_DIRECTION dir);
	BulletObject ** Getlist()
	{
		return this->bullet_list;
	}
};

#endif // !_BULLETMANAGER_H_



