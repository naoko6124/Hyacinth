#pragma once

#include <Windows.h>
#include <Glad/Glad.h>

namespace Renderer
{
	void Init()
	{
		gladLoadGL();
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	void Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}