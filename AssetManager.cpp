#include "AssetManager.h"


std::vector<std::string> AssetManager::readfile(std::string filename)
{
	std::ifstream file(filename);
	std::string line;
	std::vector<std::string> output;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			output.push_back(line);
		}
		file.close();
	}

	return output;
}