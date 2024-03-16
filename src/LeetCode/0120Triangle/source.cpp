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
	
	int minimumTotal(std::vector<std::vector<int>>& triangle) {
		int rows = triangle.size();
		//std::cout << "===== triangle rows = " << rows << "\n"; // debug
		std::vector<std::vector<int>> dp(rows);
		int minIndex = 0;
		for (int i = 0; i < rows; i++) {
			ComputeRowDp(triangle, i, dp, minIndex);
		}
		//PrintTriangle(dp); // debug
		return dp[rows - 1][minIndex];
	}

private:
	void ComputeRowDp(std::vector<std::vector<int>> &triangle, int row, std::vector<std::vector<int>> &dp, int &minIndex)
	{
		int len = triangle[row].size();
		dp[row] = std::vector<int>(len);
		//std::cout << "row = " << row << ", len = " << len << "\n"; // debug
		if (row == 0) {
			dp[0][0] = triangle[0][0];
			minIndex = 0;
			return;
		}
		dp[row][0] = dp[row - 1][0] + triangle[row][0];
		dp[row][len - 1] = dp[row - 1][len - 2] + triangle[row][len - 1];
		if (dp[row][0] < dp[row][len - 1])
			minIndex = 0;
		else
			minIndex = len - 1;
		int preRowLeft = 0, preRowRight = 0;
		for (int i = 1; i < len - 1; i++){
			preRowLeft = dp[row - 1][i - 1];
			preRowRight = dp[row - 1][i];
			dp[row][i] = std::min(preRowLeft + triangle[row][i], preRowRight + triangle[row][i]);
			if (dp[row][i] < dp[row][minIndex]) {
				minIndex = i;
			}
		}
	}

	void PrintTriangle(std::vector<std::vector<int>> & triangle)
	{
		for (auto &r : triangle) {
			for (auto &c : r) {
				std::cout << c << " ";
			}
			std::cout << "\n";
		}
	}
};

class TestMinimumTotal
{
public:
	TestMinimumTotal()
	{}

	~TestMinimumTotal()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<int>> triangle({{2},{3,4},{6,5,7},{4,1,8,3}});
		int expectedOutput = 11;
		std::cout << "===== Test triangle =  " << Vector2Str(triangle) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.minimumTotal(triangle);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<int>> triangle({{-10}});
		int expectedOutput = -10;
		std::cout << "===== Test triangle =  " << Vector2Str(triangle) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.minimumTotal(triangle);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::vector<std::vector<int>> triangle({{-1},{-2,-3}});
		int expectedOutput = -4;
		std::cout << "===== Test triangle =  " << Vector2Str(triangle) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.minimumTotal(triangle);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		std::vector<std::vector<int>> triangle({{-1},{2,3},{1,-1,-3}});
		int expectedOutput = -1;
		std::cout << "===== Test triangle =  " << Vector2Str(triangle) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.minimumTotal(triangle);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		std::vector<std::vector<int>> triangle({{2},{3,4},{6,5,9},{4,4,8,0}});
		int expectedOutput = 14;
		std::cout << "===== Test triangle =  " << Vector2Str(triangle) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.minimumTotal(triangle);
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
	TestMinimumTotal test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}