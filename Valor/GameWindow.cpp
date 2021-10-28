#include "GameWindow.h"
#include "pch.h"
#include "GLFWImpl/GLFWimplementation.h"
namespace Valor {
	GameWindow::GameWindow()
	{
#ifdef VALOR_WINDOWS
		mWindow = new GLFWimplementation;
#elif VALOR_MAC
		mWindow = new GLFWimplementation;
#elif VALOR_LINUX
		mWindow = new GLFWimplementation;
#else
		#only_Windows_Linux_Mac_are_supported
#endif
		mWindow->Init();
	}
	void GameWindow::createWindow(int width, int height,const std::string &name)
	{
		mWindow->CreateWindow(width, height, name);
	}
	void GameWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}
	void GameWindow::PollEvents()
	{
		mWindow->PollEvents();
	}
	int GameWindow::GetWindowWidth() const
	{

		return mWindow->GetWindowWidth();
	}
	int GameWindow::GetWindowHeight() const
	{
		return mWindow->GetWindowHeight();
	}
}
