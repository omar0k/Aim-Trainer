#pragma once

#ifdef VALOR_LIB
	#define VALOR_API __declspec(dllexport)
#else
	#define VALOR_API __declspec(dllimport)
#endif // VALOR_LIB
