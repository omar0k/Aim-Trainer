#include "ValorApp.h"
#include <iostream>

namespace Valor
{
	void ValorApp::Run()
	{
		std::cout << "Valor is running..." << std::endl;
		while (true)
		{
			OnUpdate();
		}
	}
	void ValorApp::OnUpdate()
	{

	}
	ValorApp::ValorApp()
	{

	}
}