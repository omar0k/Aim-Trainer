#include "MyGameApp.h"

MyGameApp::MyGameApp() : mHero("Assets/Textures/Ship.png", .5 * GetGameWindowWidth(), 0, 15), mFrameCounter(0),misses(0),mFrameCounterTargets(0)				//Bullet("Assets/Textures/Bullet.png",mHero.GetPosX()+mHero.GetUnitWidth()/2,mHero.GetPosY()+mHero.GetUnitHeight()/2,10)
{
	mShader.Load("Assets/Shader/myVertexShader.glsl", "Assets/Shader/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);
}
void MyGameApp::OnUpdate()
{

	mHero.UpdatePosition();

	//The targets should appear every frame as long there are less than 10 targets on the screen
	//mFrameCounter % FRAMES_PER_SECOND == 0 && 
	for (auto& Bullet : mBullets)
	{
		Bullet.UpdatePosition();
	}
	for (auto& target : mTargets)
	{
		target.UpdatePosition();
	}
	
	if (mFrameCounter % FRAMES_PER_SECOND == 0)
	{
		mBullets.push_back(Unit{ "Assets/Textures/Bullet.png",mHero.GetPosX() + mHero.GetUnitWidth() / 2,mHero.GetPosY() + mHero.GetUnitHeight() / 2,10 });
		mBullets.back().SetDirection(Unit::Direction::Up);

	}
	for (auto& target : mTargets)
	{
		target.Draw(mShader);
	}
	for (auto& bullet : mBullets)

	{
		bullet.Draw(mShader);
	}
	
	if (mBullets.size() > 10)
	{
		mBullets.erase(mBullets.begin());
	}
	if (mFrameCounterTargets%FRAMES_PER_SECOND==0&&mTargets.size() < 10)
	{

		int newX{ rand() % 400 + 100 };
		int newY = GetGameWindowHeight()+50;
		Unit::Direction newDir;
		int dirVal{ 0 };
		if (dirVal == 0)
		{
			newDir = Unit::Direction::Down;
		}
		else if (dirVal == 1)
		{
			newDir = Unit::Direction::Up;
		}
		else if (dirVal == 2)
		{
			newDir = Unit::Direction::Left;
		}
		else
		{
			newDir = Unit::Direction::Right;
		}
		mTargets.push_back(Unit{ "Assets/Textures/Target.png",newX,newY,1 });
		mTargets.back().SetDirection(newDir);
	}

	//for (auto& bullet : mBullets)
	//{
	//	for (auto& target : mTargets)
	//	{
	//		if (bullet.CollideWith(target))
	//		{
	//			//erase target from mTargets and erase bullet from mBullets
	//		}
	//	}
	//}

	auto it = mTargets.begin();
	if (mBullets.size() >= 10)
	{
		for (auto& bullet : mBullets)
		{
			while (it != mTargets.end())
			{
				if (bullet.CollideWith(*it)||mHero.CollideWith(*it))
				{
					//std::cout << "size: " << mBullets.size();

					//std::cout<<bullet.GetPosX();
					it = mTargets.erase(it);
				}
				else
				{
					std::cout <<"Not Hit " << bullet.GetPosX() << std::endl;
					it++;
				}
			}
		}
	}
	for (auto& target : mTargets)
	{
		if (target.GetPosY()==GetGameWindowHeight())
		{
			misses++;
			std::cout <<"MISSES" << misses;
		}
		if (misses>=3)
		{
			Valor::Renderer::ShutDown();
		}
	}
	
	

	mHero.Draw(mShader);
	mFrameCounterTargets++;
	mFrameCounter += 5;
}




void MyGameApp::OnKeyPressed(Valor::KeyPressedEvent& event)
{

	switch (event.GetKeyCode())
	{
	case VALOR_KEY_LEFT:
		//mHero.SetPosX(mHero.GetPosX() - mHero.GetSPeed());
		mHero.SetDirection(Unit::Direction::Left);
		break;
	case VALOR_KEY_RIGHT:
		//mHero.SetPosX(mHero.GetPosX() + mHero.GetSPeed());
		mHero.SetDirection(Unit::Direction::Right);
		break;
	case VALOR_KEY_UP:
		//mHero.SetPosY(mHero.GetPosY() + mHero.GetSPeed());
		mHero.SetDirection(Unit::Direction::Up);
		break;
	case VALOR_KEY_DOWN:
		//mHero.SetPosY(mHero.GetPosY() - mHero.GetSPeed());
		mHero.SetDirection(Unit::Direction::Down);
		break;
	}

}


