//** Advent of Code DAY 1 **
//The Elves take turns writing down the number of Calories contained by the various meals, snacks, rations, etc.that they've brought with them, one item per line. Each Elf separates their own inventory from the previous Elf's inventory(if any) by a blank line.
//
//For example, suppose the Elves finish writing their items' Calories and end up with the following list:
//
//1000
//2000
//3000
//
//4000
//
//5000
//6000
//
//7000
//8000
//9000
//
//10000
//This list represents the Calories of the food carried by five Elves :
//
//The first Elf is carrying food with 1000, 2000, and 3000 Calories, a total of 6000 Calories.
//The second Elf is carrying one food item with 4000 Calories.
//The third Elf is carrying food with 5000 and 6000 Calories, a total of 11000 Calories.
//The fourth Elf is carrying food with 7000, 8000, and 9000 Calories, a total of 24000 Calories.
//The fifth Elf is carrying one food item with 10000 Calories.
//In case the Elves get hungryand need extra snacks, they need to know which Elf to ask : they'd like to know how many Calories are being carried by the Elf carrying the most Calories. In the example above, this is 24000 (carried by the fourth Elf).
//
//Find the Elf carrying the most Calories.How many total Calories is that Elf carrying ?
//
//
//---------------------------------- Part Two ---------------------------------- 
//By the time you calculate the answer to the Elves' question, they've already realized that the Elf carrying the most Calories of food might eventually run out of snacks.
//
//To avoid this unacceptable situation, the Elves would instead like to know the total Calories carried by the top three Elves carrying the most Calories.That way, even if one of those Elves runs out of snacks, they still have two backups.
//
//In the example above, the top three Elves are the fourth Elf(with 24000 Calories), then the third Elf(with 11000 Calories), then the fifth Elf(with 10000 Calories).The sum of the Calories carried by these three elves is 45000.
//
//Find the top three Elves carrying the most Calories.How many Calories are those Elves carrying in total ?
//Your puzzle answer was 208191.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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

    std::vector<int> elfCalCounts; 
    int currentCalories = 0; //current count
    while (getline(inFile, lineString)) 
    { 
        //Empty line indicates new "elf"
        if (lineString.empty()) {
            elfCalCounts.push_back(currentCalories);
            currentCalories = 0;
        }

        //Add to the current count
        currentCalories += atoi(lineString.c_str());
    }

    inFile.close();

    std::sort(elfCalCounts.begin(), elfCalCounts.end());

    constexpr int TOP_COUNT = 3; //Number of top Calories to get
    int topSum = 0;

    //Start loop at 1 because we need to take 1 away from the size of the list because we don't
    //have an element at the end
    for(int i = 1; i <= TOP_COUNT; i++)
    {
        topSum += elfCalCounts[elfCalCounts.size() - i];
    }

    std::cout << "TOP Overall Cals: " << elfCalCounts[elfCalCounts.size() - 1] << std::endl;
    std::cout << "TOP " << TOP_COUNT << " Cals: " << topSum << std::endl;

    return 0;
}

