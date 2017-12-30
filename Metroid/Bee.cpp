#include "Bee.h"
#include "World.h"
#include "GroupObject.h"

Bee::Bee()
{
}

Bee::Bee(LPD3DXSPRITE spriteHandler, World * manager, ENEMY_TYPE enemy_type) : Enemy(spriteHandler, manager)
{
	this->enemy_type = enemy_type;
	this->isActive = true;

	//Khởi tạo sprites
	this->InitSprites();

	collider = new Collider();
	collider->SetCollider(0, 0, -BEE_HEIGHT, BEE_WIDTH);

	// collider dùng khi samus đi vào vùng va chạm thì BEE bắt đầu bay (Chưa làm)
	collider_area = new Collider();
	collider_area->SetCollider(0, -width, -480, width * 2);
}


Bee::~Bee()
{
	delete(fly);
}

void Bee::InitSprites()
{
	char  *fly_path = NULL;
	switch (enemy_type)
	{
	case BEE:
		fly_path = BEE_FLY;
		break;
	}

	// Khởi tạo sprite
	fly = new Sprite(spriteHandler, ENEMY_SPRITE_PATH, fly_path, BEE_WIDTH, BEE_HEIGHT, BEE_FLY_SPRITE_COUNT, 1);
}
void Bee::Update(float t)
{
	if (!isActive) return;

	// Nếu không nằm trong Camera thì unactive
	if (!IsInCamera())
	{
		isActive = false;
		return;
	}

	//// khi samus đi vào vùng va chạm (chưa làm)
	//if (this->IsCollide(manager->samus) == true)
	//{
	//	vy = -0.1f;
	//	if (pos_x < manager->samus->GetPosX())
	//	{
	//		vx = 0.05f;
	//	}
	//	else
	//	{
	//		vx = -0.05f;
	//	}
	//}

	for (int i = 0; i < manager->quadtreeGroup->size; i++)
	{
		switch (manager->quadtreeGroup->objects[i]->GetType())
		{
		case BRICK:
			float timeScale = SweptAABB(manager->quadtreeGroup->objects[i], t);
			if (timeScale < 1.0f)
			{
				SlideFromGround(manager->quadtreeGroup->objects[i], t, timeScale);
				this->Destroy();
			}
			break;
		}
	}

	/*float scaletime = SweptAABB(manager->samus, t);
	if (scaletime < 1.0f)
	{
	Deflect(manager->samus, t, scaletime);
	}*/

	pos_x += vx * t;
	pos_y += vy * t;

	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		fly->Next();
		last_time = now;
	}

	// --TO DO: Xử lý va chạm
	// ...
	// Khi cần xử lý va chạm, gọi groupCollision ở world
	//	
}

void Bee::Render()
{
	// Nếu không active thì không render
	if (!isActive)
		return;
	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	fly->Render(pos_x, pos_y);
	spriteHandler->End();
}

bool Bee::IsCollide(GameObject * target)
{
	if (target->GetCollider() == NULL || this->collider_area == NULL)
		return false;
	if (pos_x + collider_area->GetRight() < target->GetPosX())
		return false;
	// Kiểm tra phía trên
	if (pos_y + collider_area->GetBottom() > target->GetPosY())
		return false;
	// Kiểm tra bên phải
	if (pos_x > target->GetPosX() + target->GetCollider()->GetRight())
		return false;
	// Kiểm tra phía dưới
	if (pos_y < target->GetPosY() - target->GetCollider()->GetBottom())
		return false;
	return true;
}