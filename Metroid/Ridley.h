#pragma once
#include "Enemy.h"
#include "GameObject.h"
#include "Parameters.h"


class Ridley : public Enemy
{
protected:
	World * manager;
	Sprite * fly;

public:
	Ridley(LPD3DXSPRITE spriteHandler, World * manager);
	~Ridley();

	//============= OVERRIDE VIRTUAL METHOD ==================
	void Update(float t);
	void Render();
	//============= END OVERRIDE VIRTUAL METHOD ==============
};