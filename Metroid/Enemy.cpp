#include "Enemy.h"
#include "Game.h"
#include "World.h"
#include "ExplosionEffect.h"
#include <time.h>
#include "MissileItem.h"
#include "EnergyItem.h"

Enemy::Enemy()
{
	width = 16;
	height = 16;
}

Enemy::Enemy(LPD3DXSPRITE spriteHandler, World * manager)
{
	this->spriteHandler = spriteHandler;
	this->manager = manager;

	//Set type
	this->type = ENEMY;
}


Enemy::~Enemy()
{
}
void Enemy::InitPostition()
{
	
}
void Enemy::InitPostition(int x, int y)
{
	this->pos_x = x;
	this->pos_y = y;
}

void Enemy::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &spriteHandler);
	if (result != D3D_OK) return;
}
ENEMY_TYPE Enemy::GetEnemyType()
{
	return enemy_type;
}
void Enemy::SetEnemyType(ENEMY_TYPE enemy_type)
{
	this->enemy_type = enemy_type;
}
void Enemy::Update(float t)
{
}

void Enemy::TakeDamage(float damage)
{
	health -= damage;
	Game::gameSound->playSound(BULLET_HIT_ENEMY);

	if (health <= 0)
	{
		//manager->explsEffect->Init(this->pos_x, this->pos_y);	 // Xảy ra lỗi khi giết những mục tiêu to (Ridley, Mother Brain)
		Destroy();
	}
}

void Enemy::Destroy()
{
	int random;

	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number between 1 and 10: */
	random = rand() % 5 + 1;

	if (random == 1 || random == 3 || random == 5)
		manager->energyItem->Init(this->pos_x, this->pos_y);
	else
	{
		manager->missileItem->Init(this->pos_x, this->pos_y);
	}

	this->isActive = false;
}

void Enemy::Render()
{
}

void Enemy::HandleCollision()
{
}

