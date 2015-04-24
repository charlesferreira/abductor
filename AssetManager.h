#pragma once

#include <fstream>
#include <string>
#include <vector>

class AssetManager
{
public:
	std::vector<std::string> readfile(std::string filename);

	/*
	* Singleton example by Loki Astari on:
	* http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
	* (Visited on Apr 14, 2015)
	*/
	static AssetManager& getInstance()
	{
		static AssetManager instance;
		return instance;
	}

private:
	AssetManager() {};
	AssetManager(AssetManager const&) = delete;
	void operator=(AssetManager const&) = delete;

};

