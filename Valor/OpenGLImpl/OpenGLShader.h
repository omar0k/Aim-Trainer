#pragma once
#include "ShaderImplementation.h"
namespace Valor {
	class OpenGLShader : public ShaderImplementation
	{
	public:
		virtual void Load(const std::string& vertexFile, const std::string& fragmentFile) override;
		virtual void Use() override;
	private:
		unsigned int mShaderPRogram{ 0 };

	};
}