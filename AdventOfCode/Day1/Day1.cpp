// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define NOMINMAX

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string lineString;
    std::ifstream inFile;

    inFile.open("C:/Users/LewisHammond/Desktop/SelfDev/AdventOfCode/input.txt");

    if (!inFile.is_open()) 
    {
        std::cout << "Failed to open file" << std::endl;
        return -1;
    }

    std::vector<int> elfs;
    int currentCalories = 0; //current count
    while (getline(inFile, lineString)) 
    { 
        //Empty line indicates new "elf"
        if (lineString.empty()) {
            elfs.push_back(currentCalories);
            currentCalories = 0;
        }

        //Add to the current count
        currentCalories += atoi(lineString.c_str());
    }

    //Find the max
    int max = *std::max_element(elfs.begin(), elfs.end());

    std::cout << "MAX is " << max << std::endl;

    return 0;
}

