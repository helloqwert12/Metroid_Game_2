#pragma once
#include "GameObject.h"
class Item : public GameObject
{
protected:
	ITEM_TYPE item_type;
	float time_survive;
	Sprite * itemSprite;
public:
	Item(LPD3DXSPRITE sprietHandler, World * manager);
	~Item();

	//============= OVERRIDE VIRTUAL METHOD =================
	virtual void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	virtual void Init(float posX, float posY);
	virtual void Update(int t);
	virtual void Render();
	//============= END OVERRIDE VIRTUAL METHOD =============
};

