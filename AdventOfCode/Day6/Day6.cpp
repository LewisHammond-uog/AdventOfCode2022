// Day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

#define MARKER_LOCATION 4

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

    int count = 0;
    char a;
    std::deque<char> charQueue;
    while (inFile >> a)
    {
        ++count;

        charQueue.push_back(a);

        //Check if the queue contains the current char, if it does not then we have a string of 4 unique characters
        bool hasDupes = false;
        if (charQueue.size() >= 4) {
            //Check there are no repeat characters in the queue
            for (int i = 0; i < charQueue.size(); ++i) 
            {
                if (std::count(charQueue.begin(), charQueue.end(), charQueue[i]) >= 2) 
                {
                    hasDupes = true;
                    break;
                }
            }
        }

        if (!hasDupes && charQueue.size() >= 4)
        {
            std::cout << count;
            break;
        }

        if (charQueue.size() >= 4) {
            charQueue.pop_front();
        }
    }


}