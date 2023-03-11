#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "IUniquePathsII.hpp"

class UniquePathsIIUsingBfsClass : public IUniquePathsII
{
public:
	UniquePathsIIUsingBfsClass() {}

	~UniquePathsIIUsingBfsClass() {}

	int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
		int count = 0;

		Point goal(obstacleGrid[0].size() - 1, obstacleGrid.size() - 1);
		std::queue<Point> next;
		if (obstacleGrid[0][0] == 0)
			next.push(Point(0, 0));
			
		while (next.size() > 0) {
			Point cur = next.front();
			next.pop();

			if (cur == goal) {
				count = count + 1;
			}
			else
			{
				if ((cur.X + 1) < obstacleGrid[0].size() && 
					obstacleGrid[cur.Y][cur.X + 1] == 0)
					next.push(Point(cur.X + 1, cur.Y));

				if ((cur.Y + 1) < obstacleGrid.size() &&
					obstacleGrid[cur.Y + 1][cur.X] == 0)
					next.push(Point(cur.X, cur.Y + 1));
			}
		}

		return count;
	}

private:
	typedef struct point {
		int X = 0;
		int Y = 0;

		point(int x, int y) {
			this->X = x;
			this->Y = y;
		}

		point() = default;

		bool operator==(point &r) {
			return (this->X == r.X) && (this->Y == r.Y);
		}

		std::string ToString()
		{
			return "[" + std::to_string(this->X) + ", " + std::to_string(this->Y) + "]";
		}
	} Point;
};