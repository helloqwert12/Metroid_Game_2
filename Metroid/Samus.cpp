﻿#include "Samus.h"
#include "Game.h"
#include <vector>
#include "GroupObject.h"
#include "World.h"
#include "trace.h"
#include "ExplosionEffect.h"
#include "Metroid.h"
#include "Brick.h"
#include "PositionManager.h"
#include "ColliderBrick.h"
#include "EnergyItem.h"
#include "MissileItem.h"
#include "MorphItem.h"
#include "utils.h"

void Samus::Render()
{	
	// Nếu không active thì không render
	if (!isActive)
		return;

	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	if (immortal_time == 4000.0f) // Do SAMUS_IMMORTAL_TIME = 4000.0f
	{
		switch (state)
		{
		case APPEARANCE:
			appearing->Render(pos_x, pos_y);
			break;
		case RIGHTING:
			running_right->Render(pos_x, pos_y);
			break;
		case LEFTING:
			running_left->Render(pos_x, pos_y);
			break;
		case AIMING_UP_LEFT:
			run_aim_up_left->Render(pos_x, pos_y);
			break;
		case AIMING_UP_RIGHT:
			run_aim_up_right->Render(pos_x, pos_y);
			break;
		case IDLING_AIM_UP_LEFT:
			idle_aim_up_left->Render(pos_x, pos_y);
			break;
		case IDLING_AIM_UP_RIGHT:
			idle_aim_up_right->Render(pos_x, pos_y);
			break;
		case IDLE_LEFT:
			idle_left->Render(pos_x, pos_y);
			break;
		case IDLE_RIGHT:
			idle_right->Render(pos_x, pos_y);
			break;
		case ON_MORPH_LEFT:
			morph_ball_left->Render(pos_x, pos_y);
			break;
		case ON_MORPH_RIGHT:
			morph_ball_right->Render(pos_x, pos_y);
			break;
		case ON_RUN_SHOOTING_LEFT:
			run_shooting_left->Render(pos_x, pos_y);
			break;
		case ON_RUN_SHOOTING_RIGHT:
			run_shooting_right->Render(pos_x, pos_y);
			break;
		case ON_JUMP_LEFT:
			jump_left->Render(pos_x, pos_y);
			break;
		case ON_JUMP_RIGHT:
			jump_right->Render(pos_x, pos_y);
			break;
		case ON_SOMERSAULT_LEFT:
			somersault_left->Render(pos_x, pos_y);
			break;
		case ON_SOMERSAULT_RIGHT:
			somersault_right->Render(pos_x, pos_y);
			break;
		case ON_JUMPING_SHOOTING_LEFT:
			jumping_shooting_left->Render(pos_x, pos_y);
			break;
		case ON_JUMPING_SHOOTING_RIGHT:
			jumping_shooting_right->Render(pos_x, pos_y);
			break;
		case ON_JUMP_AIM_UP_LEFT:
			jump_aim_up_left->Render(pos_x, pos_y);
			break;
		case ON_JUMP_AIM_UP_RIGHT:
			jump_aim_up_right->Render(pos_x, pos_y);
			break;
		case IDLING_SHOOTING_LEFT:
			idle_shooting_left->Render(pos_x, pos_y);
			break;
		case IDLING_SHOOTING_RIGHT:
			idle_shooting_right->Render(pos_x, pos_y);
			break;
		case IDLING_SHOOTING_UP_LEFT:
			idle_shooting_up_left->Render(pos_x, pos_y);
			break;
		case IDLING_SHOOTING_UP_RIGHT:
			idle_shooting_up_right->Render(pos_x, pos_y);
			break;
		case ON_JUMP_SHOOTING_UP_LEFT:
			jump_shooting_up_right->Render(pos_x, pos_y);
			break;
		case ON_JUMP_SHOOTING_UP_RIGHT:
			jump_shooting_up_right->Render(pos_x, pos_y);
			break;
		}
	}
	else
	{
		D3DXCOLOR color;
		color.r = 127; color.g = 127; color.b = 127;

		switch (state)
		{
		case APPEARANCE:
			appearing->Render(pos_x, pos_y, color);
			break;
		case RIGHTING:
			running_right->Render(pos_x, pos_y, color);
			break;
		case LEFTING:
			running_left->Render(pos_x, pos_y, color);
			break;
		case AIMING_UP_LEFT:
			run_aim_up_left->Render(pos_x, pos_y, color);
			break;
		case AIMING_UP_RIGHT:
			run_aim_up_right->Render(pos_x, pos_y, color);
			break;
		case IDLING_AIM_UP_LEFT:
			idle_aim_up_left->Render(pos_x, pos_y, color);
			break;
		case IDLING_AIM_UP_RIGHT:
			idle_aim_up_right->Render(pos_x, pos_y, color);
			break;
		case IDLE_LEFT:
			idle_left->Render(pos_x, pos_y, color);
			break;
		case IDLE_RIGHT:
			idle_right->Render(pos_x, pos_y, color);
			break;
		case ON_MORPH_LEFT:
			morph_ball_left->Render(pos_x, pos_y, color);
			break;
		case ON_MORPH_RIGHT:
			morph_ball_right->Render(pos_x, pos_y, color);
			break;
		case ON_RUN_SHOOTING_LEFT:
			run_shooting_left->Render(pos_x, pos_y, color);
			break;
		case ON_RUN_SHOOTING_RIGHT:
			run_shooting_right->Render(pos_x, pos_y, color);
			break;
		case ON_JUMP_LEFT:
			jump_left->Render(pos_x, pos_y, color);
			break;
		case ON_JUMP_RIGHT:
			jump_right->Render(pos_x, pos_y, color);
			break;
		case ON_SOMERSAULT_LEFT:
			somersault_left->Render(pos_x, pos_y, color);
			break;
		case ON_SOMERSAULT_RIGHT:
			somersault_right->Render(pos_x, pos_y, color);
			break;
		case ON_JUMPING_SHOOTING_LEFT:
			jumping_shooting_left->Render(pos_x, pos_y, color);
			break;
		case ON_JUMPING_SHOOTING_RIGHT:
			jumping_shooting_right->Render(pos_x, pos_y, color);
			break;
		case ON_JUMP_AIM_UP_LEFT:
			jump_aim_up_left->Render(pos_x, pos_y, color);
			break;
		case ON_JUMP_AIM_UP_RIGHT:
			jump_aim_up_right->Render(pos_x, pos_y, color);
			break;
		case IDLING_SHOOTING_LEFT:
			idle_shooting_left->Render(pos_x, pos_y, color);
			break;
		case IDLING_SHOOTING_RIGHT:
			idle_shooting_right->Render(pos_x, pos_y, color);
			break;
		case IDLING_SHOOTING_UP_LEFT:
			idle_shooting_up_left->Render(pos_x, pos_y, color);
			break;
		case IDLING_SHOOTING_UP_RIGHT:
			idle_shooting_up_right->Render(pos_x, pos_y, color);
			break;
		case ON_JUMP_SHOOTING_UP_LEFT:
			jump_shooting_up_right->Render(pos_x, pos_y, color);
			break;
		case ON_JUMP_SHOOTING_UP_RIGHT:
			jump_shooting_up_right->Render(pos_x, pos_y, color);
			break;
		}
	}
	
	
	spriteHandler->End();
}

