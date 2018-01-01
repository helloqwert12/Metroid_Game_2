#include "Number.h"
#include "World.h"
#include "GroupObject.h"
#include "Samus.h"
#include "Enemy.h"
#include "Camera.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Sprite.h"
using namespace std;

int temp1, temp2;
Number::Number()
{
}

Number::Number(LPD3DXSPRITE spriteHandler, World * manager, NUMBER_TYPE number_type) :Enemy(spriteHandler, manager)
{
	this->numbertype = number_type; //Lấy type của Number (Chục hoặc đơn vị)
	this->isActive = true;
	this->SetHealth(50); //Set giá trị Health mặc định là 50 
						 //Khởi tạo sprites
	this->InitSprites();


	collider = new Collider();


	vy = 0;
	vx = BLOCK_SPEED;

}


Number::~Number()
{
	delete(number1);
	delete(number2);

}

void Number::InitSprites()
{

	if (this->GetHealth() < 0) //Nếu Health <0 thì giá trị Health là 00 (0<=Health<=99)
	{
		switch (numbertype)
		{
		case CHUC:
			Check1(0);//Số chục là 0
			break;
		case DONVI:
			Check2(0);//Số dơn vị là 0
			break;
		}

	}
	if (this->GetHealth() > 0 && this->GetHealth() < 10) //Nếu giá trị Health trong khoảng từ 1-9
	{
		switch (numbertype)
		{
		case CHUC:
			Check1(0); //Số chục là 0
			break;
		case DONVI:
			Check2(this->GetHealth()); //Số đơn vị
			break;
		}


	}
	if (this->GetHealth() >= 10 && this->GetHealth() <= 99) //Nếu health trong khoảng 10-99
	{
		switch (numbertype)
		{
		case CHUC:
		{
			int chuc = this->GetHealth() / 10; //Lấy phần nguyên là số chục 
			Check1(chuc);
		}
		break;
		case DONVI:
		{
			int b = this->GetHealth() % 10;//Lấy phần dư là số đơn vị
			Check2(b);
		}
		break;
		}

	}
	if (this->GetHealth() >99) //Nếu Health > 99 thì giá trị Health sẽ là 99  (0<=Health<=99)
	{
		switch (numbertype)
		{
		case CHUC:
			Check1(9);//Số chục là 9
			break;
		case DONVI:
			Check2(9);//Số đơn vị là 9
			break;
		}

	}
}

void Number::Update(int t)
{

	if (!isActive) return;



	// Nếu không nằm trong Camera thì unactive
	if (!IsInCamera())
	{
		isActive = false;
		return;
	}


	if (temp1 != Camera::GetCameraX() && (Camera::GetCameraX() - temp1<Camera::GetCameraX()) || temp2 != Camera::GetCameraX() && (Camera::GetCameraX() - temp2<Camera::GetCameraX())) //Kiểm tra Camera có thay đổi vị trí so với hiện tại ,nếu có thì set lại vị trí của number
	{
		switch (numbertype)
		{
		case CHUC: //Trường hợp số chục
		{
			int d = Camera::GetCameraX() - temp1; //d là quãng đường x mà Camera đã đi so với vị trí ban đầu (temp1) 
			this->pos_x += d; //Cộng thêm d để cập nhật vị trí number1(số chục)
		}
		break;
		case DONVI: //Trường hợp số đơn vị 
		{
			int e = Camera::GetCameraX() - temp2;//e là quãng đường x mà Camera đã đi so với vị trí ban đầu (temp2) 
			this->pos_x += e;//Cộng thêm e để cập nhật vị trí number2 (số dơn vị)
		}
		break;
		}

	}
	switch (numbertype)
	{
	case CHUC:
		temp1 = Camera::GetCameraX();//Cập nhật lại vị trí temp1 hiện tại
		break;
	case DONVI:
		temp2 = Camera::GetCameraX();//Cập nhật lại vị trí temp2 hiện tại
		break;
	}


}
void Number::Check1(int n)
{
	fstream f;
	try
	{
		f.open(NUMBER_PATH);
	}
	catch (std::fstream::failure e)
	{
		trace(L"[Sprite class]--Read sprite info from file failed");
		return;
	}
	string line;
	int id = 0;
	while (!f.eof())
	{
		vector<string> pos;
		string split;
		getline(f, line);
		istringstream iss(line);
		if (n == id) //Kiểm tra số cần tìm có tương ứng với index cần tìm (n=1 thì id=1)
		{
			while (getline(iss, split, ' '))
			{
				pos.push_back(split);
			}

			int x = stoi(pos[0]);
			int y = stoi(pos[1]);
			number1 = new Sprite(spriteHandler, NUMBER_SPRITE_PATH, x, y, NUMBER_WIDTH, NUMBER_HEIGHT);//Dùng tọa độ x,y để khởi tạo cho number1
			break;
		}
		id++;
	}
	f.close();
}
void Number::Check2(int n)
{
	fstream f;
	try
	{
		f.open(NUMBER_PATH);
	}
	catch (std::fstream::failure e)
	{
		trace(L"[Sprite class]--Read sprite info from file failed");
		return;
	}
	string line;
	int id = 0;
	while (!f.eof())
	{


		vector<string> pos;
		string split;
		getline(f, line);
		istringstream iss(line);
		if (n == id)
		{
			while (getline(iss, split, ' '))
			{
				pos.push_back(split);
			}

			int x = stoi(pos[0]);
			int y = stoi(pos[1]);
			number2 = new Sprite(spriteHandler, NUMBER_SPRITE_PATH, x, y, NUMBER_WIDTH, NUMBER_HEIGHT);
			break;
		}
		id++;
	}
	f.close();
}
void Number::SetHealth(int value)
{
	health = value;
}

int Number::GetHealth()
{
	return health;
}

void Number::Render()
{
	// Nếu không active thì không render
	if (!isActive)
		return;

	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	switch (numbertype)
	{
	case CHUC:
		number1->Render(pos_x, pos_y);
		break;
	case DONVI:
		number2->Render(pos_x, pos_y);
		break;
	}

	spriteHandler->End();
}
