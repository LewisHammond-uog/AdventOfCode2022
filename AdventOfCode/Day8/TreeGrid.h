#pragma once

#include <string>
#include <map>

struct Vector2 {
	Vector2(int xVal, int yVal) 
	{
		x = xVal;
		y = yVal;
	}

	bool operator<(Vector2 other) const {
		return x < other.x || (x == other.x && y < other.y);
	}

	Vector2 operator+(Vector2 other) const {
		return Vector2(x + other.x, y + other.y);
	}

	int x;
	int y;
};

enum class Direction {
	Up,
	Down,
	Left,
	Right
};

class TreeGrid
{
public:
	TreeGrid(std::string gridString);
	bool TreeIsVisible(Vector2 loc);
	int CountVisibleTrees();

private:
	std::map<Vector2, int> grid;
	Vector2 maxBounds = Vector2(0,0);

	bool TreeIsVisibleInDir(Vector2 pos, Direction dir);
	bool PosIsInGrid(Vector2 pos);
};

