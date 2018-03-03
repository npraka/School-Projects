#include "GreedyRobot.h"
#include <iostream>
#include <string>
using namespace std;

GreedyRobot::GreedyRobot()
{
	int x1, y1, x2, y2;
	cout << "Enter the coordinate positions for both the GreedyRobot starting point and the Treasure respectively." << endl;
	cin >> x1 >> y1 >> x2 >> y2;

	xDist = x2 - x1;
	yDist = y2 - y1;

	FindTreasure(xDist, yDist, count, path);
	cout << "Number of paths: " << count << endl;
}


GreedyRobot::~GreedyRobot()
{
}

GreedyRobot::GreedyRobot(const int x1, const int y1, const int x2, const int y2)
{
	xDist = x2 - x1;
	yDist = y2 - y1;

	FindTreasure(xDist, yDist, count, path);
	cout << "Number of paths: " << count << endl;
}



void GreedyRobot::FindTreasure(int x, int y, int &count, string &path)
{
	if (y != 0)
	{
		if (y > 0)
		{
			moveNorth();
			FindTreasure(x, y - 1, count, path);
			path.pop_back();

		}
		else
		{
			moveSouth();
			FindTreasure(x, y + 1, count, path);
			path.pop_back();
		}
	}

	if (x != 0)
	{
		if (x > 0)
		{
			moveEast();
			FindTreasure(x - 1, y, count, path);
			path.pop_back();
		}
		else
		{
			moveWest();
			FindTreasure(x + 1, y, count, path);
			path.pop_back();
		}
	}
	if (x == 0 && y == 0)
	{
		count++;
		cout << path << endl;
	}
}

void GreedyRobot::moveNorth()
{
	path += "N";
}
void GreedyRobot::moveSouth()
{
	path += "S";
}
void GreedyRobot::moveWest()
{
	path += "W";
}
void GreedyRobot::moveEast()
{
	path += "E";
}