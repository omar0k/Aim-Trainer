#include "GameWindow.h"
#include "pch.h"
#include "GLFWImpl/GLFWimplementation.h"
namespace Valor {
	GameWindow::GameWindow()
	{
#ifdef VALOR_WINDOWS
		mWindow = std::unique_ptr<WindowImplementation>{ new GLFWimplementation() };
#elif VALOR_MAC
		mWindow = std::unique_ptr<WindowImplementation>{ new GLFWimplementation() };
#elif VALOR_LINUX						
		mWindow = std::unique_ptr<WindowImplementation>{ new GLFWimplementation() };
#else
		#only_Windows_Linux_Mac_are_supported
#endif
			mWindow->Init();
	}
	void GameWindow::createWindow(int width, int height, const std::string& name)
	{
		mWindow->CreateWindow(width, height, name);
	}
	
	void GameWindow::windowHint(int hint, int value) {
		mWindow->WindowHint(hint, value);
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
	void GameWindow::SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> func)
	{
		mWindow->SetKeyPressedCallback(func);
	}
	void GameWindow::SetCursorPosCallback(std::function<void(MouseMovedEvent&)> func)
	{
		mWindow->SetCursorPosCallback(func);
	}
	void GameWindow::SetMouseClickedCallback(std::function<void(MouseClickedEvent&)> func)
	{
		mWindow->SetMouseClickedCallback(func);
	}
}
