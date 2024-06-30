#pragma once
#include "WindowImplementation.h"
#include "GLFW/glfw3.h"
namespace Valor {

	class GLFWimplementation :public WindowImplementation
	{
	public:
		virtual void Init() override;
		virtual void CreateWindow(int width, int height, const std::string& name) override;
		virtual void WindowHint(int hint, int value)override;
		virtual void SwapBuffers()override;
		virtual void PollEvents() override;
		virtual int GetWindowWidth() const override;
		virtual int GetWindowHeight() const override;
		virtual void SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> func) override;
		virtual void SetCursorPosCallback(std::function<void(MouseMovedEvent&)>func) override;
		virtual void SetMouseClickedCallback(std::function<void(MouseClickedEvent&)>func)override;
	private:

		struct CallbackFunctions {
			std::function<void(MouseMovedEvent&)> CursorPosCallback;
			std::function<void(KeyPressedEvent&)> KeyPressedCallback;
			std::function<void(MouseClickedEvent&)> MouseClickedCallback;
		} mCallbacks;
		GLFWwindow* mWindow;

	};
};