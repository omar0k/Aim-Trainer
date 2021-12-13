#pragma once
#include "ValorUtils.h"
#include "GameWindow.h"


namespace Valor
{
	class VALOR_API ValorApp
	{
	public:
		void Run();
		virtual void OnUpdate();
	protected:
		ValorApp();
	private:
		GameWindow mGameWindow;

	};
}