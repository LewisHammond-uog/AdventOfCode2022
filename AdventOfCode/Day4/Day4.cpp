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

    int Fullcount = 0;
    while(std::getline(inFile, lineString))
    {
        int l1 = -1; int l2 = -1; int r1 = -1; int r2 = -1;

        sscanf_s(lineString.c_str(), "%i-%i,%i-%i", &l1, &l2, &r1, &r2);

        //Full Overlap
        if((l1 >= r1 && l2 <= r2) || (r1 >= l1 && r2 <= l2))
        {
            Fullcount++;
        }

        //Partial Overlap
    }

    std::cout << Fullcount << std::endl;
}

