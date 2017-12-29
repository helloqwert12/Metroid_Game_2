#include "RidleyBoomerang.h"
#include "World.h"
#include "GroupObject.h"

RidleyBoomerang::RidleyBoomerang(World * manager)
{
	this->manager = manager;
	right = NULL;

	limit_dist_x = 0;
	limit_dist_y = 0;
	isActive = false;
}

RidleyBoomerang::~RidleyBoomerang()
{
	delete(right);
}

void RidleyBoomerang::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &_SpriteHandler);
	if (result != D3D_OK) return;

	//Create sprite
	right = new Sprite(_SpriteHandler, RIDLEY_BOOMERANG_SPIRTE_PATH, RIDLEY_BOOMERANG_PATH, RIDLEY_BOOMERANG_WIDTH, RIDLEY_BOOMERANG_HEIGHT, RIDLEY_BOOMERANG_SPRITE_COUNT, SPRITE_PER_ROW);

}

void RidleyBoomerang::Update(float t)
{
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
	case ON_RIGHT:
		isActive = true;
		vx = SPEED;
		vy = 0;
		break;
	}

	pos_x += vx * t;
	pos_y += vy * t;

	int temp_x = vx * t;
	int temp_y = vy * t;

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
}

void RidleyBoomerang::Render()
{
	if (isActive)
	{
		_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		switch (direction)
		{
		case ON_RIGHT:
			right->Render(pos_x, pos_y);
			break;
		}
		_SpriteHandler->End();
	}
}

void RidleyBoomerang::Shoot(BULLET_DIRECTION dir, float posX, float posY)
{
	direction = dir;	//cái này xem như set active
	pos_x = posX;
	pos_y = posY;
}
