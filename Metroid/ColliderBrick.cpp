#include "ColliderBrick.h"



ColliderBrick::ColliderBrick()
{
}

ColliderBrick::ColliderBrick(World * manager, float posX, float posY, float width, float height)
{
	this->type = BRICK;
	this->pos_x = posX;
	this->pos_y = posY;
	collider = new Collider(0, 0, -height, width);
}


ColliderBrick::~ColliderBrick()
{
}
