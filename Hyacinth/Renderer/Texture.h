#pragma once

#include <Glad/Glad.h>

class Texture
{
public:
	Texture()
	{
		glGenTextures(1, &texture);
	}
	~Texture()
	{
		glDeleteTextures(1, &texture);
	}
	void Set(int width, int height, int channels, unsigned char* data)
	{
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	void Use()
	{
		glBindTexture(GL_TEXTURE_2D, texture);
	}
private:
	unsigned int texture;
};