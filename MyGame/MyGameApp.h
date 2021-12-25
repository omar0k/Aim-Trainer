#pragma once
#include "Valor.h"
#include "Unit.h"

class MyGameApp :public Valor::ValorApp
{
public:
	MyGameApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Valor::KeyPressedEvent& event) override;
private:
	int misses;
	Unit mHero;
	//Unit Bullet;
	std::vector<Unit>mTargets;
	std::vector<Unit>mBullets;
	int mFrameCounter;
	int mFrameCounterTargets;
	Valor::Shader mShader;
};