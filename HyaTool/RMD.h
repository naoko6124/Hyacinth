#pragma once

#include <string>
#include "tiny_gltf.h"

class RMD
{
public:
	void CreateFromGLTF(std::string path)
	{
		tinygltf::Model model;
		tinygltf::TinyGLTF loader;
		loader.LoadBinaryFromFile(&model, nullptr, nullptr, path);

		auto& mesh = model.meshes[0];
		
		indices = GetBytes(model, mesh.primitives[0].indices);
		position = GetBytes(model, mesh.primitives[0].attributes["POSITION"]);
		normal = GetBytes(model, mesh.primitives[0].attributes["NORMAL"]);
		texcoord = GetBytes(model, mesh.primitives[0].attributes["TEXCOORD_0"]);
	}
	void Save(std::string path)
	{
		std::ofstream ofs(path, std::ios::binary);
		ofs.write("RMD1", 4);

		size_t indicesSize = indices.size();
		ofs.write((char*)&indicesSize, sizeof(size_t));
		ofs.write((char*)indices.data(), indicesSize);

		size_t positionSize = position.size();
		ofs.write((char*)&positionSize, sizeof(std::size_t));
		ofs.write((char*)position.data(), positionSize);

		size_t normalSize = normal.size();
		ofs.write((char*)&normalSize, sizeof(std::size_t));
		ofs.write((char*)normal.data(), normalSize);

		size_t texcoordSize = texcoord.size();
		ofs.write((char*)&texcoordSize, sizeof(std::size_t));
		ofs.write((char*)texcoord.data(), texcoordSize);

		ofs.close();
	}
private:
	std::vector<unsigned char> GetBytes(tinygltf::Model& model, int acessor)
	{
		auto& bufferView = model.bufferViews[model.accessors[acessor].bufferView];
		auto& buffer = model.buffers[bufferView.buffer].data;
		auto first = buffer.begin() + bufferView.byteOffset;
		auto last = first + bufferView.byteLength;
		return std::vector<unsigned char>(first, last);
	}
private:
	std::vector<unsigned char> indices;
	std::vector<unsigned char> position;
	std::vector<unsigned char> normal;
	std::vector<unsigned char> texcoord;
};