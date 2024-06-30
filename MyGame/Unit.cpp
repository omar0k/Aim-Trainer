#include "Unit.h"

Unit::Unit(const std::string& imageFile, int xPos, int yPos, int speed)
	: mPosX(xPos), mPosY(yPos), mSpeed(speed), mDirection(Direction::None)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	mImage.LoadImage(imageFile);
}

int Unit::GetUnitWidth() const
{
	return mImage.GetWidth();
}

int Unit::GetUnitHeight() const
{
	return mImage.GetHeight();
}

void Unit::SetPosX(int newX)
{
	mPosX = newX;
}

void Unit::SetPosY(int newY)
{
	mPosY = newY;
}

int Unit::GetPosX() const
{
	return mPosX;
}

int Unit::GetPosY() const
{
	return mPosY;
}

int Unit::GetSpeed() const
{
	return mSpeed;
}

bool Unit::CollideWith(const Unit& other) const
{
	int oXleft{ other.GetPosX() };
	int oXright{ other.GetPosX() + other.GetUnitWidth() };
	int oYbottom{ other.GetPosY() };
	int oYtop{ other.GetPosY() + other.GetUnitHeight() };
	bool intersectOnX{
		(mPosX <= oXleft && oXleft <= mPosX + GetUnitWidth()) ||
		(mPosX <= oXright && oXright <= mPosX + GetUnitWidth()) ||
		(oXleft <= mPosX && mPosX + GetUnitWidth() <= oXright) };

	bool intersectOnY{
		(mPosY <= oYbottom && oYbottom <= mPosY + GetUnitHeight()) ||
		(mPosY <= oYtop && oYtop <= mPosY + GetUnitHeight()) ||
		(oYbottom <= mPosY && mPosY + GetUnitHeight() <= oYtop) };

	return intersectOnX && intersectOnY;
}

void Unit::Draw(Valor::Shader& shader)
{
	Valor::Renderer::Draw(mImage, mPosX, mPosY, mImage.GetWidth(), mImage.GetHeight(), shader);
}

Unit::Direction Unit::GetDirection() const
{
	return mDirection;
}

void Unit::SetDirection(Unit::Direction newDirection)
{
	mDirection = newDirection;
}
void Unit::moveRandomDirection() {
	int randomMoveX = rand() % 20 - 5; // -5 to 5
	int randomMoveY = rand() % 20 - 5; // -5 to 5

	if (isPositionPossible(mPosX + randomMoveX, mPosY)) {
		mPosX += randomMoveX;
	}
	else {
		mPosX -= randomMoveX;
	}
	if (isPositionPossible(mPosX, mPosY + randomMoveY))
	{
		mPosY += randomMoveY;
	}
	else {
		mPosY -= randomMoveY;
	}
}
void Unit::UpdatePosition()
{

	switch (mDirection)
	{
	case Direction::Down:
		if (isPositionPossible(mPosX, mPosY - mSpeed))
			mPosY -= mSpeed;
		break;
	case Direction::Up:
		if (isPositionPossible(mPosX, mPosY + mSpeed))
			mPosY += mSpeed;
		break;
	case Direction::Left:
		if (isPositionPossible(mPosX - mSpeed, mPosY))
			mPosX -= mSpeed;
		break;
	case Direction::Right:
		if (isPositionPossible(mPosX + mSpeed, mPosY))
			mPosX += mSpeed;
		break;
	}
}

bool Unit::touchBottomEdge(int currY)
{
	if (currY == mImage.GetHeight())
		return true;
	else
	{
		return false;
	}
}

bool Unit::touchTopEdge(int currY)
{
	if (currY == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Unit::isPositionPossible(int newX, int newY) const
{
	int imageWidth = mImage.GetWidth();
	int imageHeight = mImage.GetHeight();

	// Check if the entire image fits within the bounds
	if (newX < 0 || newY < 0 || newX + imageWidth > 800 || newY + imageHeight > 800)
		return false;
	else
		return true;
}
