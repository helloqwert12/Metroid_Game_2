#pragma once
#ifndef _GATE_H
#define _GATE_H_
#include "Sprite.h"
#include "Collision.h"
#include "Parameters.h"
#include "GameObject.h"
#include "trace.h"
#include "Camera.h"

enum GATE_STATE {  //State of Gate
	OPEN,
	CLOSE
};
class Gate : public GameObject
{
protected:
	Sprite * gate; //Left sprite Gate

	char* type_path;

	int ID; //

	GATE_STATE state;
	GATE_TYPE gate_type;
public:
	Gate();
	Gate(LPD3DXSPRITE spriteHandler, World * manager);
	Gate(LPD3DXSPRITE spriteHandler, World * manager, GATE_TYPE type, int posX, int posY);
	Gate(LPD3DXSPRITE spriteHandler, World * manager, GATE_TYPE type);
	~Gate();

	void Check(int n);

	void InitSprites();
	void InitPostition(int x, int y);

	GATE_STATE GetState();
	void SetState(GATE_STATE value);

	//================ OVERRIDE VIRTUAL METHOD ==================
	void Update(int t);
	void Render();
	void Destroy();
	//================= END OVERRIDE VIRTUAL METHOD =============
};
#endif // !_GATE_H