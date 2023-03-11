#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "IUniquePathsII.hpp"

class UniquePathsIIUsingDpClass : public IUniquePathsII
{
public:
	UniquePathsIIUsingDpClass();
	~UniquePathsIIUsingDpClass();

	int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) override { 
		std::vector<std::vector<int>> dp(obstacleGrid.size(), std::vector<int>(obstacleGrid[0].size(), - 1)); 

		// initialize 
		int rows = obstacleGrid.size(), cols = obstacleGrid[0].size(); 
		bool encounterObstacle = false; 
		for (int i = 0; i < rows; i++) { 
			if (obstacleGrid[i][0] == 0 && !encounterObstacle) 
				dp[i][0] = 1; 
			else { 
				encounterObstacle = true; 
				dp[i][0] = 0; 
			} 
		} 

		encounterObstacle = false; 
		for (int i = 0; i < cols; i++) { 
			if (obstacleGrid[0][i] == 0 && !encounterObstacle) 
				dp[0][i] = 1; 
			else { 
				encounterObstacle = true; 
				dp[0][i] = 0;  
			} 
		} 

		//this->Print2DVector(obstacleGrid); // debug 
		//this->Print2DVector(dp); // debug 
		return helper(obstacleGrid, dp, rows - 1, cols - 1); 
	} 

private: 
	int helper(std::vector<std::vector<int>> &map, std::vector<std::vector<int>> &dp, int m, int n) 
	{ 
		if (dp[m][n] != -1) 
			return dp[m][n]; 

		if (map[m][n] == 1) 
			dp[m][n] = 0; 
		else 
			dp[m][n] = helper(map, dp, m - 1, n) + helper(map, dp, m, n - 1); 

		return dp[m][n]; 
	} 
	void Print2DVector(std::vector<std::vector<int>> &vec) 
	{ 
		std::cout << "["; 
		for (auto r : vec) { 
			std::cout << "["; 
			for (auto c : r) 
				std::cout << " " << c; 
			std::cout << "]" << std::endl; 
		} 
		std::cout << "]" << std::endl; 
	}
};

