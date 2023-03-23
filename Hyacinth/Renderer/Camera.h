#pragma once

#include <Glad/Glad.h>
#include <Glm/Glm.hpp>
#include <Glm/Gtc/Matrix_Transform.hpp>
#include <Glm/Gtc/Type_Ptr.hpp>

class Camera
{
public:
	glm::vec3 position = glm::vec3(0.0f, 0.0f, -5.0f);
	glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 GetViewProj()
	{
		glm::mat4 view = glm::lookAt(position, target, up);

		glm::mat4 proj = glm::perspective(glm::radians(60.0f), 800.0f / 600.0f, 0.1f, 1000.0f);

		glm::mat4 viewProj = proj * view;
		
		return viewProj;
	}
};