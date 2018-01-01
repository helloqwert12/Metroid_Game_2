#pragma once
#ifndef _Number_H_
#define _Number_H_

#include "Enemy.h"
#include "Parameters.h"
enum NUMBER_TYPE
{
	CHUC,  //Chia type number ra 2 loại chục và đơn vị
	DONVI
};
class Number : public Enemy
{
protected:
	Sprite * number1; //Số chục
	Sprite * number2; //Số đơn vị
					  //Sprite * number;
	int health;  //Hiển thị health của energy
	NUMBER_TYPE numbertype;
public:
	Number();
	Number(LPD3DXSPRITE spriteHandler, World * manager, NUMBER_TYPE enemy_type);
	~Number();

	void InitSprites();
	//============== OVERRIDE VIRTUAL METHOD ===================
	virtual void Update(int t);
	virtual void Render();
	void SetHealth(int value); //Set giá trị Health
	int GetHealth();
	void Check2(int n);//Dùng để lấy số đơn vị
	void Check1(int n);//Dùng để lấy số chục
					   //============== END OVERRIDE VIRTUAL METHOD ===============
};

#endif // !_Number_H_
