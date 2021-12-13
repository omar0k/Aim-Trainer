#include "pch.h"
#include "ValorApp.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Sprite.h"
#include "Shader.h"
#define GLFW_INCLUDE_NONE
#include "stb_image.h"
//GLFW
namespace Valor
{
	void ValorApp::Run()
	{
		std::cout << "Valor is running..." << std::endl;
		//GLFWwindow* window;
		//glfwInit();
		mGameWindow.createWindow(800, 600, "Test");
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Glad failed to initialize" << std::endl;
		}
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, //bottom left
			-0.5f,  0.5f, 0.0f, 1.0f, //top left
			 0.5f, -0.5f, 1.0f, 0.0f, // bottom right
			 0.5f,  0.5f, 1.0f, 1.0f  //top right
		};

		unsigned indeces[] =
		{
			0,1,2,
			1,2,3
		};
		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float)));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);



		
		//GLFWmonitor* mon = glfwGetPrimaryMonitor();
		//window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
		const char* fragmentShaderSource = R"(
			#version 330 core
			out vec4 FragColor;
			void main()
			{
				FragColor=vec4(1.0f,0.5f,0.2f,1.0f);
			}			
		)";
		//shaders
		Valor::Shader myShader;
		myShader.Load("Assets/Shader/myVertexShader.glsl", "Assests/Shader/myFragmentShader.glsl");
		
		//Texture
		Valor::Sprite fish;
		fish.LoadImage("Assests/Textures/awesomeface.png");

		while (true)
		{
			OnUpdate();
			glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			fish.Bind();

			myShader.Use();
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			mGameWindow.SwapBuffers();
			mGameWindow.PollEvents();
			//glfwSwapBuffers(window);
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