#pragma once

#include <string>
#include <Glad/Glad.h>
#include <Glm/Glm.hpp>
#include <Glm/Gtc/Matrix_Transform.hpp>
#include <Glm/Gtc/Type_Ptr.hpp>

class Shader
{
public:
	Shader()
	{
		program = glCreateProgram();
	}
	~Shader()
	{
		glDeleteProgram(program);
	}
	void SetShaders(std::string vertexCode, std::string fragmentCode)
	{
		int success;
		char infoLog[512];

		unsigned int vertex, fragment;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		const char* vertexBytes = vertexCode.c_str();
		const char* fragmentBytes = fragmentCode.c_str();
		glShaderSource(vertex, 1, &vertexBytes, NULL);
		glShaderSource(fragment, 1, &fragmentBytes, NULL);
		glCompileShader(vertex);
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
		};
		glCompileShader(fragment);
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
		};
		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
	}

	void Use()
	{
		glUseProgram(program);
	}

	void UploadMat4(std::string location, glm::mat4 matrix)
	{
		int loc = glGetUniformLocation(program, location.c_str());
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix));
	}
private:
	unsigned int program;
};