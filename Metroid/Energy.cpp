#include "Energy.h"
#include "World.h"
#include "GroupObject.h"
#include "Samus.h"
#include "Enemy.h"
#include "Camera.h"

int temp;
Energy::Energy()
{
}

Energy::Energy(LPD3DXSPRITE spriteHandler, World * manager, ENEMY_TYPE enemy_type) :Enemy(spriteHandler, manager)
{
	this->enemy_type = enemy_type;
	this->isActive = true;

	//Khởi tạo sprites
	this->InitSprites();

	collider = new Collider();


	vy = 0;
	vx = BLOCK_SPEED;

}


Energy::~Energy()
{
	delete(energy);

}

void Energy::InitSprites()
{

	char*  path = NULL;
	switch (enemy_type)
	{
	case ENERGY:
		path = ENERGY_PATH;
		break;
	}

	// Khởi tạo sprite
	energy = new Sprite(spriteHandler, ENERGY_SPRITE_PATH, path, ENERGY_WIDTH, ENERGY_HEIGHT, ENERGY_SPRITE_COUNT, 1);
	temp = Camera::GetCameraX();
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

	if (temp != Camera::GetCameraX() && (Camera::GetCameraX() - temp<Camera::GetCameraX())) //Kiểm tra Camera có thay đổi vị trí so với hiện tại ,nếu có thì set lại vị trí của energy
	{
		int a = Camera::GetCameraX() - temp;//a là quãng đường x mà Camera đã đi so với vị trí ban đầu (temp) 
		pos_x += a;//Cộng thêm a để cập nhật vị trí energy
	}

	temp = Camera::GetCameraX();//Cập nhật lại vị trí temp hiện tại

}

void Energy::Render()
{
	// Nếu không active thì không render
	if (!isActive)
		return;

	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	energy->Render(pos_x, pos_y);
	spriteHandler->End();
}
