#pragma once

#include "ValorUtils.h"
namespace Valor
{
	class VALOR_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		int GetKeyCode() const;
	private:
		int mKeyCode{ -1 };
	};

	class VALOR_API MouseMovedEvent {
	public:
		MouseMovedEvent(double xPos, double yPos);
		double getXPos() const;
		double getYPos() const;
	private:
		double mXPos;
		double mYPos;
	};
	class VALOR_API MouseClickedEvent {
	public:
		MouseClickedEvent(int button, int action);
		int getMouseButton() const;
		int getAction() const;
	private:
		int mMouseButton;
		int mAction;
	};
}