//void Samus::RenderDebug(LPDIRECT3DDEVICE9 d3ddv)
//{
//	Render();
//	DrawCollider(d3ddv, this->pos_x, this->pos_y, this->collider, D3DCOLOR_ARGB(0, 255, 0, 0));
//}

void Samus::Destroy()
{
	//Ngưng active
	isActive = false;
	Game::gameSound->stopSound(BACKGROUND_MAP);
	Game::gameSound->playSound(BACKGROUND_SAMUS_DEATH);
	manager->explsEffect->Init(pos_x, pos_y);
	
	isDeath = true;
	//--TO DO: Đưa Samus ra khỏi viewport

}

void Samus::TakeDamage(float damage)
{
	health -= damage;
	Game::gameSound->playSound(SAMUS_HIT_ENEMY);

	//int randomX = rand() % 32 - 16;
	//int randomY = rand() % 32 - 16;
	//Effect* newEffect = Effect::CreateEffect(EFFECT_HIT, this->postX + randomX, this->postY + randomY, 1, spriteHandler, manager);
	//manager->groupEffect->AddObject(newEffect);

	if (health <= 0)
		Destroy();
}

void Samus::SetHealth(float value)
{
	health = value;
}

float Samus::GetHealth()
{
	return health;
}

int Samus::GetMissileNumbers()
{
	return missile_numbers;
}

void Samus::SetMissileNumbers(int num)
{
	missile_numbers = num;
}

Samus::Samus()
{
	appearing = NULL;
	running_left = NULL;
	running_right = NULL;
	jump_left = NULL;
	jump_right = NULL;

	width = 28;
	height = 64;

	immortal_time = SAMUS_IMMORTAL_TIME;
	isImmortal = false;

	collider = new Collider();
	collider->SetCollider(0, 0, -this->height, this->width);
	this->isActive = true;
	state = APPEARANCE;
}

Samus::Samus(LPD3DXSPRITE spriteHandler, World * manager)
{
	this->spriteHandler = spriteHandler;
	this->manager = manager;
	this->isActive = true;
	this->isDeath = false;
	this->isMorph = false;
	//Set type
	this->type = SAMUS;

	// Khởi tạo máu cho Samus
	health = HEALTH_SAMUS;

	width = 28;
	height = 50;

	immortal_time = SAMUS_IMMORTAL_TIME;
	isImmortal = false;

	missile_numbers = 10; // set số lượng missile ban đầu

	//Collider
	this->collider = new Collider();
	this->collider->SetCollider(0, 0, -this->height, this->width);
	state = APPEARANCE;
	gravity = FALLDOWN_VELOCITY_DECREASE;
}


Samus::~Samus()
{
	delete(appearing);
	delete(running_left);
	delete(running_right);
	delete(jump_left);
	delete(jump_right);
	delete(run_shooting_left);
	delete(run_shooting_right);
	delete(run_aim_up_left);
	delete(run_aim_up_right);
	delete(idle_aim_up_left);
	delete(idle_aim_up_right);
	delete(idle_left);
	delete(idle_right);
	delete(morph_ball_left);
	delete(morph_ball_right);
	delete(somersault_left);
	delete(somersault_right);
	delete(jumping_shooting_left);
	delete(jumping_shooting_right);
	delete(jump_aim_up_left);
	delete(jump_aim_up_right);
	delete(collider);
	delete(idle_shooting_left);
	delete(idle_shooting_right);
	delete(idle_shooting_up_left);
	delete(idle_shooting_up_right);
	delete(jump_shooting_up_left);
	delete(jump_shooting_up_right);
}

//DirectCollision Samus::getDirection()
//{
//	return this->direction;
//}
//void Samus::setDirection(DirectCollision direction)
//{
//	this->direction = direction;
//}


