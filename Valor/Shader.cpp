#include "Shader.h"
namespace Valor
	{
	Shader::Shader()
	{
#ifdef VALOR_OPENGL
		mShader = std::unique_ptr<ShaderImplementation>{ new OpenGLShader };
#else
#only_openGl_is_implemented_at_the_moment
#endif // VALOR_OPENGL

	}
	void Valor::Shader::Load(const std::string& vertexFile, const std::string& fragmentFile)
	{
		mShader->Load(vertexFile, fragmentFile);
	}

	void Valor::Shader::Use()
	{
		mShader->Use();
	}

}
