﻿#pragma once
#ifndef _METROID_H_
#define _METROID_H_

#include "Game.h"
#include "World.h"
#include "Parameters.h"
#include "Loader.h"

class Metroid : public Game
{
protected:
	LPDIRECT3DSURFACE9 startscreen;
	LPDIRECT3DSURFACE9 introscreen;
	LPDIRECT3DSURFACE9 gameoverscreen;

	LPD3DXSPRITE spriteHandler;
	World * world;
	Sprite * intro;
	BulletManager * bulletManager;

	Loader* first_room;
	

private:
	void _InitBackground();
	void _InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void _InitPositions();

	DWORD start_jump;
	DWORD now_jump;
	DWORD tick_per_frame;

	DWORD start_shoot;
	DWORD now_shoot;

	void _Shoot(BULLET_DIRECTION dir);
	void _ShootMissile(BULLET_DIRECTION dir);

public:
	Metroid(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate);
	~Metroid();

	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);
	// ---------------------------
	virtual void Update(float Delta); //Kiểm tra screen Mode
	virtual void UpdateIntro(float Delta);
	virtual void UpdateFrame(float Delta);
	// -----------------------------
	virtual void Render(LPDIRECT3DDEVICE9 d3ddv);
	virtual void RenderStartScreen(LPDIRECT3DDEVICE9 d3ddv);
	virtual void RenderIntro(LPDIRECT3DDEVICE9 d3ddv);
	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv);
	virtual void RenderGameOver(LPDIRECT3DDEVICE9 d3ddv);
	// ---------------------------
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void OnKeyDown(int KeyCode);

	DWORD GetTickPerFrame();

	int screenMode;
};

#endif // !_METROID_
	