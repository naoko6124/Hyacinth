#pragma once

#include <fstream>
#include <string>
#include <vector>

struct File
{
	std::string name;
	std::vector<unsigned char> data;
};

struct FileSystem
{
	std::vector<File> files;

	File& GetFile(std::string name)
	{
		auto it = std::find_if(
			files.begin(), files.end(),
			[name](const File& file) {
			return file.name == name;
		}
		);
		return *it;
	}

	bool IsFile(std::string name)
	{
		auto it = std::find_if(
			files.begin(), files.end(),
			[name](const File& file) {
			return file.name == name;
		}
		);
		if (it == files.end())
			return false;
		else
			return true;
	}

	void Load(std::string path)
	{
		std::ifstream ifs(path, std::ios::binary);
		while (ifs)
		{
			std::size_t name_size;
			ifs.read(reinterpret_cast<char*>(&name_size), sizeof(std::size_t));

			if (!ifs) break;

			std::string name(name_size, '\0');
			ifs.read(&name[0], name_size);

			std::size_t data_size;
			ifs.read(reinterpret_cast<char*>(&data_size), sizeof(std::size_t));
			std::vector<unsigned char> data(data_size);
			ifs.read((char*)data.data(), data_size);

			NewFile(name, data);
		}
	}
private:
	File& NewFile(std::string name, std::vector<unsigned char> data)
	{
		files.push_back({ name, data });
		return GetFile(name);
	}
};

struct RMD
{
	std::vector<unsigned char> indices;
	std::vector<unsigned char> position;
	std::vector<unsigned char> normal;
	std::vector<unsigned char> texcoord;

	void Load(std::vector<unsigned char> data)
	{
		unsigned int offset = 0;

		auto sign = GetData(data, offset, 4);
		sign.push_back('\0');
		std::string signText = (char*)sign.data();
		if (signText != "RMD1")
			return;

		size_t indicesSize = GetSize(data, offset, (unsigned int)sizeof(size_t));
		indices = GetData(data, offset, (unsigned int)indicesSize);

		size_t positionSize = GetSize(data, offset, (unsigned int)sizeof(size_t));
		position = GetData(data, offset, (unsigned int)positionSize);

		size_t normalSize = GetSize(data, offset, (unsigned int)sizeof(size_t));
		normal = GetData(data, offset, (unsigned int)normalSize);

		size_t texcoordSize = GetSize(data, offset, (unsigned int)sizeof(size_t));
		texcoord = GetData(data, offset, (unsigned int)texcoordSize);
	}
private:
	size_t GetSize(std::vector<unsigned char> data, unsigned int &offset, unsigned int length)
	{
		auto first = data.begin() + offset;
		auto last = first + length;
		std::vector<unsigned char> currentData(first, last);
		offset += length;
		size_t size;
		memcpy(&size, currentData.data(), sizeof(size));
		return size;
	}
	std::vector<unsigned char> GetData(std::vector<unsigned char> data, unsigned int &offset, unsigned int length)
	{
		auto first = data.begin() + offset;
		auto last = first + length;
		offset += length;
		return std::vector<unsigned char>(first, last);
	}
};

struct RSD
{
	int width, height, channels;
	std::vector<unsigned char> bytes;

	void Load(std::vector<unsigned char> data)
	{
		unsigned int offset = 0;

		auto sign = GetData(data, offset, 4);
		sign.push_back('\0');
		std::string signText = (char*)sign.data();
		if (signText != "RSD1")
			return;

		auto widthBytes = GetData(data, offset, (unsigned int)sizeof(int));
		memcpy(&width, widthBytes.data(), widthBytes.size());

		auto heightBytes = GetData(data, offset, (unsigned int)sizeof(int));
		memcpy(&height, heightBytes.data(), heightBytes.size());

		auto channelsBytes = GetData(data, offset, (unsigned int)sizeof(int));
		memcpy(&channels, channelsBytes.data(), channelsBytes.size());

		size_t bytesSize = GetSize(data, offset, (unsigned int)sizeof(size_t));
		bytes = GetData(data, offset, (unsigned int)bytesSize);
	}
private:
	size_t GetSize(std::vector<unsigned char> data, unsigned int& offset, unsigned int length)
	{
		auto first = data.begin() + offset;
		auto last = first + length;
		std::vector<unsigned char> currentData(first, last);
		offset += length;
		size_t size;
		memcpy(&size, currentData.data(), sizeof(size));
		return size;
	}
	std::vector<unsigned char> GetData(std::vector<unsigned char> data, unsigned int& offset, unsigned int length)
	{
		auto first = data.begin() + offset;
		auto last = first + length;
		offset += length;
		return std::vector<unsigned char>(first, last);
	}
};