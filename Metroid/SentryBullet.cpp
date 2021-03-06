﻿#include "SentryBullet.h"
#include "World.h"
#include "GroupObject.h"


SentryBullet::SentryBullet(LPD3DXSPRITE spriteHandler, World * manager)
{
	this->manager = manager;
	this->spriteHandler = spriteHandler;
	up = NULL;
	left = NULL;
	right = NULL;
	bottom = NULL;
	topleft = NULL;
	topright = NULL;
	bottomleft = NULL;
	bottomright = NULL;
	limit_dist_x = 0;
	limit_dist_y = 0;
	isActive = false;

	damage = DAMAGE_SENTRY_BULLET;

	this->bulletType = SENTRY_BULLET;

	//Set collider
	collider = new Collider(SENTRY_BULLET_HEIGHT / 2, -SENTRY_BULLET_WIDTH / 2, -SENTRY_BULLET_HEIGHT / 2, SENTRY_BULLET_WIDTH / 2);
}

SentryBullet::~SentryBullet()
{
}

void SentryBullet::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &spriteHandler);
	if (result != D3D_OK) return;

	//Create sprite
	up = new Sprite(spriteHandler, SENTRY_BULLET_SPIRTE_PATH, SENTRY_BULLET_UP, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	left = new Sprite(spriteHandler, SENTRY_BULLET_SPIRTE_PATH, SENTRY_BULLET_LEFT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	right = new Sprite(spriteHandler, SENTRY_BULLET_SPIRTE_PATH, SENTRY_BULLET_RIGHT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	bottom = new Sprite(spriteHandler, SENTRY_BULLET_SPIRTE_PATH, SENTRY_BULLET_BOTTOM, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	topleft = new Sprite(spriteHandler, SENTRY_BULLET_SPIRTE_PATH, SENTRY_BULLET_TOPLEFT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	topright = new Sprite(spriteHandler, SENTRY_BULLET_SPIRTE_PATH, SENTRY_BULLET_TOPRIGHT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	bottomleft = new Sprite(spriteHandler, SENTRY_BULLET_SPIRTE_PATH, SENTRY_BULLET_BOTTOMLEFT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	bottomright = new Sprite(spriteHandler, SENTRY_BULLET_SPIRTE_PATH, SENTRY_BULLET_BOTTOMRIGHT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
}

void SentryBullet::InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 image)
{
	//Create sprite
	up = new Sprite(spriteHandler, image, SENTRY_BULLET_UP, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	left = new Sprite(spriteHandler, image, SENTRY_BULLET_LEFT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	right = new Sprite(spriteHandler, image, SENTRY_BULLET_RIGHT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	bottom = new Sprite(spriteHandler, image, SENTRY_BULLET_BOTTOM, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	topleft = new Sprite(spriteHandler, image, SENTRY_BULLET_TOPLEFT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	topright = new Sprite(spriteHandler, image, SENTRY_BULLET_TOPRIGHT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	bottomleft = new Sprite(spriteHandler, image, SENTRY_BULLET_BOTTOMLEFT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
	bottomright = new Sprite(spriteHandler, image, SENTRY_BULLET_BOTTOMRIGHT, SENTRY_BULLET_WIDTH, SENTRY_BULLET_HEIGHT, SENTRY_BULLET_SPRITE_COUNT, SPRITE_PER_ROW);
}

void SentryBullet::Update(float t)
{
	if (!isActive)
		return;

	// Va chạm của Sentry_Bullet đối với Samus
	if (manager->samus->isSamusImmortal() == false)
	{
		float TimeScale = SweptAABB(manager->samus, t);
		if (TimeScale < 1.0f)
		{
			manager->samus->TakeDamage(this->damage);
			manager->samus->setSamusImmortal(true);
		}
	}
	else
	{
		manager->samus->setImmortalTime(manager->samus->getImmortalTime() - t);
		if (manager->samus->getImmortalTime() <= 0)
		{
			manager->samus->setSamusImmortal(false);
			float temp = SAMUS_IMMORTAL_TIME;
			manager->samus->setImmortalTime(temp);
		}
	}

	// Xử lý va chạm
	for (int i = 0; i < manager->colFloorBrick->size; i++)
	{
		float timeScale = SweptAABB(manager->colFloorBrick->objects[i], t);
		if (timeScale < 1.0f)
			Reset();
	}

	//
	// Update bullet status
	//
	switch (direction)
	{
	case ON_LEFT:
		isActive = true;
		vx = -SPEED;
		vy = 0;
		break;
	case ON_RIGHT:
		isActive = true;
		vx = SPEED;
		vy = 0;
		break;
	case ON_UP:
		isActive = true;
		vy = SPEED;
		vx = 0;
		break;
	case ON_BOTTOM:
		isActive = true;
		vy = -SPEED;
		vx = 0;
		break;
	case ON_TOPLEFT:
		isActive = true;
		vy = SPEED;
		vx = -SPEED;
		break;
	case ON_TOPRIGHT:
		isActive = true;
		vy = SPEED;
		vx = SPEED;
		break;
	case ON_BOTTOMLEFT:
		isActive = true;
		vy = -SPEED;
		vx = -SPEED;
		break;
	case ON_BOTTOMRIGHT:
		isActive = true;
		vy = -SPEED;
		vx = SPEED;
		break;
	case NONE:
		isActive = false;
		vx = 0;
		vy = 0;
		break;
	}

	pos_x += vx*t;
	pos_y += vy*t;
}

void SentryBullet::Render()
{
	if (isActive)
	{
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		switch (direction)
		{
		case ON_LEFT:
			left->Render(pos_x, pos_y);
			break;
		case ON_RIGHT:
			right->Render(pos_x, pos_y);
			break;
		case ON_UP:
			up->Render(pos_x, pos_y);
			break;
		case ON_BOTTOM:
			bottom->Render(pos_x, pos_y);
			break;
		case ON_TOPLEFT:
			topleft->Render(pos_x, pos_y);
			break;
		case ON_TOPRIGHT:
			topright->Render(pos_x, pos_y);
			break;
		case ON_BOTTOMLEFT:
			bottomleft->Render(pos_x, pos_y);
			break;
		case ON_BOTTOMRIGHT:
			bottomright->Render(pos_x, pos_y);
			break;
		}
		spriteHandler->End();
	}
}

void SentryBullet::Shoot(BULLET_DIRECTION dir, float posX, float posY)
{
	direction = dir;	//cái này xem như set active
	isActive = true;
	pos_x = posX;
	pos_y = posY;
}
