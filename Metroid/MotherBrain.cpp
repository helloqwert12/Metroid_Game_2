﻿#include "MotherBrain.h"


MotherBrain::MotherBrain(LPD3DXSPRITE spriteHandler, World * manager)
{
	this->spriteHandler = spriteHandler;
	this->manager = manager;
	this->isActive = true;

	health = HEALTH_MOTHER_BRAIN;

	unbroken = new Sprite(spriteHandler, BOSS_SPRITE_PATH, MOTHER_BRAIN_UNBROKEN_PATH, MOTHER_BRAIN_WIDTH, MOTHER_BRAIN_HEIGHT, MOTHER_BRAIN_SPRITE_COUNT, SPRITE_PER_ROW);
	broken = new Sprite(spriteHandler, BOSS_SPRITE_PATH, MOTHER_BRAIN_BROKEN_PATH, MOTHER_BRAIN_WIDTH, MOTHER_BRAIN_HEIGHT, MOTHER_BRAIN_SPRITE_COUNT, SPRITE_PER_ROW);

	//--TO DO: Khởi tạo collider cho Mother Brain
	collider = new Collider();
	collider->SetCollider(0, 0, -MOTHER_BRAIN_HEIGHT, MOTHER_BRAIN_WIDTH);
}

MotherBrain::~MotherBrain()
{
	delete(unbroken);
	delete(broken);
}

void MotherBrain::Update(float t)
{
	if (!isActive) return;

	// Nếu không nằm trong Camera thì unactive
	if (!IsInCamera())
	{
		isActive = false;
		return;
	}

	pos_x += vx * t;
	pos_y += vy * t;

	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		switch (state)
		{
		case UNBROKEN:
			unbroken->Next();
			if (this->health <= HEALTH_MOTHER_BRAIN - 10) 
				state = BROKEN;
			break;
		case BROKEN:
			broken->Next();
			break;
		}
		last_time = now;
	}

	// --TO DO: Xử lý va chạm
	// ...
	// Khi cần xử lý va chạm, gọi groupCollision ở world
	//	
}

void MotherBrain::Render()
{
	// Nếu không active thì không render
	if (!isActive)
		return;
	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	switch (state)
	{
	case UNBROKEN:
		unbroken->Render(pos_x, pos_y);
		break;
	case BROKEN:
		broken->Render(pos_x, pos_y);
		break;
	}
	spriteHandler->End();
}
