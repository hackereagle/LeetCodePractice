#include <iostream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int maximalSquare(std::vector<std::vector<char>>& matrix) {
		int rows = matrix.size(), cols = matrix[0].size();

		if (rows == 1 && cols == 1) {
			if (matrix[0][0] == '1') return 1;
			else return 0;
		}

		std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
		int maxSquareSize = 0;

		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] == '1') {
				dp[i][0] = 1;
				maxSquareSize = 1;
			}
		}

		for (int j = 0; j < cols; j++) {
			if (matrix[0][j] == '1') {
				dp[0][j] = 1;
				maxSquareSize = 1;
			}
		}

		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < cols; j++) {
				UpdateDpAndMaxSquare(matrix, dp, i, j, maxSquareSize);
			}
		}
		//PrintMatrix(dp);			

		return maxSquareSize * maxSquareSize;
	}

private:
	void UpdateDpAndMaxSquare(std::vector<std::vector<char>> &matrix, std::vector<std::vector<int>> &dp, int row, int col, int &maxSquareSize)
	{
		if (matrix[row][col] == '0') 
			return ;

		int left = dp[row][col - 1];
		int up = dp[row - 1][col];
		int diag = dp[row - 1][col - 1];
		if (left > 0 && up > 0 && diag > 0) {
			int preMinSize = std::min(left, up);
			preMinSize = std::min(preMinSize, diag);
			dp[row][col] = preMinSize + 1;
		}
		else {
			dp[row][col] = 1;
		}

		if (dp[row][col] > maxSquareSize){
			maxSquareSize = dp[row][col];
		}
	}

	void PrintMatrix(std::vector<std::vector<int>> &dp)
	{
		for (auto r : dp) {
			std::cout << "[";
			for (auto c : r) {
				std::cout << c << " ";
			}
			std::cout << "]\n";
		}
	}
};

class TestMaximalSquare
{
public:
	TestMaximalSquare()
	{}

	~TestMaximalSquare()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<char>> matrix({{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}});
		int expectedOutput = 4;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.maximalSquare(matrix);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<char>> matrix({{'0','1'},{'1','0'}});
		int expectedOutput = 1;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.maximalSquare(matrix);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMaximalSquare test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}