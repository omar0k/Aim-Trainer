#include "Sprite.h"
#include "pch.h"

namespace Valor {
	Sprite::Sprite()
	{
#ifdef VALOR_OPENGL
		mSpriteImplementation = 
			std::unique_ptr<SpriteImplementation>{ new OpenGLSprite };
#else
		#only_OpenGL_is_supported_so_far
#endif // VALOR_OPENGL

	}
	void Sprite::LoadImage(const std::string& pictureFile)
	{
		mSpriteImplementation->LoadImage(pictureFile);
	}

	int Sprite::GetWidth() const
	{
		return mSpriteImplementation->GetWidth();
	}

	int Sprite::GetHeight() const
	{
		return mSpriteImplementation->GetHeight();
	}
	void Sprite::Bind()
	{
		mSpriteImplementation->Bind();
	}

}
