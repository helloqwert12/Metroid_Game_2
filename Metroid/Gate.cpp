#include "Gate.h"
#include "Game.h"
#include <vector>
#include "GroupObject.h"
#include "World.h"
#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Sprite.h"
using namespace std;

float time_survive = GATE_SURVIVE; //time_survive là thời gian chờ để cửa chuyển trạng thái (Open->Close)

void Gate::Render()
{
	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	switch (state)
	{
	case CLOSE:
	{
		switch (gate_type)
		{
		case LEFT:
		{
			if (isActive == true)
			{
				gate->Render(pos_x, pos_y);
			}//Kiểm tra State là Close thì sẽ Render gate
		}
		break;
		case RIGHT:
		{
		if (isActive == true)
			{
				gate->Render(pos_x, pos_y);
			}//Kiểm tra State là Close thì sẽ Render gate
		}
		break;
		}
	}
	}

	spriteHandler->End();
}

void Gate::Destroy()
{
	//Ngưng active
	isActive = false;

	//--TO DO: Đưa Gate ra khỏi viewport
}

Gate::Gate()
{
}

Gate::Gate(LPD3DXSPRITE spriteHandler, World * manager, GATE_TYPE type, int posX, int posY)
{


	this->spriteHandler = spriteHandler;
	this->manager = manager;
	this->gate_type = type;
	this->pos_x = posX;
	this->pos_y = posY;
	this->SetState(CLOSE);

	this->isActive = true;

	//Kiểm tra gate_type là Left hay Right



	this->InitSprites();

	//--TO DO: Set collider cho Gate

	collider = new Collider();
	collider->SetCollider(0, 0, -GATE_HEIGHT, GATE_WIDTH);
	this->SetHealth(10); //Khởi tạo Health cua Gate = 10 (Gate Close) , nếu Health của Gate <= 0 (Gate Open)
}
Gate::Gate(LPD3DXSPRITE spriteHandler, World * manager, GATE_TYPE type)
{


	this->spriteHandler = spriteHandler;
	this->manager = manager;
	this->gate_type = type;
	this->SetState(CLOSE);

	this->isActive = true;

	//Kiểm tra gate_type là Left hay Right



	this->InitSprites();

	//--TO DO: Set collider cho Gate

	collider = new Collider();
	collider->SetCollider(0, 0, -GATE_HEIGHT, GATE_WIDTH);
	this->SetHealth(10); //Khởi tạo Health cua Gate = 10 (Gate Close) , nếu Health của Gate <= 0 (Gate Open)
}
Gate::Gate(LPD3DXSPRITE spriteHandler, World * manager)
{
}

Gate::~Gate()
{
	delete(gate);
}

void Gate::InitSprites()
{
	switch (state)
	{
	case CLOSE:
	{
		switch (gate_type)
		{
		case LEFT:
		{
			this->type_path = GATE_LEFT;
			//Check(0);
		}
		break;
		case RIGHT:
			this->type_path = GATE_RIGHT;
			break;
		}
	}
	break;
	}

	//Create instance of sprites
	gate = new Sprite(spriteHandler, GATE_SPRITES_PATH, type_path, GATE_WIDTH, GATE_HEIGHT, 1, 1);
}
//void Gate::Check(int n)
//{
//	fstream f;
//	try
//	{
//		f.open(GATE_LEFT_PATH);
//	}
//	catch (std::fstream::failure e)
//	{
//		trace(L"[Sprite class]--Read sprite info from file failed");
//		return;
//	}
//	string line;
//	int id = 0;
//	while (!f.eof())
//	{
//		vector<string> pos;
//		string split;
//		getline(f, line);
//		istringstream iss(line);
//		if (n == id) //Kiểm tra số cần tìm có tương ứng với index cần tìm (n=1 thì id=1)
//		{
//			while (getline(iss, split, ' '))
//			{
//				pos.push_back(split);
//			}
//
//			int x = stoi(pos[0]);
//			int y = stoi(pos[1]);
//			switch (state)
//			{
//			case LEFT:
//			{
//				gate = new Sprite(spriteHandler, GATE_SPRITES_PATH, x, y, GATE_WIDTH, GATE_HEIGHT);//Dùng tọa độ x,y để khởi tạo cho number1
//
//			}
//			break;
//			case RIGHT:
//			{
//				gate = new Sprite(spriteHandler, GATE_SPRITES_PATH, x, y, GATE_WIDTH, GATE_HEIGHT);//Dùng tọa độ x,y để khởi tạo cho number1
//			}
//			break;
//			}
//			break;
//		}
//		id++;
//	}
//	f.close();
//}
void Gate::InitPostition(int x, int y)
{
	this->pos_x = x;
	this->pos_y = y;
}

GATE_STATE Gate::GetState()
{
	return state;
}

void Gate::SetState(GATE_STATE value)
{
	state = value;
}

void Gate::Update(int t)
{
	time_survive -= t; //Time_survive giảm dần theo t khi bắt đầu Update 
	if (!isActive) return;

	//Xử lí khi bắn đạn thì Health của Gate giảm đến <=0



	if (this->GetHealth() <= 0)  //Neu Health cua Gate <= 0 thi khong render Gate ,state tu Close sang Open
	{
		this->SetState(OPEN);
		this->isActive = false;
		/*this->SetHealth(10);*/  //Set lai Health nhu luc dau
	}

	//for (int i = 0; i < manager->quadtreeGroup->size; i++)
	//{
	//	switch (manager->quadtreeGroup->objects[i]->GetType())
	//	{
	//	case BRICK:
	//		float timeScale = SweptAABB(manager->quadtreeGroup->objects[i], t);
	//		// Nếu có va chạm
	//		if (timeScale < 1.0f)
	//		{
	//			this->SlideFromGround(manager->quadtreeGroup->objects[i], t, timeScale);
	//		}
	//		break;
	//	}

	//}

	//if (state == OPEN) //Nếu cửa ở trạng thái OPEN
	//{
	//	//Nếu time_survive (thời gian chờ ) <=0 thì cửa sẽ chuyển sang Close 	
	//	if (time_survive <= 0)
	//	{
	//		this->SetState(CLOSE);
	//		this->SetHealth(10);
	//		this->SetActive(true);
	//		//this->InitSprites();
	//		time_survive = GATE_SURVIVE;
	//	
	//	}
	//}
}