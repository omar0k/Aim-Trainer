#pragma once
#include "ValorApp.h"
#include "ValorUtils.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"
#include "Events.h"


#define START_VALOR_GAME(classname) \
int main()\
{\
	classname _valor_game;\
	_valor_game.Run();\
}