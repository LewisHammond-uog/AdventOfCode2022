// Day 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

#define LETTER_POS 1
#define BLOCK_LEN 3
#define BLOCK_LEN_WITH_SPACE BLOCK_LEN + 1
#define BLOCK_STACK_COUNT 9


int main()
{
    std::string lineString;
    std::ifstream inFileStacks;
    std::ifstream inFileInstructions;

    inFileStacks.open("input_blocks.txt");
    inFileInstructions.open("input_instructions.txt");

    if (!inFileStacks.is_open() << !inFileInstructions.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return -1;
    }

    std::stack < std::string > stacks[BLOCK_STACK_COUNT];


    //Read stacks
    while (getline(inFileStacks, lineString)) 
    {
        int currentStack = 0;
        for (int i = 0; i < lineString.length(); i += BLOCK_LEN_WITH_SPACE)
        {
            if (lineString[i] == ' ') {
                ++currentStack;
                continue;
            }
            
            std::string item = std::string(1, lineString[i + LETTER_POS]);

            stacks[currentStack].push(item);
            ++currentStack;
        }
    }
    inFileStacks.close();

    //Read and execute instructions
  
    while (getline(inFileInstructions, lineString))
    {
        int numToMove = 0;
        int stackFrom = 0;
        int stackTo = 0;

        sscanf_s(lineString.c_str(), "move %i from %i to %i", &numToMove, &stackFrom, &stackTo);

        for (int i = 0; i < numToMove; ++i) 
        {
            //-1 because instructions are 1 indexed, stacks are 0 indexed
            std::string moveChar = stacks[stackFrom - 1].top();
            stacks[stackFrom - 1].pop();

            stacks[stackTo - 1].push(moveChar);
        }
    }
    inFileInstructions.close();

    //List the tops of each stack
    for (int i = 0; i < BLOCK_STACK_COUNT; ++i) 
    {
        std::cout << stacks[i].top();
    }
}

