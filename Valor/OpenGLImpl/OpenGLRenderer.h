#pragma once
#include "RendererImplementation.h"
#include "Shader.h"
#include "Sprite.h"
namespace Valor
{
	class OpenGLRenderer :public RendererImplementation
	{
	public:
		OpenGLRenderer();
		virtual void Draw(Sprite& sprite,
			int xPos, int yPos,
			int width, int height,
			Shader& shader)override;
		virtual void ClearFrame() override;
		
	};
}