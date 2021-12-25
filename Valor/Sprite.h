#pragma once

#include "pch.h"
#include "ValorUtils.h"
#include "SpriteImplementation.h"
namespace Valor {
	class VALOR_API Sprite
	{
	public:
		Sprite();
		void LoadImage(const std::string& pictureFile);
		int GetWidth() const;
		int GetHeight() const;
		void Bind();
	private:
		//OpenGLSprite spr;
		std::unique_ptr<SpriteImplementation> mSpriteImplementation;
	};

}

