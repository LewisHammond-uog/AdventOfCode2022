#include "TreeGrid.h"

#include <iostream>
#include <vector>
#include <thread>
#include <future>

TreeGrid::TreeGrid(std::string gridString)
{
	int rowCount = 990;
	int collumCount = 99;

	maxBounds = Vector2(rowCount, collumCount);
	
	for (int x = 0; x < rowCount; x++)
	{
		for (int y = 0; y < collumCount; y++)
		{
			//Add y to end the to bypass /n for new lines
			grid.insert({ Vector2(x,y), gridString[y * rowCount + x + y] - '0'});
		}
	}
}

int TreeGrid::GetBestScore()
{
	std::vector<std::future<int>> futures;
	for (int x = 0; x < maxBounds.x; x++)
	{
		for (int y = 0; y < maxBounds.y; y++)
		{
			futures.push_back(std::async(std::launch::async, &TreeGrid::GetTreeScore, this, Vector2(x, y)));
		}
	}

	int bestScore = 0;
	for (int x = 0; x < maxBounds.x; x++)
	{
		for (int y = 0; y < maxBounds.y; y++)
		{
			bestScore = std::max(bestScore, futures[y * maxBounds.x + x].get());
		}
	}

	return bestScore;
}


int TreeGrid::GetTreeScore(Vector2 pos)
{
	int x = pos.x;
	int y = pos.y;

	int currentScore = GetTreeScoreInDir(Vector2(x, y), Direction::Up) *
		GetTreeScoreInDir(Vector2(x, y), Direction::Down) *
		GetTreeScoreInDir(Vector2(x, y), Direction::Left) *
		GetTreeScoreInDir(Vector2(x, y), Direction::Right);

	return currentScore;
}

int TreeGrid::GetTreeScoreInDir(Vector2 pos, Direction dir)
{
	int xMove = 0;
	int yMove = 0;

	if (dir == Direction::Up || dir == Direction::Down) {
		yMove = dir == Direction::Up ? -1 : 1;
	}
	else {
		xMove = dir == Direction::Left ? -1 : 1;
	}

	auto treeIter = grid.find(pos);
	if (treeIter == grid.end()) 
	{
		std::cout << "ERROR, invalid tree location" << std::endl;
		return false;
	}
	int targetTreeScore = treeIter->second;

	Vector2 currentPos = pos;
	currentPos = currentPos + Vector2(xMove, yMove);
	int freeSpaces = 0;
	while (PosIsInGrid(currentPos))
	{
		auto iter = grid.find(currentPos);
		if (iter == grid.end()) {
			std::cout << "ERROR, invalid pos" << std::endl;
			return 0;
		}

		++freeSpaces;
		int currentTreeScore = iter->second;
		if (currentTreeScore >= targetTreeScore) {
			return freeSpaces;
		}

		currentPos = currentPos + Vector2(xMove, yMove);

	}

	return freeSpaces;
	
}

bool TreeGrid::PosIsInGrid(Vector2 pos)
{
	return pos.x >= 0 && pos.y >= 0 && pos.x < maxBounds.x && pos.y < maxBounds.y;
}
