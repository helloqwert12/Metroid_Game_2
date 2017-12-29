#include "Ridley.h"
#include "World.h"
#include "GroupObject.h"
#include "BulletManager.h"

Ridley::Ridley(LPD3DXSPRITE spriteHandler, World * manager)
{
	this->spriteHandler = spriteHandler;
	this->manager = manager;
	this->isActive = true;

	fly = new Sprite(spriteHandler, BOSS_SPRITE_PATH, RIDLEY_FLY_PATH, RIDLEY_WIDTH, RIDLEY_HEIGHT, RIDLEY_SPRITE_COUNT, SPRITE_PER_ROW);

	//--TO DO: Khởi tạo collider cho Ridley
	collider = new Collider();
	collider->SetCollider(0, 0, -RIDLEY_HEIGHT, RIDLEY_WIDTH);
}

Ridley::~Ridley()
{
	delete(fly);
}

void Ridley::Update(float t)
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
	if (now - last_time > 1000 / 2)
	{
		manager->ridleyBoomerang->Next(ON_RIGHT, pos_x, pos_y);
		fly->Next();
		last_time = now;
	}

	// --TO DO: Xử lý va chạm
	// ...
	// Khi cần xử lý va chạm, gọi groupCollision ở world
	//	
}

void Ridley::Render()
{
	// Nếu không active thì không render
	if (!isActive)
		return;

	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	fly->Render(pos_x, pos_y);
	spriteHandler->End();
}
