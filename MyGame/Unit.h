#pragma once
#include "Valor.h"
class Unit
{
public:
	Unit() = delete;
	Unit(const std::string& imageFile,int xPos,int yPos, int speed);
	int GetUnitWidth() const;
	int GetUnitHeight() const;
	void SetPosX(int newX);
	void SetPosY(int newY);
	int GetPosX() const;
	int GetPosY() const;
	int GetSPeed() const;

	//True if units collide(overlap)
	bool CollideWith(const Unit& other) const;
	void Draw(Valor::Shader& shader);
	enum class Direction
	{
		None,
		Up,
		Down,
		Right,
		Left
	};
	Unit::Direction GetDirection() const;
	void SetDirection(Unit::Direction newDirection);
	void UpdatePosition();
	bool touchBottomEdge(int currY);
	bool touchTopEdge(int currY);
private:
	bool isPositionPossible(int newX, int newY)const;
	Valor::Sprite mImage;
	int mSpeed;
	int mPosX;
	int mPosY;
	Direction mDirection;
};


