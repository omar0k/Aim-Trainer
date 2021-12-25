#include "pch.h"
#include "GLFWimplementation.h"
namespace Valor
{
	void GLFWimplementation::Init()
	{
		glfwInit();

	}
	void GLFWimplementation::CreateWindow(int width, int height, const std::string& name)
	{
		mWindow = glfwCreateWindow(width,height, name.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);

		glfwSetWindowUserPointer(mWindow,&mCallbacks);
		glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, 1);
		glfwSetKeyCallback(mWindow, [](
			GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action==GLFW_PRESS||action==GLFW_REPEAT)
				{
					CallbackFunctions* callbacks{(CallbackFunctions*)glfwGetWindowUserPointer(window)};
					KeyPressedEvent event{ key };
					callbacks->KeyPressedCallback(event);
				}

			});
		glfwSetCursorPosCallback(mWindow, [](
			GLFWwindow* window, double xPos, double yPos) {
				CallbackFunctions* callbacks{ (CallbackFunctions*)glfwGetWindowUserPointer(window) };
				
				std::cout << xPos << " : " << yPos << std::endl;
			});
		glfwSetMouseButtonCallback(mWindow, [](
			GLFWwindow* window, int button, int action, int mods) {
				CallbackFunctions* callbacks{ (CallbackFunctions*)glfwGetWindowUserPointer(window) };

				if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
				{
					std::cout << "right button pressed" << std::endl;
				}
				if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
				{
					std::cout << "right button released" << std::endl;
				}
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
				{
					std::cout << "left button released" << std::endl;
				}
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
				{
					std::cout << "left button pressed" << std::endl;
				}
				
			});
	
		
	}
	
	void GLFWimplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}
	void GLFWimplementation::PollEvents()
	{
		
		glfwPollEvents();
	}
	int GLFWimplementation::GetWindowWidth() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}
	int GLFWimplementation::GetWindowHeight() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}
	void GLFWimplementation::SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> func)
	{
		mCallbacks.KeyPressedCallback = func;

	}

	void GLFWimplementation::SetCursorPosCallback(std::function<void(KeyPressedEvent&)> func)
	{
		mCallbacks.CursorPosCallback = func;
	}

	void GLFWimplementation::SetMouseClickedCallback(std::function<void(KeyPressedEvent&)> func)
	{
		mCallbacks.MouseClickedCallback = func;

	}

	



}