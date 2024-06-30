#include "MyGameApp.h"

MyGameApp::MyGameApp() : mFrameCounter(0), score(0), mFrameCounterTargets(0),
mouseXPos(0.0), mouseYPos(0.0)				//Bullet("Assets/Textures/Bullet.png",mHero.GetPosX()+mHero.GetUnitWidth()/2,mHero.GetPosY()+mHero.GetUnitHeight()/2,10)
{
	mTargets.push_back(Unit{ "Assets/Textures/Target.png", GetGameWindowWidth() / 2, GetGameWindowHeight() / 2, strafeMode ? 5 : 0 });
	mShader.Load("Assets/Shader/myVertexShader.glsl", "Assets/Shader/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", GetGameWindowWidth(), GetGameWindowHeight());
}
void MyGameApp::OnUpdate()
{
	for (auto& Bullet : mBullets)
	{
		Bullet.UpdatePosition();
	}
	for (auto& target : mTargets)
	{
		target.UpdatePosition();
	}

	for (auto& target : mTargets)
	{
		target.Draw(mShader);
	}

	// number of targets
	if (!strafeMode)
	{
		if (mTargets.size() < 4)
		{
			int newX = rand() % (GetGameWindowWidth() - 200) + 100;
			int newY = rand() % (GetGameWindowHeight() - 200) + 100;
			int targetSpeed = strafeMode ? 5 : 0;
			mTargets.push_back(Unit{ "Assets/Textures/Target.png", newX, newY, targetSpeed });
		}
	}
	// If strafe mode is true

	if (strafeMode) {
		for (auto& target : mTargets) {
			target.moveRandomDirection();
		}
	}
	// other wise: targets dispear on hit
	else {
		auto it = mTargets.begin();

		while (it != mTargets.end())
		{
			auto it2 = it;
			it2++;
			while (it2 != mTargets.end())
			{
				if (it->CollideWith(*it2))
				{
					it2 = mTargets.erase(it2);
				}
				else
				{
					it2++;
				}
			}

			if (IsMouseOverTarget(*it) && mouseClicked)
			{
				score++;
				it = mTargets.erase(it);
			}
			else
			{
				it++;
			}
		}
	}
	//std::cout << score << std::endl;
	mFrameCounterTargets++;
	mFrameCounter += 5;
}




void MyGameApp::OnKeyPressed(Valor::KeyPressedEvent& event)
{
	int movementAmount = 10;
	switch (event.GetKeyCode())
	{
	case VALOR_KEY_LEFT:
		//mHero.SetPosX(mHero.GetPosX() - mHero.GetSPeed());
		//mHero.SetDirection(Unit::Direction::Left);
		//mHero.SetPosX(mHero.GetPosX() - movementAmount);
		break;
	case VALOR_KEY_RIGHT:
		//mHero.SetPosX(mHero.GetPosX() + mHero.GetSPeed());
		//mHero.SetDirection(Unit::Direction::Right);
		//mHero.SetPosX(mHero.GetPosX() + movementAmount);
		break;
	}
}
void MyGameApp::OnMouseMoved(Valor::MouseMovedEvent& event) {
	mouseXPos = event.getXPos();
	mouseYPos = event.getYPos();
}


bool MyGameApp::IsMouseOverTarget(const Unit& target) const {
	if (mouseXPos >= target.GetPosX() &&
		mouseXPos <= target.GetPosX() + target.GetUnitWidth() &&
		(GetGameWindowHeight() - mouseYPos) >= target.GetPosY() &&
		(GetGameWindowHeight() - mouseYPos) <= target.GetPosY() + target.GetUnitHeight()) {
		return true;
	}
	return false;
}

Unit::Direction MyGameApp::getRandomDirection()
{

	int randomIndex = std::rand() % 4;
	switch (randomIndex) {
	case 0: return Unit::Direction::Up;
	case 1: return Unit::Direction::Down;
	case 2: return Unit::Direction::Right;
	case 3: return Unit::Direction::Left;
	default: return Unit::Direction::Up;
	}

}

void MyGameApp::OnMouseClicked(Valor::MouseClickedEvent& event)
{
	if (event.getMouseButton() == 0) {

		mouseClicked = !mouseClicked;
	}
}




