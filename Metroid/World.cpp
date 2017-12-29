#include "World.h"
#include "GroupObject.h"
#include "Brick.h"
#include "Camera.h"
#include "BulletManager.h"
#include "MorphItem.h"
#include "EnergyItem.h"
#include "MissileItem.h"
#include "ExplosionEffect.h"

World::World()
{
}

World::World(LPD3DXSPRITE spriteHandler, Metroid * metroid)
{
	//Gán
	this->spriteHandler = spriteHandler;
	this->metroid = metroid;

	//Khởi tạo các đối tượng trong World
	samus = new Samus(spriteHandler, this);
	//brick = new Brick(spriteHandler, this, BLUE, 1, 32*3, 32*10);

	quadtreeGroup = new GroupObject(this);
	rootQNode = NULL;

	bullets = new BulletManager(this, STANDARD);
	bullets->InitPosition(samus->GetPosX(), samus->GetPosY());
	missiles = new BulletManager(this, MISSILE);
	missiles->InitPosition(samus->GetPosX(), samus->GetPosY());
	sentrybullets = new BulletManager(this, SENTRY);
	birdbullets = new BulletManager(this, BIRD_BULLET);
	ridleyBoomerang = new BulletManager(this, BOOMERANG);

	morphItem = new MorphItem(spriteHandler, this);
	energyItem = new EnergyItem(spriteHandler, this);
	missileItem = new MissileItem(spriteHandler, this);

	explsEffect = new ExplosionEffect(spriteHandler, this);

	motherBrain = new MotherBrain(spriteHandler, this);
	ridley = new Ridley(spriteHandler, this);

	sentryLeft = new Sentry(spriteHandler, this, SENTRY_LEFT);
	sentryTop = new Sentry(spriteHandler, this, SENTRY_TOP);
	sentryRight = new Sentry(spriteHandler, this, SENTRY_RIGHT);

	collisionGroup = new GroupObject(this);
	effectgroup = new GroupObject(this);
	enemyGroup = new GroupObject(this);

	hog_yellow = new Bedgehog(spriteHandler, this, BEDGEHOG_YELLOW);
	hog_pink = new Bedgehog(spriteHandler, this, BEDGEHOG_PINK);
	bird = new Bird(spriteHandler, this, BIRD);
	block = new Block(spriteHandler, this, BLOCK);

	enemyGroup->AddGameObject(hog_yellow);
	enemyGroup->AddGameObject(hog_pink);
	enemyGroup->AddGameObject(bird);
	enemyGroup->AddGameObject(block);
	enemyGroup->AddGameObject(sentryLeft);
	enemyGroup->AddGameObject(sentryTop);
	enemyGroup->AddGameObject(sentryRight);
	enemyGroup->AddGameObject(motherBrain);
	enemyGroup->AddGameObject(ridley);
}


World::~World()
{
	delete(samus);
}

void World::Update(float t)
{
	samus->Update(t);
	// Cập nhật các đối tượng hiển thị trong camera

	bullets->Update(t);
	missiles->Update(t);
	sentrybullets->Update(t);
	birdbullets->Update(t);
	ridleyBoomerang->Update(t);

	morphItem->Update(t);
	energyItem->Update(t);
	missileItem->Update(t);

	explsEffect->Update(t);

	quadtreeGroup->GetCollisionObjectQTree();
	// Cập nhật các đối tượng có khả năng va chạm trong frame này
	collisionGroup->GetCollisionObjects();
	effectgroup->Update(t);
	collisionGroup->Update(t);

	hog_yellow->Update(t);
	hog_pink->Update(t);
	block->Update(t);
	bird->Update(t);
	sentryLeft->Update(t);
	sentryTop->Update(t);
	sentryRight->Update(t);

	motherBrain->Update(t);
	ridley->Update(t);
}

void World::Render()
{
	samus->Render();
	//zoomer->Render();
	bullets->Render();
	missiles->Render();
	sentrybullets->Render();
	birdbullets->Render();
	ridleyBoomerang->Render();

	morphItem->Render();
	energyItem->Render();
	missileItem->Render();

	explsEffect->Render();

	quadtreeGroup->Render();
	hog_yellow->Render();
	hog_pink->Render();
	block->Render();
	bird->Render();
	sentryLeft->Render();
	sentryTop->Render();
	sentryRight->Render();
	motherBrain->Render();
	ridley->Render();

	collisionGroup->Render();
	effectgroup->Render();
}

void World::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	samus->InitSprites(d3ddv);
	bullets->InitSprites(d3ddv);
	missiles->InitSprites(d3ddv);
	sentrybullets->InitSprites(d3ddv);
	birdbullets->InitSprites(d3ddv);
	ridleyBoomerang->InitSprites(d3ddv);

	morphItem->InitSprites(d3ddv);
	energyItem->InitSprites(d3ddv);
	missileItem->InitSprites(d3ddv);

	explsEffect->InitSprites(d3ddv);
}
