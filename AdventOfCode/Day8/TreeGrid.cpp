#include "TreeGrid.h"

#include <iostream>

TreeGrid::TreeGrid(std::string gridString)
{
	int rowCount = 99;
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

bool TreeGrid::TreeIsVisible(Vector2 loc)
{
	return TreeIsVisibleInDir(loc, Direction::Up) || TreeIsVisibleInDir(loc, Direction::Down) || TreeIsVisibleInDir(loc, Direction::Left) || TreeIsVisibleInDir(loc, Direction::Right);
}

int TreeGrid::CountVisibleTrees()
{
	int count = 0;
	for (int x = 0; x < maxBounds.x; ++x) 
	{
		for (int y = 0; y < maxBounds.y; ++y)
		{
			count += (int)TreeIsVisible(Vector2(x,y));
		}
	}
	return count;
}

bool TreeGrid::TreeIsVisibleInDir(Vector2 pos, Direction dir)
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
	while (PosIsInGrid(currentPos))
	{
		auto iter = grid.find(currentPos);
		if (iter == grid.end()) {
			std::cout << "ERROR, invalid pos" << std::endl;
			return false;
		}

		int currentTreeScore = iter->second;
		if (currentTreeScore >= targetTreeScore) {
			return false;
		}

		currentPos = currentPos + Vector2(xMove, yMove);
	}

	return true;
	
}

bool TreeGrid::PosIsInGrid(Vector2 pos)
{
	return pos.x >= 0 && pos.y >= 0 && pos.x < maxBounds.x && pos.y < maxBounds.y;
}
