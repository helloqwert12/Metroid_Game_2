#pragma once
#ifndef _WORLD_H_
#define _WORLD_H_

#define BEDGEHOG_YELLOW_COUNT 3
#define BEDGEHOG_PINK_COUNT 3
#define BIRD_COUNT 3
#define BLOCK_COUNT 3
#define BEE_COUNT 2

#include <d3dx9.h>
#include "Samus.h"
#include "Parameters.h"
#include "Bedgehog.h"
#include "Block.h"
#include "Bird.h"
#include "Bee.h"
#include "Sentry.h"
#include "MotherBrain.h"
#include "Ridley.h"

/*
	Class này chứa tất cả những thứ trong Game
	Các class khác chứa con trỏ đến class này để thao tác với các đối tượng trong class này
*/

class Metroid;

class World
{
public:
	Metroid * metroid;
	Samus * samus;

	LPD3DXSPRITE spriteHandler;

	QNode * rootQNode1;
	QNode * rootQNode2;
	GroupObject * quadtreeGroup;
	GroupObject * qtreeGroup;
	GroupObject * colBrick;

	//Enemy
	Bedgehog * hogs_yellow[BEDGEHOG_YELLOW_COUNT];
	Bedgehog * hogs_pink[BEDGEHOG_PINK_COUNT];
	Bird * birds[BIRD_COUNT];
	Block * blocks[BLOCK_COUNT];
	Bee * bees[BEE_COUNT];

	Bedgehog * hog_yellow;
	Bedgehog * hog_pink;
	Bird * bird;
	Block * block;
	Bee * bee;

	Sentry * sentryLeft;
	Sentry * sentryRight;
	Sentry * sentryTop;

	MotherBrain * motherBrain;
	Ridley * ridley;

	BulletManager * bullets;
	BulletManager * missiles;
	BulletManager * sentrybullets;
	BulletManager * birdbullets;
	BulletManager * ridleyBoomerang;

	MorphItem * morphItem;
	EnergyItem * energyItem;
	MissileItem * missileItem;

	ExplosionEffect * explsEffect;

	GroupObject * collisionGroup;	//Group chứa các gameobject có khả năng va chạm với nhau
	GroupObject * enemyGroup;
	GroupObject * effectgroup;

	PositionManager* posManager;

	World();
	World(LPD3DXSPRITE spriteHandler, Metroid * metroid);
	~World();

	//void Init();
	void Update(float t);
	void Render();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	//void Destroy();

};

#endif // !_WORLD_H_

