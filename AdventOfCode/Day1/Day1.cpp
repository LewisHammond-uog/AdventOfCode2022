// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define NOMINMAX

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>

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

    int elfID = 0;
    std::vector<int> elfs; 
    int currentCalories = 0; //current count
    while (getline(inFile, lineString)) 
    { 
        //Empty line indicates new "elf"
        if (lineString.empty()) {
            elfs.push_back(currentCalories);

            currentCalories = 0;
            ++elfID;
        }

        //Add to the current count
        currentCalories += atoi(lineString.c_str());
    }

    std::sort(elfs.begin(), elfs.end());

    int one = elfs[elfs.size() - 1];
    int two = elfs[elfs.size() - 2];
    int three = elfs[elfs.size() - 3];

    std::cout << one + two + three << std::endl;

    return 0;
}

