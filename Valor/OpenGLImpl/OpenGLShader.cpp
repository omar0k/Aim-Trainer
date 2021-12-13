#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"
namespace Valor
{
	void OpenGLShader::Load(const std::string& vertexFile, const std::string& fragmentFile)
	{
		std::ifstream vertexFileStream{vertexFile};
		if (!vertexFileStream.is_open())
		{
			std:: cout<< "Failed to open shader files!!!" << std::endl;
		}
		std::stringstream vertexStringStream;
		vertexStringStream << vertexFileStream.rdbuf();
		std::string vertexCode{ vertexStringStream.str() };
		const char* cVertexCode{ vertexCode.c_str() };
		vertexFileStream.close();

		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &cVertexCode, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::fragment::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		//Fragment header
		std::ifstream fragmentFileStream{ fragmentFile };
		std::stringstream fragmentStringStream;
		fragmentStringStream << fragmentFileStream.rdbuf();
		std::string fragmentCode{ fragmentStringStream.str() };
		const char* cfragmentCode{ fragmentCode.c_str() };
		fragmentFileStream.close();

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &cfragmentCode, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::fragment::COMPILATION_FAILED\n" << infoLog << std::endl;
		}


		if (mShaderPRogram != 0)
		{
			glDeleteProgram(mShaderPRogram);
		}
		mShaderPRogram = glCreateProgram();
		glAttachShader(mShaderPRogram, vertexShader);
		glAttachShader(mShaderPRogram, fragmentShader);
		glLinkProgram(mShaderPRogram);

		glGetProgramiv(mShaderPRogram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(mShaderPRogram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::fragment::COMPILATION_FAILED\n" << infoLog << std::endl;

		}

	}
	void OpenGLShader::Use()
	{
		glUseProgram(mShaderPRogram);
	}
}