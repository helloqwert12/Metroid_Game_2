#include "BulletManager.h"
#include "World.h"
#include "Metroid.h"
#include "Bullet.h"
#include "SentryBullet.h"
#include "BirdBullet.h"
#include "RidleyBoomerang.h"
#include "Parameters.h"
#include "utils.h"

BulletManager::BulletManager(LPD3DXSPRITE spriteHandler, World * manager, BULLET_TYPE bullet_type)
{
	this->manager = manager;
	this->spriteHandler = spriteHandler;
	//Create instance bullet_list
	
	switch (bullet_type)
	{
	case STANDARD:
		num = STANDARD_NUM;
		image = LoadTexture(BULLET_SPRITE_PATH, spriteHandler);
		break;
	case MISSILE:
		num = MISSILE_NUM;
		image = LoadTexture(MISSILE_SPRITE_PATH, spriteHandler);
		break;
	case SENTRY_BULLET:
		num = SENTRY_BULLET_NUM;
		image = LoadTexture(SENTRY_BULLET_SPIRTE_PATH, spriteHandler);
		break;
	case BIRD_BULLET:
		num = BIRD_BULLET_NUM;
		image = LoadTexture(BULLET_SPRITE_PATH, spriteHandler);
		break;
	case BOOMERANG:
		num = RIDLEY_BOOMERANG_NUM;
		image = LoadTexture(RIDLEY_BOOMERANG_SPIRTE_PATH, spriteHandler);
		break;
	case ICEBEAM:
		num = ICEBEAM_NUM;
		image = LoadTexture(ICEBEAM_SPRITE_PATH, spriteHandler);
		break;
	case BOMB:
		num = BOMB_NUM;
		image = LoadTexture(BOMB_SPRITE_PATH, spriteHandler);
		break;
	}
	bullet_list = new BulletObject*[num];
	switch (bullet_type)
	{
	case STANDARD:
		//bullet_list = new BulletObject*[STANDARD_NUM];
		for (int i = 0; i < num; i++)
		{
			bullet_list[i] = new Bullet(spriteHandler, manager);
		}
		manager->samus->setNum(num);
		manager->samus->setListBullet(bullet_list);
		break;
	case MISSILE:
		for (int i = 0; i < num; i++)
		{
			bullet_list[i] = new Missile(spriteHandler, manager);
		}
		break;
	case SENTRY_BULLET:
		for (int i = 0; i < num; i++)
		{
			bullet_list[i] = new SentryBullet(spriteHandler, manager);
		}
		break;
	case BIRD_BULLET:
		for (int i = 0; i < num; i++)
		{
			bullet_list[i] = new BirdBullet(spriteHandler, manager);
		}
		break;
	case BOOMERANG:
		for (int i = 0; i < num; i++)
		{
			bullet_list[i] = new RidleyBoomerang(spriteHandler, manager);
		}
		break;
	case ICEBEAM:
		for (int i = 0; i < num; i++)
		{
			bullet_list[i] = new IceBeam(spriteHandler, manager);
		}
		break;
	case BOMB:
		for (int i = 0; i < num; i++)
		{
			bullet_list[i] = new Bomb(spriteHandler, manager);
		}
		break;
		// ...
	}


	_Index = 0;
	this->start_shoot = 0;
	//this->tick_per_frame = manager->metroid->GetTickPerFrame();
	this->frame_rate = manager->metroid->FrameRate;
	this->tick_per_frame = 1000 / 80;
}

//BulletManager::BulletManager(int posX, int posY)
//{
//	BulletManager();
//	this->pos_x_holder = posX;
//	this->pos_y_holder = posY;
//}


BulletManager::~BulletManager()
{
	for (int i = 0; i < num; i++)
	{
		delete(bullet_list[i]);
	}
	delete(bullet_list);
}

void BulletManager::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	for (int i = 0; i < num; i++)
	{
		bullet_list[i]->InitSprites(d3ddv, image);
	}
}

void BulletManager::InitPosition(int posX, int posY)
{
	for (int i = 0; i < num; i++)
	{
		bullet_list[i]->InitPosition(pos_x_holder, pos_y_holder);
	}
}

void BulletManager::ResetAll()
{
	_Index = 0;
	for (int i = 0; i < num; i++)
	{
		bullet_list[i]->Reset();
	}
}

//void BulletManager::Next(BULLET_DIRECTION dir)
//{
//	bullet_list[_Index]->Shoot(dir);
//	_Index = (_Index + BULLET_COUNT - 1) % BULLET_COUNT;
//}

void BulletManager::Next(BULLET_DIRECTION dir, float posX, float posY)
{
	bullet_list[_Index]->Shoot(dir, posX, posY);
	_Index = (_Index + num - 1) % num;
}

void BulletManager::Update(float t)
{
	for (int i = 0; i < num; i++)
	{
		bullet_list[i]->Update(t);
	}

}

void BulletManager::Render()
{
	for (int i = 0; i < num; i++)
	{
		bullet_list[i]->Render();
	}
}

void BulletManager::setNum(int numBullet)
{
	num = numBullet;
}

int BulletManager::getNum()
{
	return num;
}

// Cái này chưa dùng được bị sai
//void BulletManager::Shoot(BULLET_DIRECTION dir)
//{
//	now_shoot = GetTickCount();
//	if (start_shoot <= 0) //if shooting is active
//	{
//		start_shoot = GetTickCount();
//		this->Next(dir);
//	}
//	else if ((now_shoot - start_shoot) > 1000);
//	{
//		//Reset start_shoot
//		start_shoot = 0;
//	}
//}

