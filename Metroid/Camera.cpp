#include "Camera.h"

float Camera::currentCamX = 0;
float Camera::currentCamY = 500;

float Camera::max_x = 2000;
float Camera::min_x = 0;

float Camera::max_y = 0;
float Camera::min_y = 0;

int Camera::width = 640;
int Camera::height = 480;

float Camera::speed = 0.2f;

bool Camera::moveLeft = false;
bool Camera::moveRight = false;

Camera::Camera()
{
	Camera::SetDemension(GAME_SCREEN_RESOLUTION_640_480_24);
}


Camera::~Camera()
{
}

void Camera::SetCameraX(float pos_x, float t)
{
	

	if (max_x == 0) return;

	if (moveRight == true)
	{
		currentCamX += speed * t;
		// Nếu current đã chạy đến vị trí max
		if (currentCamX >= max_x)
		{
			
			moveRight = false;	//Ngừng hiệu ứng chuyển camera
			min_x = max_x;		//Gán min bằng max, rồi max gán mức tiếp theo
		}
		return;
	}
	if (moveLeft == true)
	{
		currentCamX -= speed * t;
		// Nếu góc phải camera đã chạy đến vị trí min
		if (currentCamX + width <= min_x)
		{
			moveLeft = false;	//Ngừng hiệu ứng chuyển camera
			max_x = min_x;		//Gán max bằng min, rồi min gán mức nhỏ hơn
		}
		return;
	}

	currentCamX = pos_x - 320;
	
	if (currentCamX < min_x)
	{
		currentCamX = min_x;
	}
	else if (currentCamX + width >= max_x)
	{
		currentCamX = max_x - width;
	}
}

void Camera::SetCameraY(float pos_y, float t)
{
	if (max_y == 0) return;
	
	currentCamY = pos_y - 240;

	if (currentCamY < min_y)
	{
		currentCamY = min_y;
	}
	if (currentCamY + height >= max_y)
	{
		currentCamY = max_y;
	}
}

void Camera::SetDemension(int mode)
{
	switch (mode)
	{
	case GAME_SCREEN_RESOLUTION_640_480_24:
		width = 640;
		height = 480;
		break;
	case GAME_SCREEN_RESOLUTION_800_600_24:
		width = 800;
		height = 600;
		break;
	case GAME_SCREEN_RESOLUTION_1024_768_24:
		width = 1024;
		height = 768;
		break;
	}
}

bool Camera::IsInCamera(float x, float y, float width, float height)
{
		 //Kiềm tra bên trái
		if (x + width < Camera::currentCamX)
			return false;
		// Kiểm tra phía trên
		if (y + height > Camera::currentCamY)
			return false;
		// Kiểm tra bên phải
		if (x > Camera::currentCamX + Camera::width)
			return false;
		// Kiểm tra phía dưới
		if (y < Camera::currentCamY - Camera::height)
			return false;
	
		return true;
}
