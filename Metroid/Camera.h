#pragma once
#include "Parameters.h"
class Camera
{
public:
	static float max_x;
	static float min_x;

	static float max_y;
	static float min_y;

	static float currentCamX;
	static float currentCamY;

	static int width;	// width của viewport
	static int height;	// height của viewport

	static float speed;

	static bool moveLeft;
	static bool moveRight;

	Camera();
	~Camera();

	static void SetCameraX(float pos_x, float t);
	static void SetCameraY(float pos_y, float t);

	static void SetDemension(int mode);
};