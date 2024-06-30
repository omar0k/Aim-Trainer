#include "pch.h"
#include "Events.h"

namespace Valor
{
	KeyPressedEvent::KeyPressedEvent(int keyCode) :mKeyCode(keyCode)
	{

	}
	int KeyPressedEvent::GetKeyCode() const
	{
		return mKeyCode;
	}
	MouseMovedEvent::MouseMovedEvent(double xPos, double yPos) :mXPos(xPos), mYPos(yPos)
	{
	}
	double MouseMovedEvent::getXPos() const
	{
		return mXPos;
	}
	double MouseMovedEvent::getYPos() const
	{
		return mYPos;
	}
	MouseClickedEvent::MouseClickedEvent(int button, int action)
		: mMouseButton(button), mAction(action)
	{
	}

	int MouseClickedEvent::getMouseButton() const
	{
		return mMouseButton;
	}

	int MouseClickedEvent::getAction() const
	{
		return mAction;
	}
}