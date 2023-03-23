#include "Core/Window.h"
#include "Core/FileSystem.h"
#include "Renderer/Mesh.h"
#include "Renderer/Camera.h"
#include "Renderer/Shader.h"
#include "Renderer/Texture.h"
#include "Renderer/Renderer.h"

int main()
{
	FileSystem fs;
	fs.Load("C:/dev/Hyacinth/Example/data.pkg");

	auto& vShaderByte = fs.GetFile("vertex.glsl");
	auto& fShaderByte = fs.GetFile("fragment.glsl");
	std::string vShader((char*)vShaderByte.data.data(), vShaderByte.data.size());
	std::string fShader((char*)fShaderByte.data.data(), fShaderByte.data.size());

	auto& prefab = fs.GetFile("test.rmd");
	RMD rmd;
	rmd.Load(prefab.data);

	Window::Create(800, 600, "Teste");
	Renderer::Init();

	Shader shader;
	shader.SetShaders(vShader, fShader);

	Mesh mesh;
	mesh.SetIndices(rmd.indices);
	mesh.SetPosition(rmd.position);
	mesh.SetNormal(rmd.normal);
	mesh.SetTexcoord(rmd.texcoord);

	Camera camera;
	camera.position = glm::vec3(0.0f, 0.0f, 3.0f);

	auto& sprite = fs.GetFile("test.rsd");
	RSD rsd;
	rsd.Load(sprite.data);
	Texture texture;
	texture.Set(rsd.width, rsd.height, rsd.channels, rsd.bytes.data());

	float rot = 0.0f;
	while (Window::GetEvents())
	{
		rot += 1.0f;
		Renderer::Clear();
		shader.Use();

		shader.UploadMat4("viewproj", camera.GetViewProj());

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		shader.UploadMat4("model", model);

		texture.Use();

		mesh.Draw();

		Window::Present();
	}
}