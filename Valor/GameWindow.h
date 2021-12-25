#pragma once
#include "ValorUtils.h"
#include "WindowImplementation.h"
#include "pch.h"
#include "Events.h"
namespace Valor
{
	class VALOR_API GameWindow
	{
	public:
		GameWindow();
		void createWindow(int width, int height,const std::string& name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowHeight() const;
		void SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> func);
		void SetCursorPosCallback(std::function<void(KeyPressedEvent&)>func);
		void SetMouseClickedCallback(std::function<void(KeyPressedEvent&)>func);
	private:
		std::unique_ptr<WindowImplementation> mWindow;
	};

}

