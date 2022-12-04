// Advent of Code Day 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::string lineString1;
    std::string lineString2;
    std::string lineString3;
    std::ifstream inFile;

    inFile.open("input.txt");
    if (!inFile.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return -1;
    }

    int totalPrios = 0;

    while (getline(inFile, lineString1))
    {
        getline(inFile, lineString2);
        getline(inFile, lineString3);

        char repeatChar = NULL;
        for(int i = 0; i < lineString1.length(); ++i)
        {
	        const char checkChar = lineString1[i];
            if(lineString2.find(checkChar) != -1 && lineString3.find(checkChar) != -1)
            {
                repeatChar = checkChar;
            }
        }

        if(repeatChar == NULL)
        {
            std::cout << "Didn't find repeat char" << std::endl;
            return -1;
        }

		//Determine Value
        int val = 0;
        if (repeatChar - 'a' >= 0) {
            val = repeatChar - 'a' + 1;
        }else
        {
            val = repeatChar - 'A' + 27;
        }

        totalPrios += val;
    }

    std::cout << totalPrios << std::endl;
}
