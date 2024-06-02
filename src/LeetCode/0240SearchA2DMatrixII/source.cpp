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
	
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
		int searchedSuccess = false;
		int rows = matrix.size(), cols = matrix[0].size();
		int r = 0, c = cols - 1;
		while (0 <= r && r < rows &&
			0<= c && c < cols) {
			if (matrix[r][c] == target) {
				searchedSuccess = true;
				break;
			}
			else if (matrix[r][c] > target) {
				c = c - 1;
			}
			else if (matrix[r][c] < target) {
				r = r + 1;
			}
		}

		return searchedSuccess;
	}
};

class TestSearchMatrix
{
public:
	TestSearchMatrix()
	{}

	~TestSearchMatrix()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}});
		int target = 5;
		bool expectedOutput = true;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", target = " << target << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.searchMatrix(matrix, target);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}});
		int target = 20;
		bool expectedOutput = false;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", target = " << target << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.searchMatrix(matrix, target);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{-5},{10},{20}});
		int target = 10;
		bool expectedOutput = true;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", target = " << target << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.searchMatrix(matrix, target);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{-5}});
		int target = -5;
		bool expectedOutput = true;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", target = " << target << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.searchMatrix(matrix, target);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{-5}});
		int target = 10;
		bool expectedOutput = false;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", target = " << target << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.searchMatrix(matrix, target);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example6()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{-5, 10, 20}});
		int target = 30;
		bool expectedOutput = false;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", target = " << target << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.searchMatrix(matrix, target);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example7()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{1,4},{2,5}});
		int target = 5;
		bool expectedOutput = true;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", target = " << target << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.searchMatrix(matrix, target);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example8()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{1,1}});
		int target = 0;
		bool expectedOutput = false;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", target = " << target << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.searchMatrix(matrix, target);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example9()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}});
		int target = 19;
		bool expectedOutput = true;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", target = " << target << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.searchMatrix(matrix, target);
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
	TestSearchMatrix test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	test.Example8();
	test.Example9();
	getchar();
	return EXIT_SUCCESS;
}