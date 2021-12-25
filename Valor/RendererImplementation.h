#pragma once
#include "pch.h"
#include "Shader.h"
#include "Sprite.h"
namespace Valor
{
	class RendererImplementation
	{
	public:
		 virtual void Draw(Sprite& sprite,
			int xPos, int yPos,
			int width, int height,
			Shader& shader)=0;
		 virtual void ClearFrame()=0;
		 virtual ~RendererImplementation() {};
	};
}