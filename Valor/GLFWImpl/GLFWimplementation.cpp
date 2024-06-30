#include "pch.h"
#include "GLFWimplementation.h"
namespace Valor
{
	void GLFWimplementation::Init()
	{
		glfwInit();

	}
	void GLFWimplementation::WindowHint(int hint, int value) {
		glfwWindowHint(hint, value);
	}
	void GLFWimplementation::CreateWindow(int width, int height, const std::string& name)
	{
		mWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);

		glfwSetWindowUserPointer(mWindow, &mCallbacks);
		glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, 1);
		glfwSetKeyCallback(mWindow, [](
			GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					CallbackFunctions* callbacks{ (CallbackFunctions*)glfwGetWindowUserPointer(window) };
					KeyPressedEvent event{ key };
					callbacks->KeyPressedCallback(event);
				}

			});
		glfwSetCursorPosCallback(mWindow, [](
			GLFWwindow* window, double xPos, double yPos) {
				CallbackFunctions* callbacks{ (CallbackFunctions*)glfwGetWindowUserPointer(window) };
				MouseMovedEvent mouseMovedEvent(xPos, yPos);
				callbacks->CursorPosCallback(mouseMovedEvent);
			});
		glfwSetMouseButtonCallback(mWindow, [](

			GLFWwindow* window, int button, int action, int mods) {
				CallbackFunctions* callbacks{ (CallbackFunctions*)glfwGetWindowUserPointer(window) };
				MouseClickedEvent mouseClickedEvent(button, action);
				callbacks->MouseClickedCallback(mouseClickedEvent);
				std::cout << button<<"----"<<action <<std::endl;
				/*if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
				{
					std::cout << "right button pressed" << std::endl;
				}
				if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
				{
					std::cout << "right button released" << std::endl;
				}*/
				/*if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
				{
					std::cout << "left button released" << std::endl;
				}
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
				{
					std::cout << "left button pressed" << std::endl;
				}*/
			});
		unsigned char pixels[16 * 16 * 4];

		// Fill pixels with transparent (alpha channel = 0)
		memset(pixels, 0, sizeof(pixels));

		// Define the size of the crosshair lines
		int lineThickness = 2;

		// Draw horizontal line
		for (int y = 7 - lineThickness / 2; y <= 7 + lineThickness / 2; ++y) {
			for (int x = 0; x < 16; ++x) {
				int index = (y * 16 + x) * 4;
				// Set RGB channels to white
				pixels[index] = 0xFF; // R
				pixels[index + 1] = 0xFF; // G
				pixels[index + 2] = 0xFF; // B
				// Set alpha channel to opaque
				pixels[index + 3] = 0xFF; // A
			}
		}

		// Draw vertical line
		for (int x = 7 - lineThickness / 2; x <= 7 + lineThickness / 2; ++x) {
			for (int y = 0; y < 16; ++y) {
				int index = (y * 16 + x) * 4;
				// Set RGB channels to white
				pixels[index] = 0xFF; // R
				pixels[index + 1] = 0xFF; // G
				pixels[index + 2] = 0xFF; // B
				// Set alpha channel to opaque
				pixels[index + 3] = 0xFF; // A
			}
		}

		// Create GLFW image
		GLFWimage image;
		image.width = 16;
		image.height = 16;
		image.pixels = pixels;

		// Create cursor
		GLFWcursor* cursor = glfwCreateCursor(&image, 7, 7); // Hotspot at the center
		glfwSetCursor(mWindow, cursor);



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

	void GLFWimplementation::SetCursorPosCallback(std::function<void(MouseMovedEvent&)> func)
	{
		mCallbacks.CursorPosCallback = func;
	}

	void GLFWimplementation::SetMouseClickedCallback(std::function<void(MouseClickedEvent&)> func)
	{
		
		mCallbacks.MouseClickedCallback = func;

	}
}