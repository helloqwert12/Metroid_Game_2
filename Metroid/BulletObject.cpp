﻿#include "BulletObject.h"
#include "World.h"
#include "GroupObject.h"


BulletObject::BulletObject()
{
}

BulletObject::BulletObject(World * manager)
{
	this->manager = manager;
}

BulletObject::~BulletObject()
{
}

void BulletObject::InitPosition(int posX, int posY)
{
	pos_x = posX;
	pos_y = posY;

	pos_x_holder = posX;
	pos_y_holder = posY;

	direction = NONE;
}

void BulletObject::ResetPosition()
{
	pos_x = pos_x_holder;
	pos_y = pos_y_holder;
}

void BulletObject::Reset()
{
	//Ngung render
	isActive = false;

	//Reset vi tri
	ResetPosition();

	//Reset distance
	limit_dist_x = 0;
	limit_dist_y = 0;

	//Set direction to NONE
	direction = NONE;
}

BULLET_DIRECTION BulletObject::GetDirection()
{
	return direction;
}

void BulletObject::SetDirection(BULLET_DIRECTION value)
{
	direction = value;
}

void BulletObject::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
}

void BulletObject::Update(float t)
{
	if (!isActive)
		return;

	// Xử lý va chạm
	for (int i = 0; i < manager->quadtreeGroup->size; i++)
	{
		switch (manager->quadtreeGroup->objects[i]->GetType())
		{
		case BRICK:
			float timeScale = SweptAABB(manager->quadtreeGroup->objects[i], t);
			if (timeScale < 1.0f)
			{
				Reset();
			}
			break;
		}
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
	case NONE:
		isActive = false;
		vx = 0;
		vy = 0;
		break;
	}

	pos_x += vx*t;
	pos_y += vy*t;

	int temp_x = vx*t;
	int temp_y = vy*t;

	if (temp_x < 0)
		temp_x = -temp_x;
	if (temp_y < 0)
		temp_y = -temp_y;

	limit_dist_x += temp_x;
	limit_dist_y += temp_y;


	//Check if the bullet reach the limit
	if (limit_dist_x >= LIMIT_DISTANCE || limit_dist_y >= LIMIT_DISTANCE)
	{
		Reset();
	}

	//Update position of samus
	//pos_x_holder = posX;
	//pos_y_holder = posY;
}

void BulletObject::Render()
{

}

void BulletObject::Shoot(BULLET_DIRECTION dir)
{
	direction = dir;	//cái này xem như set active
	isActive = true;
	pos_x = pos_x_holder;
	pos_y = pos_y_holder;
}

void BulletObject::Shoot(BULLET_DIRECTION dir, float posX, float posY)
{
	direction = dir;	//cái này xem như set active
	isActive = true;
	pos_x = posX;
	pos_y = posY;
}
