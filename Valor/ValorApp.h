#pragma once
#include "ValorUtilsh.h"
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

	};
}