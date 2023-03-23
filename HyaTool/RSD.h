#pragma once

#include <string>
#include <sstream>
#include <vector>
#include "stb_image.h"

class RSD
{
public:
	void CreateFromPNG(std::string path)
	{
		unsigned char* bytesRead = stbi_load(path.c_str(), &width, &height, &channels, 0);
		std::vector<unsigned char> bytesStr(bytesRead, bytesRead + width * height * channels);
		bytes = bytesStr;
		stbi_image_free(bytesRead);
	}
	void Save(std::string path)
	{
		std::ofstream ofs(path, std::ios::binary);
		ofs.write("RSD1", 4);

		ofs.write((char*)&width, sizeof(int));
		ofs.write((char*)&height, sizeof(int));
		ofs.write((char*)&channels, sizeof(int));

		size_t bytesSize = bytes.size();
		ofs.write((char*)&bytesSize, sizeof(size_t));
		ofs.write((char*)bytes.data(), bytesSize);

		ofs.close();
	}
private:
	int width, height, channels;
	std::vector<unsigned char> bytes;
};