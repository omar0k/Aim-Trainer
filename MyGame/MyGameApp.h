#pragma once
#include "Valor.h"
#include "Unit.h"

class MyGameApp :public Valor::ValorApp
{
public:
	MyGameApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Valor::KeyPressedEvent& event) override;
	virtual void OnMouseMoved(Valor::MouseMovedEvent& event) override;
	virtual void OnMouseClicked(Valor::MouseClickedEvent& event) override;
	virtual bool IsMouseOverTarget(const Unit& target) const;
	Unit::Direction getRandomDirection();
private:
	double mouseXPos;
	double mouseYPos;
	bool mouseClicked = false;
	bool strafeMode = true;
	int score;
	std::vector<Unit>mTargets;
	std::vector<Unit>mBullets;
	int mFrameCounter;
	int mFrameCounterTargets;
	Valor::Shader mShader;
};