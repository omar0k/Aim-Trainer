#pragma once

#ifdef VALOR_WINDOWS
	#ifdef VALOR_LIB
		#define VALOR_API __declspec(dllexport)
	#else
		#define VALOR_API __declspec(dllimport)
	#endif // VALOR_LIB
#else
	#define VALOR_API
#endif // VALOR_WINDOWS
