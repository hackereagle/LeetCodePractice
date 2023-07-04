#include <iostream>
#include <string>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int minPathSum(std::vector<std::vector<int>>& grid) {
		//PrintGrid(grid); // debug
		int rows = grid.size(), cols = grid[0].size();
		for (int i = 1; i < cols; i++)
			grid[0][i] = grid[0][i] + grid[0][i - 1];

		for (int i = 1; i < rows; i++)
			grid[i][0] = grid[i][0] + grid[i - 1][0];

		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < cols; j++) {
				grid[i][j] = grid[i][j] + std::min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		//PrintGrid(grid); // debug

		return grid[rows - 1][cols - 1] ;
	}

private:
	void PrintGrid(std::vector<std::vector<int>> &grid)
	{
		std::cout << "{";
		for (auto &r : grid) {
			std::cout << "[";
			for (auto &e : r) {
				std::cout << e << " ";
			}
			std::cout << "]" << std::endl;
		}
		std::cout << "}" << std::endl;
	}
};

class TestMinPathSum
{
public:
	TestMinPathSum()
	{}

	~TestMinPathSum()
	{}

	void Example1()
	{
		std::vector<std::vector<int>> grid({{1,3,1},{1,5,1},{4,2,1}});
		int expectedMinSum = 7;
		std::cout << "===== Test grid = " << Vector2Str(grid) << ", output = " << expectedMinSum << " =====" << std::endl;

		int result = this->mSolution.minPathSum(grid);

		AssertClass::GetInstance().Assert(result == expectedMinSum);
	}
	
	void Example2()
	{
		std::vector<std::vector<int>> grid({{1,2,3},{4,5,6}});
		int expectedMinSum = 12;
		std::cout << "===== Test grid = " << Vector2Str(grid) << ", output = " << expectedMinSum << " =====" << std::endl;

		int result = this->mSolution.minPathSum(grid);

		AssertClass::GetInstance().Assert(result == expectedMinSum);
	}

	void Example3()
	{
		std::vector<std::vector<int>> grid({{1}});
		int expectedMinSum = 1;
		std::cout << "===== Test grid = " << Vector2Str(grid) << ", output = " << expectedMinSum << " =====" << std::endl;

		int result = this->mSolution.minPathSum(grid);

		AssertClass::GetInstance().Assert(result == expectedMinSum);
	}

	void Example4()
	{
		std::vector<std::vector<int>> grid({{0,7,7,8,1,2,4,3,0,0,5,9,8,3,6,5,1,0},{2,1,1,0,8,1,3,3,9,9,5,8,7,5,7,5,5,8},{9,2,3,1,2,8,1,2,3,7,9,7,9,3,0,0,3,8},{3,9,3,4,8,1,2,6,8,9,3,4,9,4,8,3,6,2},{3,7,4,7,6,5,6,5,8,6,7,3,6,2,2,9,9,3},{2,3,1,1,5,4,7,4,0,7,7,6,9,1,5,5,0,3},{0,8,8,8,4,7,1,0,2,6,1,1,1,6,4,2,7,9},{8,6,6,8,3,3,5,4,6,2,9,8,6,9,6,6,9,2},{6,2,2,8,0,6,1,1,4,5,3,1,7,3,9,3,2,2},{8,9,8,5,3,7,5,9,8,2,8,7,4,4,1,9,2,2},{7,3,3,1,0,9,4,7,2,3,2,6,7,1,7,7,8,1},{4,3,2,2,7,0,1,4,4,4,3,8,6,2,1,2,5,4},{1,9,3,5,4,6,4,3,7,1,0,7,2,4,0,7,8,0},{7,1,4,2,5,9,0,4,1,4,6,6,8,9,7,1,4,3},{9,8,6,8,2,6,5,6,2,8,3,2,8,1,5,4,5,2},{3,7,8,6,3,4,2,3,5,1,7,2,4,6,0,2,5,4},{8,2,1,2,2,6,6,0,7,3,6,4,5,9,4,4,5,7}});
		int expectedMinSum = 91;
		std::cout << "===== Test grid = " << Vector2Str(grid) << ", output = " << expectedMinSum << " =====" << std::endl;

		int result = this->mSolution.minPathSum(grid);

		AssertClass::GetInstance().Assert(result == expectedMinSum);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMinPathSum test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}