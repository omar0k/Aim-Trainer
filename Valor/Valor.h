#pragma once
#include "ValorApp.h"
#include "ValorUtils.h"
#include "GameWindow.h"

#define START_VALOR_GAME(classname) \
int main()\
{\
	classname _valor_game;\
	_valor_game.Run();\
}