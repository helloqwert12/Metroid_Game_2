#include "Bomb.h"
#include "World.h"
#include "GroupObject.h"
#include "Metroid.h"

void Bomb::Render()
{
	if (!isActive)
		return;

	else
	{
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		bomb->Render(pos_x, pos_y);
		spriteHandler->End();
	}
}

Bomb::Bomb(LPD3DXSPRITE spriteHandler, World * manager)
{
	bomb = NULL;
	limit_dist_x = 0;
	limit_dist_y = 0;
	isActive = false;
	this->damage = DAMAGE_SAMUS_BOMB;
	this->time_exist = TIME_BOMB_EXIST;
	this->bulletType = BOMB;
	this->spriteHandler = spriteHandler;
	this->manager = manager;
	collider = new Collider(BOMB_HEIGHT / 2, -BOMB_WIDTH / 2, -BOMB_HEIGHT / 2, BOMB_WIDTH / 2);
}

Bomb::Bomb(LPD3DXSPRITE spriteHandler, World * manager, int x_holder, int y_holder)
{
	bomb = NULL;
	limit_dist_x = 0;
	limit_dist_y = 0;
	isActive = false;
	this->manager = manager;
	this->damage = DAMAGE_SAMUS_BOMB;
	this->time_exist = TIME_BOMB_EXIST;
	this->bulletType = BOMB;
	this->spriteHandler = spriteHandler;
	pos_x_holder = x_holder;
	pos_y_holder = y_holder;
	collider = new Collider(BOMB_HEIGHT / 2, -BOMB_WIDTH / 2, -BOMB_HEIGHT / 2, BOMB_WIDTH / 2);
}


Bomb::~Bomb()
{
	delete(bomb);
}

void Bomb::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &spriteHandler);
	if (result != D3D_OK) return;

	//Create sprite
	bomb = new Sprite(spriteHandler, BOMB_SPRITE_PATH, BOMB_SPRITE, BOMB_WIDTH, BOMB_HEIGHT, BOMB_COUNT, SPRITE_PER_ROW);
	time_exist = TIME_BOMB_EXIST;

}
void Bomb::InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 image)
{
	//Create sprite
	bomb = new Sprite(spriteHandler, BOMB_SPRITE_PATH, BOMB_SPRITE, BOMB_WIDTH, BOMB_HEIGHT, BOMB_COUNT, SPRITE_PER_ROW);
}

void Bomb::Update(float t)
{
	if (!isActive)
		return;

	// Xử lý va chạm
	if (!(manager->metroid->isOnFloor))
	{
		for (int i = 0; i < manager->colGroundBrick->size; i++)
		{
			float timeScale = SweptAABB(manager->colGroundBrick->objects[i], t);
			if (timeScale < 1.0f)
			{
				SlideFromGround(manager->colGroundBrick->objects[i], t, timeScale);
				Reset();
			}
		}
	}

	if ((manager->metroid->isOnFloor))
	{
		for (int i = 0; i < manager->colFloorBrick->size; i++)
		{
			float timeScale = SweptAABB(manager->colFloorBrick->objects[i], t);
			if (timeScale < 1.0f)
			{
				SlideFromGround(manager->colGroundBrick->objects[i], t, timeScale);
				Reset();
			}
		}
	}

	time_exist -= t;
	// Nếu hết thời gian thì không hiển thị nữa
	if (time_exist <= 0)
	{
		manager->explsEffect->Init(this->pos_x, this->pos_y);
		collider->SetCollider(BOMB_HEIGHT * 3, -BOMB_WIDTH * 3, -BOMB_HEIGHT * 3, BOMB_WIDTH * 3);
		for (int i = 0; i < manager->enemyGroup->size; i++)
		{
			if (manager->enemyGroup->objects[i]->IsActive())
			{
				float timeScale = SweptAABB(manager->enemyGroup->objects[i], t);
				if (timeScale < 1.0f)
				{
					manager->enemyGroup->objects[i]->isHit = true;
					switch (manager->enemyGroup->objects[i]->GetType())
					{
					case BEDGEHOG_YELLOW:
					{
						Bedgehog * hog_yellow = (Bedgehog*)manager->enemyGroup->objects[i];
						switch (getBulletType())
						{
							hog_yellow->TakeDamage(this->damage); break;
						}
					}
					break;
					case BEDGEHOG_PINK:
					{
						Bedgehog * hog_pink = (Bedgehog*)manager->enemyGroup->objects[i];
						switch (getBulletType())
						{
							hog_pink->TakeDamage(this->damage); break;
						}
					}
					break;
					case BIRD:
					{
						Bird * bird = (Bird*)manager->enemyGroup->objects[i];
						switch (getBulletType())
						{
							bird->TakeDamage(this->damage); break;
						}
					}
					break;
					case BEE:
					{
						Bee * bee = (Bee*)manager->enemyGroup->objects[i];
						switch (getBulletType())
						{
							bee->TakeDamage(this->damage); break;

						}
					}
					break;
					case RIDLEY:
					{
						Ridley * ridley = (Ridley*)manager->enemyGroup->objects[i];
						switch (getBulletType())
						{
							ridley->TakeDamage(this->damage); break;
						}
					}
					break;
					case MOTHER_BRAIN:
					{
						MotherBrain * motherBrain = (MotherBrain*)manager->enemyGroup->objects[i];
						switch (getBulletType())
						{
							motherBrain->TakeDamage(this->damage); break;
						}
					}
					break;
					case BLOCK:
						break;
					}
					Reset();
				}
			}
		}
		Game::gameSound->playSound(BOMB_EXPLOSION);
		isActive = false;
	}

	DWORD now = GetTickCount();
	if (now - last_time > 1000 / 10)
	{
		bomb->Next();
		last_time = now;
	}
}