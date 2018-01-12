#pragma once

#include "Sprite.h"
#include "Collision.h"
#include "Parameters.h"
#include "GameObject.h"
#include "trace.h"
#include "Camera.h"

enum GATE_STATE {  //State of Gate
	OPEN,
	CLOSE,
	DESTROYING
};

class Gate : public GameObject
{
protected:
	Sprite * exists;
	Sprite * destroying;
	float time_survive;
	GATE_STATE state;
public:
	Gate(LPD3DXSPRITE spriteHandler, World * manager, GATE_TYPE type);
	~Gate();

	void Update(float t);
	void Render();
	void DestroyGate();
};

