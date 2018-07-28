#include "IceBeam.h"
#include "World.h"

IceBeam::IceBeam(LPD3DXSPRITE spriteHandler, World * manager)
{
	icebeam_up = NULL;
	icebeam_left = NULL;
	icebeam_right = NULL;
	limit_dist_x = 0;
	limit_dist_y = 0;
	isActive = false;
	this->manager = manager;
	this->spriteHandler = spriteHandler;
	this->bulletType = ICEBEAM;
	damage = DAMAGE_SAMUS_ICEBEAM;

	//Set collider
	collider = new Collider(ICEBEAM_HEIGHT / 2, -ICEBEAM_WIDTH / 2, -ICEBEAM_HEIGHT / 2, ICEBEAM_WIDTH / 2);
}

IceBeam::IceBeam(LPD3DXSPRITE spriteHandler, World * manager, int x_holder, int y_holder)
{
	icebeam_up = NULL;
	icebeam_left = NULL;
	icebeam_right = NULL;
	limit_dist_x = 0;
	limit_dist_y = 0;
	isActive = false;
	this->manager = manager;
	this->spriteHandler = spriteHandler;
	this->bulletType = ICEBEAM;
	damage = DAMAGE_SAMUS_ICEBEAM;

	pos_x_holder = x_holder;
	pos_y_holder = y_holder;
}


IceBeam::~IceBeam()
{
	delete(icebeam_up);
	delete(icebeam_left);
	delete(icebeam_right);
}

void IceBeam::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &spriteHandler);
	if (result != D3D_OK) return;

	//Create sprite
	icebeam_up = new Sprite(spriteHandler, ICEBEAM_SPRITE_PATH, ICEBEAM_UP_SPRITE, ICEBEAM_UP_WIDTH, ICEBEAM_UP_HEIGHT, ICEBEAM_COUNT, SPRITE_PER_ROW);
	icebeam_left = new Sprite(spriteHandler, ICEBEAM_SPRITE_PATH, ICEBEAM_LEFT_SPRITE, ICEBEAM_WIDTH, ICEBEAM_HEIGHT, ICEBEAM_COUNT, SPRITE_PER_ROW);
	icebeam_right = new Sprite(spriteHandler, ICEBEAM_SPRITE_PATH, ICEBEAM_RIGHT_SPRITE, ICEBEAM_WIDTH, ICEBEAM_HEIGHT, ICEBEAM_COUNT, SPRITE_PER_ROW);
}

void IceBeam::InitSprites(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DTEXTURE9 image)
{
	//Create sprite
	icebeam_up = new Sprite(spriteHandler, image, ICEBEAM_UP_SPRITE, ICEBEAM_UP_WIDTH, ICEBEAM_UP_HEIGHT, ICEBEAM_COUNT, SPRITE_PER_ROW);
	icebeam_left = new Sprite(spriteHandler, image, ICEBEAM_LEFT_SPRITE, ICEBEAM_WIDTH, ICEBEAM_HEIGHT, ICEBEAM_COUNT, SPRITE_PER_ROW);
	icebeam_right = new Sprite(spriteHandler, image, ICEBEAM_RIGHT_SPRITE, ICEBEAM_WIDTH, ICEBEAM_HEIGHT, ICEBEAM_COUNT, SPRITE_PER_ROW);
}

void IceBeam::Render()
{
	if (isActive)
	{
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		switch (direction)
		{
		case ON_UP:
			icebeam_up->Render(pos_x, pos_y);
			break;
		case ON_LEFT:
			icebeam_left->Render(pos_x, pos_y + 10);
			break;
		case ON_RIGHT:
			icebeam_right->Render(pos_x, pos_y + 10);
			break;
		}
		spriteHandler->End();
	}
}