#pragma once


#include "ValorUtils.h"
#include "pch.h"
#include "ShaderImplementation.h"
#include "OpenGLImpl/OpenGLShader.h"
namespace Valor {
	class VALOR_API Shader
	{
	public:
		Shader();
		void Load(const std::string& vertexFile, const std::string& fragmentFile);
		void Use();
	private:
		std::unique_ptr<ShaderImplementation> mShader;

	};

}

