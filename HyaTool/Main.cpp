#include <iostream>

#include "FileSystem.h"
#include "RMD.h"
#include "RSD.h"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("How to use:\n");
		printf("HyaTool package MYPACKAGE.pkg MYFILE1.png MYFILE2.txt ...\n");
		printf("HyaTool RMD MYFILE.rmd MYFILE1.glb\n");
		printf("HyaTool RSD MYFILE.rsd MYFILE1.png\n");

		return 0;
	}
	std::string operation = argv[1];
	if (operation == "package")
	{
		if (!argv[2]) return 0;
		
		FileSystem fs;
		for (int i = 3; i < argc; i++)
		{
			std::string path = argv[i];
			std::string filename = path.substr(path.find_last_of("/\\") + 1);
			if (!fs.IsFile(filename))
			{
				File& f = fs.NewFile(filename);
				f.Open(path);
			}
			else
			{
				printf("Error: Repeated File \"%s\"\n", filename.c_str());
			}
		}
		fs.Save(argv[2]);
	}
	if (operation == "RMD")
	{
		if (!(argv[2] && argv[3])) return 0;

		RMD rmd;
		rmd.CreateFromGLTF(argv[3]);
		rmd.Save(argv[2]);
	}
	if (operation == "RSD")
	{
		if (!(argv[2] && argv[3])) return 0;

		RSD rsd;
		rsd.CreateFromPNG(argv[3]);
		rsd.Save(argv[2]);
	}
	return 0;
}