#pragma once
#include "GameObject.h"
class ColliderBrick : public GameObject
{
public:
	ColliderBrick();
	ColliderBrick(World * manager, float posX, float posY, float width, float height);
	~ColliderBrick();
};

