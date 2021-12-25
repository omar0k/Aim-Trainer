#pragma once

#include "ValorUtils.h"
namespace Valor
{
	class VALOR_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		int GetKeyCode() const;
	private:
		int mKeyCode{ -1 };
	};
}