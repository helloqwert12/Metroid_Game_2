#include "ExplosionEffect.h"



ExplosionEffect::ExplosionEffect() : Effect()
{
	type = EFFECT_TYPE;
	Effect_Type = EXPLOSION;
}
ExplosionEffect::ExplosionEffect(LPD3DXSPRITE spriteHandler, World *manager) : Effect(spriteHandler, manager)
{
	type = EFFECT_TYPE;
	Effect_Type = EXPLOSION;
}

ExplosionEffect::~ExplosionEffect()
{
}

void ExplosionEffect::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	Effect::InitSprites(d3ddv);
}
