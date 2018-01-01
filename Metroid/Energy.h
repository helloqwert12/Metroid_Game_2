#pragma once
#ifndef _Energy_H_
#define _Energy_H_

#include "Enemy.h"
#include "Parameters.h"

class Energy : public Enemy
{
protected:
	Sprite * energy;

public:
	Energy();
	Energy(LPD3DXSPRITE spriteHandler, World * manager, ENEMY_TYPE enemy_type);
	~Energy();

	void InitSprites();
	//============== OVERRIDE VIRTUAL METHOD ===================
	virtual void Update(int t);
	virtual void Render();
	//============== END OVERRIDE VIRTUAL METHOD ===============
};

#endif // !_Energy_H_
