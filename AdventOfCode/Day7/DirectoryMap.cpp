#include "DirectoryMap.h"

#include <regex>
#include <iostream>
#include <algorithm>

#define COMMAND_SIZE 4

DirectoryMap::DirectoryMap()
{
	//Add root dir
	AddFile("", 0);
}

void DirectoryMap::ProcessCommand(std::string command)
{
	//Get the type of command
	std::string cmdString = command.substr(0, 4);
	if (cmdString == "dir ") { //Create an empty directroy in the tree
		AddFile(command.substr(command.find(" ") + 1) + "/", 0);
		return;
	} 
	else if (cmdString == "$ cd") //Change to a different directory
	{
		ChangeDir(command.substr(command.find_last_of(" ") + 1));
		return;
	} 
	else if (cmdString == "$ ls")
	{
		return;
	}
	else  //Only other input is numbers for file size
	{
		int size = stoi(command);
		std::string fileName = command.substr(command.find(" ") + 1);
		AddFile(fileName, size);
		return;
	}

	std::cout << "ERROR - Unsuppoted CMD" << std::endl;
}

int DirectoryMap::GetSizeOf(std::string dir)
{
	auto iter = fileMap.find(dir);
	if(iter == fileMap.end())
	{
		std::cout << "ERROR Invalid Dir" << std::endl;
		return -1;
	}

	return iter->second;
}

int DirectoryMap::GetSumOfDirectories(int maxDirSize)
{
	int sum = 0;
	for (auto it : fileMap) 
	{
		std::string path = it.first;
		int size = it.second;

		//Don't count files just directories
		if (path[path.length() - 1] != '/') 
		{
			continue;
		}

		if (size > maxDirSize) 
		{
			continue;
		}

		sum += size;
	}

	return sum;
}

void DirectoryMap::AddFile(std::string fileName, int size)
{
	std::string fileDir = currentDir + fileName;
	fileMap.insert({ fileDir, size });
	UpdateParentDirSizes(fileDir, size);
}

//Update the sizes of a parent directory with a new insterted file and its size
void DirectoryMap::UpdateParentDirSizes(std::string fileName, int size)
{
	std::string parentDir = GetParentDir(fileName);
	while (parentDir != "/")
	{
		//Find the dir in the map
		auto iter = fileMap.find(parentDir);
		if (iter != fileMap.end()) {
			iter->second += size;
		}
		parentDir = GetParentDir(parentDir);
	}

	//Update "/" dir
	auto iter = fileMap.find(parentDir);
	if (iter != fileMap.end()) {
		iter->second += size;
	}
}

void DirectoryMap::ChangeDir(std::string dir)
{
	if (dir == "..") {
		currentDir = GetParentDir(currentDir);
	}
	else if(dir == "/") {
		currentDir = "/";
	}
	else {
		currentDir += dir + "/";
	}
}

std::string DirectoryMap::GetParentDir(std::string dir)
{
	if (dir == "/") {
		return "/";
	}
	//Remove trailing backslash
	if (dir.back() == '/'){
		dir = dir.substr(0, dir.length() - 1);
	}

	//Remove anything past the last /
	int lastSlashIndex = dir.find_last_of('/');
	return dir.substr(0, lastSlashIndex + 1);
}

int DirectoryMap::GetDirToDelete(int totalDiskSize, int requiredUpdateSize)
{
	auto iter = fileMap.find("/");
	if (iter == fileMap.end()) {
		return -1;
	}

	int usedSize = iter->second;
	int deleteSize = abs(totalDiskSize - usedSize - requiredUpdateSize);
	int smallestDirSize = usedSize;

	for (auto it : fileMap) 
	{
		if (it.second > deleteSize && it.second < smallestDirSize) {
			smallestDirSize = it.second;
		}
	}

	return smallestDirSize;
}
