#include "Energy.h"
#include "World.h"
#include "GroupObject.h"
#include "Samus.h"
#include "Camera.h"

int tempenergy, tempmissile;
Energy::Energy()
{
}

Energy::Energy(LPD3DXSPRITE spriteHandler, World * manager, TYPE type)
{
	this->spriteHandler = spriteHandler;
	this->manager = manager;
	this->type = type;
	this->isActive = true;

	//Khởi tạo sprites
	this->InitSprites();

	collider = new Collider();
}


Energy::~Energy()
{
	delete(energy);
}

void Energy::InitSprites()
{
	switch (type)
	{
	case ENERGYINFO:
		energy = new Sprite(spriteHandler, ENERGY_SPRITE_PATH, ENERGY_PATH, ENERGY_WIDTH, ENERGY_HEIGHT, ENERGY_SPRITE_COUNT, 1);
		break;
	case MISSILEINFO:
		energy = new Sprite(spriteHandler, MISSILE_SPRITE_PATH, MISSILE_PATH, MISSILE_WIDTH, MISSILE_HEIGHT, MISSILE_SPRITE_COUNT, 1);
		break;
	}
}

void Energy::Update(int t)
{

	if (!isActive) return;

	// Nếu không nằm trong Camera thì unactive
	if (!IsInCamera())
	{
		isActive = false;
		return;
	}
	switch (type)
	{
	case ENERGYINFO:
	{
		if (tempenergy != Camera::GetCameraX() && (Camera::GetCameraX() - tempenergy<Camera::GetCameraX())) //Kiểm tra Camera có thay đổi vị trí so với hiện tại ,nếu có thì set lại vị trí của energy
		{
			int a = Camera::GetCameraX() - tempenergy;//a là quãng đường x mà Camera đã đi so với vị trí ban đầu (temp) 
			pos_x += a;//Cộng thêm a để cập nhật vị trí energy
		}

		tempenergy = Camera::GetCameraX();//Cập nhật lại vị trí temp hiện tại
	}
	break;
	case MISSILEINFO:
	{
		if (tempmissile != Camera::GetCameraX() && (Camera::GetCameraX() - tempmissile<Camera::GetCameraX())) //Kiểm tra Camera có thay đổi vị trí so với hiện tại ,nếu có thì set lại vị trí của energy
		{
			int a = Camera::GetCameraX() - tempmissile;//a là quãng đường x mà Camera đã đi so với vị trí ban đầu (temp) 
			pos_x += a;//Cộng thêm a để cập nhật vị trí energy
		}

		tempmissile = Camera::GetCameraX();//Cập nhật lại vị trí temp hiện tại
	}
	break;
	}


}

void Energy::InitPosition()
{
	switch (type)
	{
	case ENERGYINFO:
	{
		this->pos_x = Camera::currentCamX + 1440;
		this->pos_y = 400;
	}
	break;
	case MISSILEINFO:
	{
		this->pos_x = Camera::currentCamX + 1440;
		this->pos_y = 380;
	}
	break;
	}
}

void Energy::Render()
{
	// Nếu không active thì không render
	if (!isActive)
		return;

	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	switch (type)
	{
	case ENERGYINFO:
	{
		energy->Render(pos_x, pos_y);
	}
	break;
	case MISSILEINFO:
	{
		energy->Render(pos_x, pos_y);
	}
	break;
	}

	spriteHandler->End();
}