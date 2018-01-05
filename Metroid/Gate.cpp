//#include "Gate.h"
//#include "Game.h"
//#include <vector>
//#include "GroupObject.h"
//#include "World.h"
//#include <time.h>
//
//float time_survive = GATE_SURVIVE; //time_survive là thời gian chờ để cửa chuyển trạng thái (Open->Close)
//
//void Gate::Render()
//{
//	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
//
//	switch (state)
//	{
//	case CLOSE:
//		gate->Render(pos_x, pos_y); //Kiểm tra State là Close thì sẽ Render gate
//		break;
//	}
//	spriteHandler->End();
//}
//
//void Gate::Destroy()
//{
//	//Ngưng active
//	isActive = false;
//
//	//--TO DO: Đưa Gate ra khỏi viewport
//}
//
//Gate::Gate()
//{
//}
//
//Gate::Gate(LPD3DXSPRITE spriteHandler, World * manager, GATE_TYPE type, int posX, int posY)
//{
//	this->type = GATE;
//
//	this->spriteHandler = spriteHandler;
//	this->manager = manager;
//	this->gate_type = type;
//	this->pos_x = posX;
//	this->pos_y = posY;
//
//
//
//	this->SetState(CLOSE);
//
//	this->isActive = true;
//
//	//Kiểm tra gate_type là Left hay Right
//	switch (gate_type)
//	{
//	case LEFT:
//		this->type_path = GATE_LEFT;
//		break;
//	case RIGHT:
//		this->type_path = GATE_RIGHT;
//		break;
//	}
//
//
//	this->InitSprites();
//
//	//--TO DO: Set collider cho Gate
//
//	collider = new Collider();
//	collider->SetCollider(0, 0, -GATE_HEIGHT, GATE_WIDTH);
//	this->SetHealth(-10); //Khởi tạo Health cua Gate = 10 (Gate Close) , nếu Health của Gate <= 0 (Gate Open)
//}
//Gate::Gate(LPD3DXSPRITE spriteHandler, World * manager)
//{
//}
//
//Gate::~Gate()
//{
//	delete(gate);
//}
//
//void Gate::InitSprites()
//{
//	//Create instance of sprites
//	gate = new Sprite(spriteHandler, GATE_SPRITES_PATH, type_path, GATE_WIDTH, GATE_HEIGHT, 1, 1);
//}
//
//void Gate::InitPostition()
//{
//}
//
//GATE_STATE Gate::GetState()
//{
//	return state;
//}
//
//void Gate::SetState(GATE_STATE value)
//{
//	state = value;
//}
//
//void Gate::Update(int t)
//{
//	time_survive -= t; //Time_survive giảm dần theo t khi bắt đầu Update 
//	if (!isActive) return;
//
//	//Xử lí khi bắn đạn thì Health của Gate giảm đến <=0
//
//	if (this->GetHealth() <= 0)  //Neu Health cua Gate <= 0 thi khong render Gate ,state tu Close sang Open
//	{
//		this->SetState(OPEN);
//		this->isActive = false;
//		this->SetHealth(10);  //Set lai Health nhu luc dau
//	}
//
//
//	if (state == OPEN) //Nếu cửa ở trạng thái OPEN
//	{
//		//Nếu time_survive (thời gian chờ ) <=0 thì cửa sẽ chuyển sang Close 	
//		if (time_survive <= 0)
//		{
//			state = CLOSE;
//			this->isActive = true;
//			time_survive = GATE_SURVIVE;
//		}
//	}
//}