#pragma once
#include "ValorUtils.h"
#include "WindowImplementation.h"
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
	private:
		WindowImplementation* mWindow;
	};

}

