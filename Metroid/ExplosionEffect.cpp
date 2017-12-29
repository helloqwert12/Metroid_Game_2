#include "ExplosionEffect.h"



//ExplosionEffect::ExplosionEffect() : Effect()
//{
//	effect_type = EXPLOSION;
//}

ExplosionEffect::ExplosionEffect(LPD3DXSPRITE spriteHandler, World *manager) : Effect(spriteHandler, manager)
{
	effect_type = EXPLOSION;
}

ExplosionEffect::~ExplosionEffect()
{
}

void ExplosionEffect::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	Effect::InitSprites(d3ddv);

	effectSprite 
}
