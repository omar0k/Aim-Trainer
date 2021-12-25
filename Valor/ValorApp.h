#pragma once
#include "ValorUtils.h"
#include "GameWindow.h"

#define FRAMES_PER_SECOND 30
namespace Valor
{
	class VALOR_API ValorApp
	{
	public:
		void Run();
		virtual void OnUpdate();
		virtual void OnKeyPressed(KeyPressedEvent& event);
		int GetGameWindowWidth() const;
		int GetGameWindowHeight() const;
	protected:
		ValorApp();
	private:
		GameWindow mGameWindow;
		std::chrono::steady_clock::time_point mTimeOfNextFrame;
		std::chrono::milliseconds mFrameDuration{1000/FRAMES_PER_SECOND};

	};
}