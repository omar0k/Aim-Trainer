#pragma once
#include "pch.h"
#include "Sprite.h"
#include "Shader.h"

#include "RendererImplementation.h"

namespace Valor {
	class Renderer
	{
	public:
		static void init();
		static void Draw(const Sprite& sprite,
			int xPos, int yPos,
			int width, int height,
			const Shader& shader);
		static void ClearFrame();
		static void ShutDown();
	private:
		Renderer();
		inline static Renderer* mInstance{ nullptr };
		std::unique_ptr<RendererImplementation> mImplementation;
	};
}