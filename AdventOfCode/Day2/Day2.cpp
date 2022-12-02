// Advent of Code Day 2
/*
Rock Paper Scissors is a game between two players.Each game contains many rounds; in each round, the players each simultaneously choose one of Rock, Paper, or Scissors using a hand shape.Then, a winner for that round is selected : Rock defeats Scissors, Scissors defeats Paper, and Paper defeats Rock.If both players choose the same shape, the round instead ends in a draw.

Appreciative of your help yesterday, one Elf gives you an encrypted strategy guide(your puzzle input) that they say will be sure to help you win. "The first column is what your opponent is going to play: A for Rock, B for Paper, and C for Scissors. The second column--" Suddenly, the Elf is called away to help with someone's tent.

The second column, you reason, must be what you should play in response : X for Rock, Y for Paper, and Z for Scissors.Winning every time would be suspicious, so the responses must have been carefully chosen.

The winner of the whole tournament is the player with the highest score.Your total score is the sum of your scores for each round.The score for a single round is the score for the shape you selected(1 for Rock, 2 for Paper, and 3 for Scissors) plus the score for the outcome of the round(0 if you lost, 3 if the round was a draw, and 6 if you won).

Since you can't be sure if the Elf is trying to help you or trick you, you should calculate the score you would get if you were to follow the strategy guide.

For example, suppose you were given the following strategy guide :

A Y
B X
C Z
This strategy guide predictsand recommends the following :

In the first round, your opponent will choose Rock(A), and you should choose Paper(Y).This ends in a win for you with a score of 8 (2 because you chose Paper + 6 because you won).
In the second round, your opponent will choose Paper(B), and you should choose Rock(X).This ends in a loss for you with a score of 1 (1 + 0).
The third round is a draw with both players choosing Scissors, giving you a score of 3 + 3 = 6.
In this example, if you were to follow the strategy guide, you would get a total score of 15 (8 + 1 + 6).

What would your total score be if everything goes exactly according to your strategy guide ?
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


#define ELF_ROCK "A"
#define ELF_PAPER "B"
#define ELF_SCISSORS "C"

#define PLAYER_ROCK "X"
#define PLAYER_PAPER "Y"
#define PLAYER_SCISSORS "Z"

#define ROCK_SCORE 1
#define PAPER_SCORE 2
#define SCISSORS_SCORE 3

#define LOSE_SCORE 0
#define DRAW_SCORE 3
#define WIN_SCORE 6

enum class Items {
    Rock,
    Paper,
    Scisors
};

enum class State 
{
    Win,
    Lose,
    Draw
};

std::map<Items, int> itemToScore = { {Items::Rock, ROCK_SCORE}, {Items::Paper, PAPER_SCORE}, {Items::Scisors, SCISSORS_SCORE} };

std::map<std::string, Items> charToItem = { {"A", Items::Rock},  {"B", Items::Paper}, {"C", Items::Scisors},
                                            {"X", Items::Rock }, { "Y", Items::Paper }, { "Z", Items::Scisors }};

//Get the winning item for a given item
std::map<Items, Items> GetCounterItem = { {Items::Rock, Items::Paper}, {Items::Paper, Items::Scisors}, {Items::Scisors, Items::Rock} };

State GetMatchResult(Items elfItem, Items playerItem);

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

    int totalScore = 0;
    std::string elfPlay, playerPlay;
    while (inFile >> elfPlay >> playerPlay)
    {
        Items elfItem = charToItem[elfPlay];
        Items playerItem = charToItem[playerPlay];

        totalScore += itemToScore[playerItem];

        State playerState = GetMatchResult(elfItem, playerItem);

        if (playerState == State::Win) 
        {
            totalScore += WIN_SCORE;
        }
        else if (playerState == State::Draw) 
        {
            totalScore += DRAW_SCORE;
        }
        else if (playerState == State::Draw)
        {
            totalScore += LOSE_SCORE;
        }
    }

    std::cout << totalScore << std::endl;

    inFile.close();
}

State GetMatchResult(Items elfItem, Items playerItem) 
{
    if (elfItem == playerItem) {
        return State::Draw;
    }
    else if (playerItem == GetCounterItem[elfItem]) { //If the player playeed the counter to the elf item
        return State::Win;
    }

    return State::Lose;
}