// Advent of Code Day 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

    while (getline(inFile, lineString))
    {
        int charCount = lineString.length();

        std::string firstPart = lineString.substr(0, charCount / 2);
        std::string secondPart = lineString.substr(charCount / 2, charCount / 2);

        char repeatChar = NULL;
        for(unsigned int i = 0; i < firstPart.length(); ++i)
        {
	        if(secondPart.find(firstPart[i]) != -1)
	        {
                repeatChar = firstPart[i];
                break;
	        }
        }

        if(repeatChar == NULL)
        {
            std::cout << "Did not find repeat char" << std::endl;
        }
    }
}
