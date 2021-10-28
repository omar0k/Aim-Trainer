#include "pch.h"
#include "ValorApp.h"
#include "GLFW/glfw3.h"

//GLFW
namespace Valor
{
	void ValorApp::Run()
	{
		std::cout << "Valor is running..." << std::endl;
		//GLFWwindow* window;
		//glfwInit();
		mGameWindow.createWindow(800, 600, "Test");
		//GLFWmonitor* mon = glfwGetPrimaryMonitor();
		//window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
		while (true)
		{
			OnUpdate();
			mGameWindow.SwapBuffers();
			//glfwSwapBuffers(window);
			mGameWindow.PollEvents();
			//glfwPollEvents();
		}
	}
	void ValorApp::OnUpdate()
	{

	}
	ValorApp::ValorApp()
	{
	}
}