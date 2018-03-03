#pragma once
#include <iostream>
#include <string>
using namespace std;
class GreedyRobot
{
public:

	GreedyRobot();
	~GreedyRobot();
	GreedyRobot(const int x1, const int y1, const int x2,const int y2);
	void FindTreasure(int x, int y, int &count, string &path);


private:
	int xDist=0, yDist=0, count=0;
	string path;
	void moveNorth();
	void moveSouth();
	void moveWest();
	void moveEast();



};