void Samus::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	LPDIRECT3DTEXTURE9 image = LoadTexture(SAMUS_SPRITES_PATH, spriteHandler);

	//Create instance of sprites
	/*appearing = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, APPEARING, APPEARING_WIDTH, APPEARING_HEIGHT, APPEARING_COUNT, SPRITE_PER_ROW);
	running_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, RUNNING_LEFT, RUNNING_WIDTH, RUNNING_HEIGHT, RUNNING_COUNT, SPRITE_PER_ROW);
	running_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, RUNNING_RIGHT, RUNNING_WIDTH, RUNNING_HEIGHT, RUNNING_COUNT, SPRITE_PER_ROW);
	jump_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, JUMP_LEFT, JUMP_WIDTH, JUMP_HEIGHT, JUMP_COUNT, SPRITE_PER_ROW);
	jump_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, JUMP_RIGHT, JUMP_WIDTH, JUMP_HEIGHT, JUMP_COUNT, SPRITE_PER_ROW);
	run_shooting_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, RUN_SHOOTING_LEFT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
	run_shooting_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, RUN_SHOOTING_RIGHT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
	run_aim_up_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, RUN_AIM_UP_LEFT, RUN_AIM_UP_WIDTH, RUN_AIM_UP_HEIGHT, RUN_AIM_UP_COUNT, SPRITE_PER_ROW);
	run_aim_up_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, RUN_AIM_UP_RIGHT, RUN_AIM_UP_WIDTH, RUN_AIM_UP_HEIGHT, RUN_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_aim_up_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, IDLE_AIM_UP_LEFT, IDLE_AIM_UP_WIDTH, IDLE_AIM_UP_HEIGHT, IDLE_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_aim_up_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, IDLE_AIM_UP_RIGHT, IDLE_AIM_UP_WIDTH, IDLE_AIM_UP_HEIGHT, IDLE_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, STANDING_LEFT, STANDING_WIDTH, STANDING_HEIGHT, STANDING_COUNT, SPRITE_PER_ROW);
	idle_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, STANDING_RIGHT, STANDING_WIDTH, STANDING_HEIGHT, STANDING_COUNT, SPRITE_PER_ROW);
	morph_ball_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, MORPH_BALL_LEFT, MORPH_BALL_WIDTH, MORPH_BALL_HEIGHT, MORPH_BALL_COUNT, SPRITE_PER_ROW);
	morph_ball_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, MORPH_BALL_RIGHT, MORPH_BALL_WIDTH, MORPH_BALL_HEIGHT, MORPH_BALL_COUNT, SPRITE_PER_ROW);
	somersault_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, SOMERSAULT_LEFT, SOMERSAULT_WIDTH, SOMERSAULT_HEIGHT, SOMERSAULT_COUNT, SPRITE_PER_ROW);
	somersault_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, SOMERSAULT_RIGHT, SOMERSAULT_WIDTH, SOMERSAULT_HEIGHT, SOMERSAULT_COUNT, SPRITE_PER_ROW);
	jumping_shooting_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, JUMPING_SHOOTING_LEFT, JUMPING_SHOOTING_WIDTH, JUMPING_SHOOTING_HEIGHT, JUMPING_SHOOTING_COUNT, SPRITE_PER_ROW);
	jumping_shooting_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, JUMPING_SHOOTING_RIGHT, JUMPING_SHOOTING_WIDTH, JUMPING_SHOOTING_HEIGHT, JUMPING_SHOOTING_COUNT, SPRITE_PER_ROW);
	jump_aim_up_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, JUMP_AIM_UP_LEFT, JUMP_AIM_UP_WIDTH, JUMP_AIM_UP_HEIGHT, JUMP_AIM_UP_COUNT, SPRITE_PER_ROW);
	jump_aim_up_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, JUMP_AIM_UP_RIGHT, JUMP_AIM_UP_WIDTH, JUMP_AIM_UP_HEIGHT, JUMP_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_shooting_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, STAND_SHOOTING_LEFT, STANDING_SHOOTING_WIDTH, STANDING_SHOOTING_HEIGHT, STAND_SHOOTING_COUNT, SPRITE_PER_ROW);
	idle_shooting_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, STAND_SHOOTING_RIGHT, STANDING_SHOOTING_WIDTH, STANDING_SHOOTING_HEIGHT, STAND_SHOOTING_COUNT, SPRITE_PER_ROW);
	idle_shooting_up_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, STAND_SHOOTING_UP_LEFT, STANDING_SHOOTING_UP_WIDTH, STANDING_SHOOTING_UP_HEIGHT, STAND_SHOOTING_UP_COUNT, SPRITE_PER_ROW);
	idle_shooting_up_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, STAND_SHOOTING_UP_RIGHT, STANDING_SHOOTING_UP_WIDTH, STANDING_SHOOTING_UP_HEIGHT, STAND_SHOOTING_UP_COUNT, SPRITE_PER_ROW);
	jump_shooting_up_left = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, JUMP_SHOOTING_UP_LEFT, JUMP_SHOOTING_UP_WIDTH, JUMP_SHOOTING_UP_HEIGHT, JUMP_SHOOTING_UP_COUNT, SPRITE_PER_ROW);
	jump_shooting_up_right = new Sprite(spriteHandler, SAMUS_SPRITES_PATH, JUMP_SHOOTING_UP_RIGHT, JUMP_SHOOTING_UP_WIDTH, JUMP_SHOOTING_UP_HEIGHT, JUMP_SHOOTING_UP_COUNT, SPRITE_PER_ROW);*/

	appearing = new Sprite(spriteHandler, image, APPEARING, APPEARING_WIDTH, APPEARING_HEIGHT, APPEARING_COUNT, SPRITE_PER_ROW);
	running_left = new Sprite(spriteHandler, image, RUNNING_LEFT, RUNNING_WIDTH, RUNNING_HEIGHT, RUNNING_COUNT, SPRITE_PER_ROW);
	running_right = new Sprite(spriteHandler, image, RUNNING_RIGHT, RUNNING_WIDTH, RUNNING_HEIGHT, RUNNING_COUNT, SPRITE_PER_ROW);
	jump_left = new Sprite(spriteHandler, image, JUMP_LEFT, JUMP_WIDTH, JUMP_HEIGHT, JUMP_COUNT, SPRITE_PER_ROW);
	jump_right = new Sprite(spriteHandler, image, JUMP_RIGHT, JUMP_WIDTH, JUMP_HEIGHT, JUMP_COUNT, SPRITE_PER_ROW);
	run_shooting_left = new Sprite(spriteHandler, image, RUN_SHOOTING_LEFT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
	run_shooting_right = new Sprite(spriteHandler, image, RUN_SHOOTING_RIGHT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
	run_aim_up_left = new Sprite(spriteHandler, image, RUN_AIM_UP_LEFT, RUN_AIM_UP_WIDTH, RUN_AIM_UP_HEIGHT, RUN_AIM_UP_COUNT, SPRITE_PER_ROW);
	run_aim_up_right = new Sprite(spriteHandler, image, RUN_AIM_UP_RIGHT, RUN_AIM_UP_WIDTH, RUN_AIM_UP_HEIGHT, RUN_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_aim_up_left = new Sprite(spriteHandler, image, IDLE_AIM_UP_LEFT, IDLE_AIM_UP_WIDTH, IDLE_AIM_UP_HEIGHT, IDLE_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_aim_up_right = new Sprite(spriteHandler, image, IDLE_AIM_UP_RIGHT, IDLE_AIM_UP_WIDTH, IDLE_AIM_UP_HEIGHT, IDLE_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_left = new Sprite(spriteHandler, image, STANDING_LEFT, STANDING_WIDTH, STANDING_HEIGHT, STANDING_COUNT, SPRITE_PER_ROW);
	idle_right = new Sprite(spriteHandler, image, STANDING_RIGHT, STANDING_WIDTH, STANDING_HEIGHT, STANDING_COUNT, SPRITE_PER_ROW);
	morph_ball_left = new Sprite(spriteHandler, image, MORPH_BALL_LEFT, MORPH_BALL_WIDTH, MORPH_BALL_HEIGHT, MORPH_BALL_COUNT, SPRITE_PER_ROW);
	morph_ball_right = new Sprite(spriteHandler, image, MORPH_BALL_RIGHT, MORPH_BALL_WIDTH, MORPH_BALL_HEIGHT, MORPH_BALL_COUNT, SPRITE_PER_ROW);
	somersault_left = new Sprite(spriteHandler, image, SOMERSAULT_LEFT, SOMERSAULT_WIDTH, SOMERSAULT_HEIGHT, SOMERSAULT_COUNT, SPRITE_PER_ROW);
	somersault_right = new Sprite(spriteHandler, image, SOMERSAULT_RIGHT, SOMERSAULT_WIDTH, SOMERSAULT_HEIGHT, SOMERSAULT_COUNT, SPRITE_PER_ROW);
	jumping_shooting_left = new Sprite(spriteHandler, image, JUMPING_SHOOTING_LEFT, JUMPING_SHOOTING_WIDTH, JUMPING_SHOOTING_HEIGHT, JUMPING_SHOOTING_COUNT, SPRITE_PER_ROW);
	jumping_shooting_right = new Sprite(spriteHandler, image, JUMPING_SHOOTING_RIGHT, JUMPING_SHOOTING_WIDTH, JUMPING_SHOOTING_HEIGHT, JUMPING_SHOOTING_COUNT, SPRITE_PER_ROW);
	jump_aim_up_left = new Sprite(spriteHandler, image, JUMP_AIM_UP_LEFT, JUMP_AIM_UP_WIDTH, JUMP_AIM_UP_HEIGHT, JUMP_AIM_UP_COUNT, SPRITE_PER_ROW);
	jump_aim_up_right = new Sprite(spriteHandler, image, JUMP_AIM_UP_RIGHT, JUMP_AIM_UP_WIDTH, JUMP_AIM_UP_HEIGHT, JUMP_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_shooting_left = new Sprite(spriteHandler, image, STAND_SHOOTING_LEFT, STANDING_SHOOTING_WIDTH, STANDING_SHOOTING_HEIGHT, STAND_SHOOTING_COUNT, SPRITE_PER_ROW);
	idle_shooting_right = new Sprite(spriteHandler, image, STAND_SHOOTING_RIGHT, STANDING_SHOOTING_WIDTH, STANDING_SHOOTING_HEIGHT, STAND_SHOOTING_COUNT, SPRITE_PER_ROW);
	idle_shooting_up_left = new Sprite(spriteHandler, image, STAND_SHOOTING_UP_LEFT, STANDING_SHOOTING_UP_WIDTH, STANDING_SHOOTING_UP_HEIGHT, STAND_SHOOTING_UP_COUNT, SPRITE_PER_ROW);
	idle_shooting_up_right = new Sprite(spriteHandler, image, STAND_SHOOTING_UP_RIGHT, STANDING_SHOOTING_UP_WIDTH, STANDING_SHOOTING_UP_HEIGHT, STAND_SHOOTING_UP_COUNT, SPRITE_PER_ROW);
	jump_shooting_up_left = new Sprite(spriteHandler, image, JUMP_SHOOTING_UP_LEFT, JUMP_SHOOTING_UP_WIDTH, JUMP_SHOOTING_UP_HEIGHT, JUMP_SHOOTING_UP_COUNT, SPRITE_PER_ROW);
	jump_shooting_up_right = new Sprite(spriteHandler, image, JUMP_SHOOTING_UP_RIGHT, JUMP_SHOOTING_UP_WIDTH, JUMP_SHOOTING_UP_HEIGHT, JUMP_SHOOTING_UP_COUNT, SPRITE_PER_ROW);
}

void Samus::InitPostition()
{
	//--TO DO: This code will be edited soon
	pos_x = 50;
	pos_y = GROUND_Y;

	vx = 0;
	vx_last = 1.0f;
	vy = 0;

	//Init state of samus
	state = APPEARANCE;
}

int max_camera_x = 300;
int max_camera_y = 480;

int min_camera_x = 0;
int min_camera_y = 480;


SAMUS_STATE Samus::GetState()
{
	return state;
}

void Samus::SetState(SAMUS_STATE value)
{
	state = value;
}

void Samus::ResetAllSprites()
{
	appearing->Reset();
	running_left->Reset();
	running_right->Reset();
	jump_left->Reset();
	jump_right->Reset();
	run_shooting_left->Reset();
	run_shooting_right->Reset();
	run_aim_up_left->Reset();
	run_aim_up_right->Reset();
	idle_aim_up_left->Reset();
	idle_aim_up_right->Reset();
	idle_left->Reset();
	idle_right->Reset();
	morph_ball_left->Reset();
	morph_ball_right->Reset();
	somersault_left->Reset();
	somersault_right->Reset();
	jumping_shooting_left->Reset();
	jumping_shooting_right->Reset();
	jump_aim_up_left->Reset();
	jump_aim_up_right->Reset();
	idle_shooting_left->Reset();
	idle_shooting_right->Reset();
	idle_shooting_up_left->Reset();
	idle_shooting_up_right->Reset();
	jump_shooting_up_left->Reset();
	jump_shooting_up_right->Reset();
}

bool Samus::isSamusDeath()
{
	if (isDeath == true)
		return true;
	return false;
}

bool Samus::isSamusCanMorph()
{
	if (isMorph == true)
		return true;
	return false;
}

bool Samus::isSamusCrouch()
{
	if (isCrouch == true)
		return true;
	return false;
}

bool Samus::isSamusOnAir()
{
	if (isOnAir == true)
		return true;
	return false;
}

bool Samus::isSamusImmortal()
{
	if (isImmortal == true)
		return true;
	return false;
}

void Samus::setSamusImmortal(bool result)
{
	isImmortal = result;
}

float Samus::getImmortalTime()
{
	return immortal_time;
}

void Samus::setImmortalTime(float time)
{
	immortal_time = time;
}

bool Samus::GetStateActive()
{
	return isActive;
}


void Samus::Reset(int x, int y)
{
	// Cho samus active trở lại
	isActive = true;

	//Đặt lại vị trí
	this->pos_x = x;
	this->pos_y = y;
	isMorph = false;
	isDeath = false;
	manager->morphItem->Init(704, 186);
	Camera::currentCamX = 1000 - 240;
	Camera::currentCamY = 480;
	health = HEALTH_SAMUS;
}

void Samus::Update(float t)
{
	//
	// Update samus status
	//
	//GameObject::Update(t);

	vy -= gravity;
	
	//===========> Quan update - updating . . .
	for (int i = 0; i < manager->enemyGroup->size; i++)
	{	
		Enemy * enemy = (Enemy*)manager->enemyGroup->objects[i];
		if (enemy->IsActive())
		{
			if (isImmortal == false)
			{
				float timeScale = SweptAABB(enemy, t);
				if (timeScale < 1.0f)
				{
					//Xử lý khi va chạm với enemy
					if (enemy->time_freeze <= 300) // DoF ENEMY_FREEZE = 300
					{
						//if (enemy->GetEnemyType() == BEDGEHOG_YELLOW || enemy->GetEnemyType() == BEDGEHOG_PINK)
						//	enemy->GetCollider()->SetCollider(0, 0, -BEDGEHOG_HEIGHT, BEDGEHOG_WIDTH);
						//else
						//	enemy->GetCollider()->SetCollider(enemy->GetHeight() / 2, -enemy->GetWidth() / 2, -enemy->GetHeight() / 2, enemy->GetWidth() / 2);
						Deflect(enemy, t, timeScale);
						isImmortal = true;

						// xong rồi tùy con mà takedamage
						switch (enemy->GetEnemyType())
						{
						case BEDGEHOG_YELLOW:
						{// take damge cho samus, truyen vao dame cua con nay
							// co the them thuoc tinh damage cho moi con enemy de truyen vao
							// Vd: this->TakeDamage(float enemy_damage)
							Bedgehog* hog_yellow = (Bedgehog*)manager->enemyGroup->objects[i];
							TakeDamage(hog_yellow->damage);
						}
						break;
						case BEDGEHOG_PINK:
						{
							Bedgehog * hog_pink = (Bedgehog*)manager->enemyGroup->objects[i];
							TakeDamage(hog_pink->damage);
						}
						break;
						case BIRD:
						{
							Bird * bird = (Bird*)manager->enemyGroup->objects[i];
							TakeDamage(bird->damage);
							pos_y = GROUND_Y; // Set giá trị vị trí cho samus khi va chạm bird, tránh bị bug xuyên đất
						}
						break;
						case BLOCK:
						{
							Block * block = (Block*)manager->enemyGroup->objects[i];
							TakeDamage(block->damage);
						}
						break;
						case BEE:
						{
							Bee * bee = (Bee*)manager->enemyGroup->objects[i];
							TakeDamage(bee->damage);
							pos_y = GROUND_Y; // Set giá trị vị trí cho samus khi va chạm bee, tránh bị bug xuyên đất
						}
						break;
						case RIDLEY:
						{
							Ridley * ridley = (Ridley*)manager->enemyGroup->objects[i];
							TakeDamage(ridley->damage);
						}
						break;
						// ...
						}
					}
					else
					{
						if (enemy->GetEnemyType() == BEDGEHOG_YELLOW || enemy->GetEnemyType() == BEDGEHOG_PINK)
							enemy->GetCollider()->SetCollider(0, 0, -30, 32);
						else
							enemy->GetCollider()->SetCollider(enemy->GetHeight() / 2 + 10, -enemy->GetWidth() / 2, -enemy->GetHeight() / 2, enemy->GetWidth() / 2);
						SlideFromGround(enemy, t, timeScale);
					}
				}
			}
			else
			{
				immortal_time -= t;
				if (immortal_time <= 0)
				{
					isImmortal = false;
					immortal_time = SAMUS_IMMORTAL_TIME;
				}
			}
		}
	}

	//<======================

	// Xử lý va chạm với Item
	if (SweptAABB(manager->energyItem, t) < 1.0f)
	{
		if (manager->energyItem->IsActive() == true)
		{
			Game::gameSound->playSound(SAMUS_HIT_LIFE_POINT);
			this->health += manager->energyItem->getNumberGain();
			manager->energyItem->Destroy();
		}
	}

	if (SweptAABB(manager->missileItem, t) < 1.0f)
	{
		if (manager->missileItem->IsActive() == true)
		{
			Game::gameSound->playSound(SAMUS_HIT_LIFE_POINT);
			manager->samus->SetMissileNumbers(manager->samus->GetMissileNumbers() + 1);
			manager->missileItem->Destroy();
		}

	}
	if (SweptAABB(manager->morphItem, t) < 1.0f)
	{
		if (manager->morphItem->IsActive() == true)
		{
			isMorph = true;
			Game::gameSound->stopSound(BACKGROUND_MAP);
			Game::gameSound->playSound(BACKGROUND_ITEM_ACQUIRED);
			manager->morphItem->Destroy();

			manager->metroid->isFreezing = true;
		}
	}
	//----------------------------
	
	//Xử lý va chạm với ground
	//for (int i = 0; i < manager->quadtreeGroup->size; i++)
	//{
	//	switch (manager->quadtreeGroup->objects[i]->GetType())
	//	{
	//	case BRICK:
	//		Brick * brick = (Brick*)(manager->quadtreeGroup->objects[i]);
	//		float timeScale = SweptAABB(manager->quadtreeGroup->objects[i], t);
	//		if (timeScale < 1.0f)
	//		{
	//			if (brick->IsPassable())
	//			{
	//				if (this->vx > 0)
	//				{
	//					Camera::moveRight = true;
	//					
	//					if (manager->posManager->GetIndexRoom() <= 1)
	//						manager->posManager->Next();	// tăng index pooling đến room kế tiếp
	//					else if (manager->posManager->GetIndexRoom() == 2)
	//					{
	//						manager->posManager->Next();
	//						manager->metroid->isOnFloor = true;
	//					}
	//					else if (manager->posManager->GetIndexRoom() == 4)
	//						manager->posManager->Back();

	//					this->pos_x += 65;
	//				}
	//				else if (this->vx < 0)
	//				{
	//					Camera::moveLeft = true;

	//					if (manager->posManager->GetIndexRoom() < 3)
	//						manager->posManager->Back();	// giảm index pooling đến room phía sau
	//					else if (manager->posManager->GetIndexRoom() == 3)
	//						manager->posManager->Next();	// vào room boss
	//					
	//					this->pos_x -= 65;
	//				}
	//			}
	//			else
	//			{
	//				SlideFromGround(manager->quadtreeGroup->objects[i], t, timeScale);
	//				manager->samus->isOnAir = false;
	//			}
	//			//Response(manager->quadtreeGroup->objects[i], t, timeScale);
	//		}
	//		break;
	//	}
	//	
	//}

	for (int i = 0; i < manager->colGroundBrick->size; i++)
	{
		float timeScale = SweptAABB(manager->colGroundBrick->objects[i], t);
		if (timeScale < 1.0f)
		{
			ColliderBrick * brick = (ColliderBrick*)manager->colGroundBrick->objects[i];
			if (brick->isPassable == true)
			{
				if (this->vx > 0)
				{
					Camera::moveRight = true;

					if (manager->posManager->GetIndexRoom() <= 1)
						manager->posManager->Next();	// tăng index pooling đến room kế tiếp
					else if (manager->posManager->GetIndexRoom() == 2)
					{
						manager->posManager->Next();
						manager->metroid->isOnFloor = true;
					}
					else if (manager->posManager->GetIndexRoom() == 4)	// ra khỏi phòng boss
					{
						manager->posManager->Back();

						//Tắt nhạc phòng boss và bật nhạc nền ở đây
						Game::gameSound->stopSound(BACKGROUND_MOTHER_BRAIN_BOSS);
						Game::gameSound->playSoundLoop(BACKGROUND_MAP);
					}

					this->pos_x += 65;
				}
				else if (this->vx < 0)
				{
					Camera::moveLeft = true;

					if (manager->posManager->GetIndexRoom() < 3)
						manager->posManager->Back();	// giảm index pooling đến room phía sau
					else if (manager->posManager->GetIndexRoom() == 3)
					{
						manager->posManager->Next();	// vào room boss

														//tắt nhạc nền và thêm nhạc phòng boss ở đây
						Game::gameSound->playSoundLoop(BACKGROUND_MOTHER_BRAIN_BOSS);
						Game::gameSound->stopSound(BACKGROUND_MAP);
					}

					this->pos_x -= 65;

				}
			}
			else
			{
				SlideFromGround(brick, t, timeScale);
				manager->samus->isOnAir = false;
			}
		}
	}

	//Xử lý va chạm với colBrick khi đang ở floor
	if (manager->metroid->isOnFloor)
	{
		for (int i = 0; i < manager->colFloorBrick->size; i++)
		{
			float timeScale = SweptAABB(manager->colFloorBrick->objects[i], t);
			if (timeScale < 1.0f)
			{
				ColliderBrick * brick = (ColliderBrick*)manager->colFloorBrick->objects[i];
				if (brick->isPassable == true)
				{
					if (this->vx > 0)
					{
						Camera::moveRight = true;

						if (manager->posManager->GetIndexRoom() <= 1)
							manager->posManager->Next();	// tăng index pooling đến room kế tiếp
						else if (manager->posManager->GetIndexRoom() == 2)
						{
							manager->posManager->Next();
							manager->metroid->isOnFloor = true;
						}
						else if (manager->posManager->GetIndexRoom() == 4)	// ra khỏi phòng boss
						{
							manager->posManager->Back();

							//Tắt nhạc phòng boss và bật nhạc nền ở đây
							Game::gameSound->stopSound(BACKGROUND_MOTHER_BRAIN_BOSS);
							Game::gameSound->playSoundLoop(BACKGROUND_MAP);
						}

						this->pos_x += 65;
					}
					else if (this->vx < 0)
					{
						Camera::moveLeft = true;

						if (manager->posManager->GetIndexRoom() < 3)
							manager->posManager->Back();	// giảm index pooling đến room phía sau
						else if (manager->posManager->GetIndexRoom() == 3)
						{
							manager->posManager->Next();	// vào room boss
							
							//tắt nhạc nền và thêm nhạc phòng boss ở đây
							Game::gameSound->playSoundLoop(BACKGROUND_MOTHER_BRAIN_BOSS);
							Game::gameSound->stopSound(BACKGROUND_MAP);
						}

						this->pos_x -= 65;

					}
				}
				else
				{
					SlideFromGround(brick, t, timeScale);
					manager->samus->isOnAir = false;
				}
			}
		}
	}

	//Xử lý va chạm với static object
	for (int i = 0; i < manager->otherGO->size; i++)
	{
		float timeScale = SweptAABB(manager->otherGO->objects[i], t);
		if (timeScale < 1.0f)
		{
			switch (manager->otherGO->objects[i]->GetType())
			{
			case SENTRY:
			case GATE:
			{
				this->SlideFromGround(manager->otherGO->objects[i], t, timeScale);
				break;
			}
			}
		}
	}


	//float collisiontime = SweptAABB(manager->gateleft, t);
	//	if (collisiontime < 1.0f)
	//	{
	//		if (manager->gateleft->IsActive())
	//		{
	//			this->SlideFromGround(manager->gateleft, t, collisiontime);
	//		}
	//	}

	//	float collisiontime1 = SweptAABB(manager->gateright, t);
	//	if (collisiontime1 < 1.0f)
	//	{
	//		if (manager->gateright->IsActive())
	//		{
	//			this->SlideFromGround(manager->gateright, t, collisiontime1);
	//		}
	//	}
	
	pos_x += vx*t;
	pos_y += vy*t;

	Camera::SetCameraX(pos_x, t);
	Camera::SetCameraY(pos_y, t);

	// Animate samus if he is running
	//trace((LPWSTR)t);
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		switch (state)
		{
		case APPEARANCE:
			appearing->Next();
			break;
		case RIGHTING:
			running_right->Next();
			break;
		case LEFTING:
			running_left->Next();
			break;
		case AIMING_UP_LEFT:
			run_aim_up_left->Next();
			break;
		case AIMING_UP_RIGHT:
			run_aim_up_right->Next();
			break;
		case IDLING_AIM_UP_LEFT:
			idle_aim_up_left->Next();
			break;
		case IDLING_AIM_UP_RIGHT:
			idle_aim_up_right->Next();
			break;
		case ON_MORPH_LEFT:
			morph_ball_left->Next();
			break;
		case ON_MORPH_RIGHT:
			morph_ball_right->Next();
			break;
		case ON_RUN_SHOOTING_LEFT:
			run_shooting_left->Next();
			break;
		case ON_RUN_SHOOTING_RIGHT:
			run_shooting_right->Next();
			break;
		case ON_JUMP_LEFT:
			jump_left->Next();
			break;
		case ON_JUMP_RIGHT:
			jump_right->Next();
			break;
		case ON_SOMERSAULT_LEFT:
			somersault_left->Next();
			break;
		case ON_SOMERSAULT_RIGHT:
			somersault_right->Next();
			break;
		case ON_JUMPING_SHOOTING_LEFT:
			jumping_shooting_left->Next();	
			break;
		case ON_JUMPING_SHOOTING_RIGHT:
			jumping_shooting_right->Next();
			break;
		case ON_JUMP_AIM_UP_LEFT:
			jump_aim_up_left->Next();
			break;
		case ON_JUMP_AIM_UP_RIGHT:
			jump_aim_up_right->Next();
			break;
		case IDLING_SHOOTING_LEFT:
			idle_shooting_left->Next();
			break;
		case IDLING_SHOOTING_RIGHT:
			idle_shooting_right->Next();
			break;
		case IDLING_SHOOTING_UP_LEFT:
			idle_shooting_up_left->Next();
			break;
		case IDLING_SHOOTING_UP_RIGHT:
			idle_shooting_up_right->Next();
			break;
		}
		last_time = now;
	}	

	//Check if samus is on ground or not
	/*if (pos_y > GROUND_Y)
	{
		vy -= gravity;
	}
	else
	{
		pos_y = GROUND_Y;
		vy = 0;
		if (state == ON_JUMP_LEFT || state == ON_JUMPING_SHOOTING_LEFT || state == ON_SOMERSAULT_LEFT || state == ON_JUMP_AIM_UP_LEFT)
		{
			state = IDLE_LEFT;
		}
		else if (state == ON_JUMP_RIGHT || state == ON_JUMPING_SHOOTING_RIGHT || state == ON_SOMERSAULT_RIGHT || state == ON_JUMP_AIM_UP_RIGHT)
		{
			state = IDLE_RIGHT;
		}
	}*/

	//Render
	//Render();

}

void Samus::Response(GameObject *target, const float &DeltaTime, const float &CollisionTimeScale)
{
	// rồi mới bật ra
	if (normalx > 0.1f)	// tông bên phải
	{
		if (vx < -0.0f)// đang chạy qua trái => văng ngược lại
			vx *= -1;
	}
	else if (normalx < -0.1f) // tông bên trái
	{
		if (vx > 0.0f)//	đang chạy qua phải => văng ngược lại
			vx *= -1;
	}

	if (normaly > 0.1f) // tông phía trên
	{
		if (vy < -0.0f)// đang rơi xuống => văng lên trên
			vy = 0.0f;
		if (state == ON_JUMP_LEFT || state == ON_JUMPING_SHOOTING_LEFT || state == ON_SOMERSAULT_LEFT || state == ON_JUMP_AIM_UP_LEFT)
		{
			state = IDLE_LEFT;
		}
		else if (state == ON_JUMP_RIGHT || state == ON_JUMPING_SHOOTING_RIGHT || state == ON_SOMERSAULT_RIGHT || state == ON_JUMP_AIM_UP_RIGHT)
		{
			state = IDLE_RIGHT;
		}
	}
	else if (normaly < -0.1f) // tông phía dưới
	{
		if (vy > 0.0f)// đang bay lên => văng xuống
			vy *= -1;
	}

	if (normaly != 0)
	{
		pos_x += vx * (CollisionTimeScale)* DeltaTime;
		pos_y += vy * (CollisionTimeScale)* DeltaTime;
	}
}

// Phản xạ khi va chạm với ground
void Samus::SlideFromGround(GameObject *target, const float &DeltaTime, const float &CollisionTimeScale)
{
	//ResponseFrom(target, _DeltaTime, collisionTimeScale);
	// lỡ đụng 2,3 ground mà chạy cái này nhiều lần sẽ rất sai
	// "góc lag" sẽ làm đi luôn vào trong tường


	if (normalx > 0.1f)	// tông bên phải gạch
	{
		this->pos_x = (target->GetPosX() + target->GetCollider()->GetRight() - this->collider->GetLeft()) + 0.1f;
		pos_x -= vx*DeltaTime;
		//vx = 0.0f;
	}

	else if (normalx < -0.1f)// tông bên trái gạch
	{
		this->pos_x = (target->GetPosX() + target->GetCollider()->GetLeft() - this->collider->GetRight()) - 0.1f;
		pos_x -= vx*DeltaTime;
		//vx = 0.0f;
	}

	if (normaly > 0.1f) // trên xuống (không vào normaly được)
	{
		this->pos_y = (target->GetPosY() + target->GetCollider()->GetTop() - this->collider->GetBottom()) + 0.1f;
		//pos_y -= vy*DeltaTime;
		vy = 0;

		// Xử lý trạng thái cho samus
		if (state == ON_JUMP_LEFT || state == ON_JUMPING_SHOOTING_LEFT || state == ON_SOMERSAULT_LEFT || state == ON_JUMP_AIM_UP_LEFT)
		{
			state = IDLE_LEFT;
		}
		else if (state == ON_JUMP_RIGHT || state == ON_JUMPING_SHOOTING_RIGHT || state == ON_SOMERSAULT_RIGHT || state == ON_JUMP_AIM_UP_RIGHT)
		{
			state = IDLE_RIGHT;
		}

	}
	else if (normaly < -0.1f)	// tông ở dưới lên
	{
		//this->pos_y = (target->pos_y + target->collider->GetTop() - this->collider->GetBottom()) - 0.1f;
		pos_y -= vy*DeltaTime;
		vy = 0;
	}
	return;
}
void Samus::Deflect(GameObject *target, const float &DeltaTime, const float &CollisionTimeScale)
{
	// di chuyển vào sát tường trước
	//this->Response(target, DeltaTime, CollisionTimeScale);

	// rồi mới bật ra
	if (normalx > 0.1f)	// tông bên phải
	{
		if (vx < -0.0f)// đang chạy qua trái => văng ngược lại
			vx *= -1;
	}
	else if (normalx < -0.1f) // tông bên trái
	{
		if (vx > 0.0f)//	đang chạy qua phải => văng ngược lại
			vx *= -1;
	}

	if (normaly > 0.1f) // tông phía trên
	{
		if (vy < -0.0f)// đang rơi xuống => văng lên trên
			vy = 0.0f;
	}
	else if (normaly < -0.1f) // tông phía dưới
	{
		if (vy > 0.0f)// đang bay lên => văng xuống
			vy *= -1;
	}

	if (normaly != 0)
	{
		pos_x += vx * (CollisionTimeScale)* DeltaTime + 20.0f*normalx;
		pos_y += vy * (CollisionTimeScale)* DeltaTime + 20.0f*normaly;
	}
}
//----------------------------------