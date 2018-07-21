#include "ColliderBrick.h"
#include "Metroid.h"
#include "World.h"


ColliderBrick::ColliderBrick()
{
}

ColliderBrick::ColliderBrick(LPD3DXSPRITE spriteHandler, World * manager, float posX, float posY, float width, float height)
{
	this->d3ddv = manager->metroid->GetDevice();
	this->type = COLLIDER_BRICK;
	this->pos_x = posX;
	this->pos_y = posY;
	this->width = width;
	this->height = height;

	isPassable = false;
	collider = new Collider(0, 0, -height, width);

	d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &back_buffer);

	// Create a small off-screen surface (will fill it contain in GameRun)
	int result =
		d3ddv->CreateOffscreenPlainSurface(
			100,					// width 				
			100,					// height
			D3DFMT_X8R8G8B8,		// format
			D3DPOOL_DEFAULT,		// where? (VRAM or RAM)
			&surface,
			NULL);
}


ColliderBrick::~ColliderBrick()
{
}

void ColliderBrick::Render()
{
	// đây là nơi để render cái khung hcn test nhưng chưa được

	//if (d3ddv->BeginScene())
	//{
	//	// Clear back buffer with BLACK
	//	d3ddv->ColorFill(back_buffer, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//	// Random color for the surface
	//	int r = 255;
	//	int g = 0;
	//	int b = 0;

	//	// Fill the bitmap
	//	d3ddv->ColorFill(surface, NULL, D3DCOLOR_XRGB(r, g, b));

	//	// Generate a random area (within back buffer) to draw the surface onto
	//	RECT rect;
	//	/*
	//	rect.left = rand() % (SCREEN_WIDTH/2);
	//	rect.top = rand() % (SCREEN_HEIGHT/2);
	//	rect.right = rect.left + rand() % (SCREEN_WIDTH/2);
	//	rect.bottom = rect.left + rand() % (SCREEN_HEIGHT/2);
	//	*/

	//	rect.left = pos_x;
	//	rect.top = pos_y;
	//	rect.right = pos_x + width;
	//	rect.bottom = rect.top + height;


	//	/*rect.left = 100;
	//	rect.top = 100;
	//	rect.right = 100+267;
	//	rect.bottom = 100+120;
	//	*/

	//	// Draw the surface onto the back buffer
	//	d3ddv->StretchRect(
	//		surface,			// from 
	//		NULL,				// which portion?
	//		back_buffer,		// to 
	//		&rect,				// which portion?
	//		D3DTEXF_NONE);

	//	d3ddv->EndScene();
	//}

	//d3ddv->Present(NULL, NULL, NULL, NULL);
}
