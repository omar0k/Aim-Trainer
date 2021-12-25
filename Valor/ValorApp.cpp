#include "pch.h"
#include "ValorApp.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Sprite.h"
#include "Shader.h"
#define GLFW_INCLUDE_NONE
#include "stb_image.h"
#include "Renderer.h"

//
namespace Valor

{
	void ValorApp::Run()
	{
		VALOR_LOG("Valor app running...");
		//ValorApp::ValorApp();
		
			
		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;
		//Renderer::Draw(happyface, 100, 50, happyface.GetWidth(), happyface.GetHeight(), myShader);

		while (true)
		{
			Renderer::ClearFrame();

			OnUpdate();

			std::this_thread::sleep_until(mTimeOfNextFrame);

			mGameWindow.SwapBuffers();

			mGameWindow.PollEvents();


			mTimeOfNextFrame += mFrameDuration;


		}
		Renderer::ShutDown();

	}
	void ValorApp::OnUpdate()
	{

	}
	void ValorApp::OnKeyPressed(KeyPressedEvent& event)
	{
		VALOR_LOG(event.GetKeyCode());
	}
	int ValorApp::GetGameWindowWidth() const
	{
		return mGameWindow.GetWindowWidth();
	}
	int ValorApp::GetGameWindowHeight() const
	{
		return mGameWindow.GetWindowHeight();
	}
	
	ValorApp::ValorApp()
	{
		mGameWindow.createWindow(800, 600, "Aim_Trainer");

		mGameWindow.SetKeyPressedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});
		mGameWindow.SetMouseClickedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
		});
		mGameWindow.SetCursorPosCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});

		Renderer::Init();
		
	}
}