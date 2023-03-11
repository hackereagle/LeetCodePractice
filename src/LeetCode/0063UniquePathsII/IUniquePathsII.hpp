#pragma once 
#include <vector>

class IUniquePathsII
{
private:
	/* data */
public:
	virtual ~IUniquePathsII() {}
	virtual int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) = 0;
};

