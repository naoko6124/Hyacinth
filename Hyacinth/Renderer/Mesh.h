#pragma once

#include <vector>
#include <Glad/Glad.h>

class Mesh
{
public:
	Mesh()
	{
		glGenVertexArrays(1, &vertexArray);
	}
	~Mesh()
	{
		glDeleteVertexArrays(1, &vertexArray);
	}
	void SetIndices(std::vector<unsigned char> data)
	{
		glBindVertexArray(vertexArray);

		unsigned int buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size(), data.data(), GL_STATIC_DRAW);

		indexCount = data.size() / sizeof(unsigned short);
	}
	void SetPosition(std::vector<unsigned char> data)
	{
		glBindVertexArray(vertexArray);

		unsigned int buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, data.size(), data.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &buffer);
	}
	void SetNormal(std::vector<unsigned char> data)
	{
		glBindVertexArray(vertexArray);

		unsigned int buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, data.size(), data.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &buffer);
	}
	void SetTexcoord(std::vector<unsigned char> data)
	{
		glBindVertexArray(vertexArray);

		unsigned int buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, data.size(), data.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &buffer);
	}
	void Draw()
	{
		glBindVertexArray(vertexArray);
		glDrawElements(GL_TRIANGLES, (GLsizei)indexCount, GL_UNSIGNED_SHORT, 0);
	}
private:
	unsigned int vertexArray;
	size_t indexCount;
};