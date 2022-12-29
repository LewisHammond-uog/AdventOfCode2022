
#include <iostream>
#include <fstream>
#include "DirectoryMap.h"

int main()
{
    std::string lineString;
    std::ifstream inFile;

    inFile.open("input.txt");
    if (!inFile.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return -1;
    }


    DirectoryMap* m = new DirectoryMap();
    while (getline(inFile, lineString))
    {
        m->ProcessCommand(lineString);
    }

    std::cout << "TOTAL SIZE: " << m->GetSizeOf("/") << std::endl;
    std::cout << "SUM OF DIRS UNDER " << m->GetSumOfDirectories(100000) << std::endl;
}
