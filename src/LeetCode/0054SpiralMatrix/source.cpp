#include <iostream>
#include <vector>
#include <string>
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
	
	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int size = rows * cols;
		std::vector<int> ret(size, 0);

		int rightBoundary = cols -1;
		int leftBoundary = 0;
		int topBoundary = 0;
		int bottomBoundary = rows - 1;

		int index = 0;
		while(index < size) {
			for (int i = leftBoundary; i <= rightBoundary && index < size; i++) {
				ret[index] = matrix[topBoundary][i];
				index = index + 1;
			}
			topBoundary = topBoundary + 1;

			for (int i = topBoundary; i <= bottomBoundary && index < size; i++) {
				ret[index] = matrix[i][rightBoundary];
				index = index + 1;
			}
			rightBoundary = rightBoundary - 1;

			for (int i = rightBoundary; i >= leftBoundary && index < size; i--) {
				ret[index] = matrix[bottomBoundary][i];
				index = index + 1;
			}
			bottomBoundary = bottomBoundary - 1;
			
			for (int i = bottomBoundary; i >= topBoundary && index < size; i--) {
				ret[index] = matrix[i][leftBoundary];
				index = index + 1;
			}
			leftBoundary = leftBoundary + 1;
		}

		return ret;
	}
};

class TestSpiralOrder
{
public:
	TestSpiralOrder()
	{}

	~TestSpiralOrder()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
		std::vector<int> expectedOutput({1,2,3,6,9,8,7,4,5});
		std::cout << "===== Test matrix " << Vector2Str(matrix) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<int> result = this->mSolution.spiralOrder(matrix);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
		std::vector<int> expectedOutput({1,2,3,4,8,12,11,10,9,5,6,7});
		std::cout << "===== Test matrix " << Vector2Str(matrix) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<int> result = this->mSolution.spiralOrder(matrix);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestSpiralOrder test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}