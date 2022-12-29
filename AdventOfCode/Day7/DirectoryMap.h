#pragma once

#include <string>
#include <map>

class DirectoryMap
{
public:
	DirectoryMap();
	void ProcessCommand(std::string command);
	int GetSizeOf(std::string dir);
	int GetSumOfDirectories(int maxDirSize);
	int GetDirToDelete(int totalDiskSize, int requiredUpdateSize);

private:
	std::string currentDir = "/";
	//Map of path, file size
	std::map<std::string, int> fileMap;

	void AddFile(std::string fileName, int size);
	void UpdateParentDirSizes(std::string fileName, int size);
	void ChangeDir(std::string dir);
	std::string GetParentDir(std::string dir);
};

