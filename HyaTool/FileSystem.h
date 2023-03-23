#pragma once

#include <fstream>
#include <string>
#include <vector>

struct File
{
	std::string name;
	std::vector<char> data;

	void Save(std::string path)
	{
		std::ofstream ofs(path, std::ios::binary);
		ofs.write(data.data(), data.size());
		ofs.close();
	}

	void Open(std::string path)
	{
		std::ifstream ifs(path, std::ios::binary);
		std::vector<char> input_data(std::istreambuf_iterator<char>(ifs), {});
		data = input_data;
		ifs.close();
	}
};

struct FileSystem
{
	std::vector<File> files;

	File& NewFile(std::string name, std::vector<char> data)
	{
		files.push_back({ name, data });
		return GetFile(name);
	}

	File& NewFile(std::string name)
	{
		files.push_back({ name });
		return GetFile(name);
	}

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

	void Save(std::string path)
	{
		std::ofstream ofs(path, std::ios::binary);
		for (const auto& file : files)
		{
			std::size_t name_size = file.name.size();
			ofs.write(reinterpret_cast<const char*>(&name_size), sizeof(std::size_t));
			ofs.write(file.name.data(), name_size);

			std::size_t data_size = file.data.size();
			ofs.write(reinterpret_cast<const char*>(&data_size), sizeof(std::size_t));
			ofs.write(file.data.data(), data_size);
		}
		ofs.close();
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
			std::vector<char> data(data_size);
			ifs.read(data.data(), data_size);

			NewFile(name, data);
		}
	}
};