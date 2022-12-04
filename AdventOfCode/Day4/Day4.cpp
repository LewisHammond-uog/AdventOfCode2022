// Day4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <fstream>
#include <iostream>

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

    int fullCount = 0;
    int partialCount = 0;
    while(std::getline(inFile, lineString))
    {
        int elf1Left = -1; int elf1Right = -1; int elf2Left = -1; int elf2Right = -1;

        sscanf_s(lineString.c_str(), "%i-%i,%i-%i", &elf1Left, &elf1Right, &elf2Left, &elf2Right);

        //Full Overlap
        if((elf1Left >= elf2Left && elf1Right <= elf2Right) || (elf2Left >= elf1Left && elf2Right <= elf1Right))
        {
            fullCount++;
        }

        //Partial Overlap
        if (!(elf1Right < elf2Left || elf1Left > elf2Right))
        {
            partialCount++;
        }
    }

    std::cout << "Full Overlaps: " << fullCount << std::endl;
    std::cout << "Partial Overlaps: " <<  partialCount << std::endl;
}

