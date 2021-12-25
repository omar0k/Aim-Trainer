#include "pch.h"
#include "OpenGLImpl/OpenGLRenderer.h"
#include "Renderer.h"

namespace Valor
{
	Renderer::Renderer()
	{
#ifdef VALOR_OPENGL
		mImplementation = std::unique_ptr<RendererImplementation>(new OpenGLRenderer);
#else
		#only_OPENGL_is_supported_currently

#endif // VALOR_OPENGL

	}
	void Renderer::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new Renderer;
		}
	}
	void Renderer::Draw(Sprite& sprite,
		int xPos, int yPos,
		int width, int height,
		Shader& shader)
	{
		mImplementation->Draw(sprite, xPos, yPos, width, height, shader);
		//std::cout << "debug2";

	}
	void Renderer::ClearFrame()
	{
		mImplementation->ClearFrame();
	}
	void Renderer::ShutDown()
	{
		if (mInstance != nullptr)
		{
			delete mInstance;
			mInstance = nullptr;
		}
	}
}