#include "Shader.h"
#include "OpenGLImpl/OpenGLShader.h"
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

	void Shader::SetVec2IntUniform(const std::string& unifName, int first, int second)
	{
		mShader->SetVec2IntUniform(unifName, first, second);
	}

	void Valor::Shader::Use()
	{
		mShader->Use();
	}

}
