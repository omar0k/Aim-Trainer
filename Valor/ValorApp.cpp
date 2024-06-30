#include "pch.h"
#include "ValorApp.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Sprite.h"
#include "Shader.h"
#define GLFW_INCLUDE_NONE
#include "stb_image.h"
#include "Renderer.h"

namespace Valor

{
	void ValorApp::Run()
	{
		VALOR_LOG("Valor app running...");
		//ValorApp::ValorApp();
		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;

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
	void ValorApp::OnMouseClicked(MouseClickedEvent& event)
	{
		VALOR_LOG(event.getMouseButton())
	}
	void ValorApp::OnMouseMoved(MouseMovedEvent& event)
	{
		VALOR_LOG(event.getXPos());
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

		mGameWindow.windowHint(GLFW_RESIZABLE, GLFW_FALSE);
		mGameWindow.createWindow(800, 800, "Aim Trainer");
		mGameWindow.SetKeyPressedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});
		mGameWindow.SetMouseClickedCallback([this](MouseClickedEvent& event) {
			OnMouseClicked(event);
			});
		mGameWindow.SetCursorPosCallback([this](MouseMovedEvent& event) {
			OnMouseMoved(event);
			});

		Renderer::Init();

	}
}