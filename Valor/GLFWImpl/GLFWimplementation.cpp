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
}