// Day8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "TreeGrid.h"

int main()
{
    std::string lineString;
    std::ifstream inFile;

    inFile.open("input.txt");
    if (!inFile.is_open())
    {
        std::cout << "day 8 Failed to open file" << std::endl;
        return -1;
    }

    std::stringstream stream;
    stream << inFile.rdbuf();
    std::string fileRead = stream.str();

    TreeGrid grid = TreeGrid(fileRead);

    using milli = std::chrono::milliseconds;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << grid.GetBestScore();
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "myFunction() took "
        << std::chrono::duration_cast<milli>(finish - start).count()
        << " milliseconds\n";


}

