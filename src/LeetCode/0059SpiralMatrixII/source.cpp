#include <iostream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<std::vector<int>> generateMatrix(int n) {
		std::vector<std::vector<int>> res(n, std::vector<int>(n, 1));

		int size = n * n;
		int val = 1;
		int left = 0, right = n - 1, top = 0, bottom = n - 1;
		while (val <= size) {
			HorizontalMoving(res, top, left, right, val, 1);
			top = top + 1;

			VerticalMoving(res, right, top, bottom, val, 1);
			right = right - 1;

			HorizontalMoving(res, bottom, right, left, val, -1);
			bottom = bottom - 1;

			VerticalMoving(res, left, bottom, top, val, -1);
			left = left + 1;
		}

		return res;
	}

private:
	void HorizontalMoving(std::vector<std::vector<int>> &res, int row, int begin, int end, int &val, int step)
	{
		if (step > 0) {
			for (int i = begin; i <= end; i++) {
				res[row][i] = val;
				val = val + 1;
			}
		}
		else {
			for (int i = begin; i >= end; i--) {
				res[row][i] = val;
				val = val + 1;
			}
		}
	}

	void VerticalMoving(std::vector<std::vector<int>> &res, int col, int begin, int end, int &val, int step)
	{
		if (step > 0) {
			for (int i = begin; i <= end; i++) {
				res[i][col] = val;
				val = val + 1;
			}
		}
		else {
			for (int i = begin; i >= end; i--) {
				res[i][col] = val;
				val = val + 1;
			}
		}
	}
};

class TestGenerateMatrix
{
public:
	TestGenerateMatrix()
	{}

	~TestGenerateMatrix()
	{}

	void Example1()
	{
		int n = 3;
		std::vector<std::vector<int>> expected({{1,2,3},{8,9,4},{7,6,5}});
		std::cout << "===== Test n = " << n << ", expected output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.generateMatrix(n);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example2()
	{
		int n = 1;
		std::vector<std::vector<int>> expected({{1}});
		std::cout << "===== Test n = " << n << ", expected output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.generateMatrix(n);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example3()
	{
		int n = 10;
		std::vector<std::vector<int>> expected({{1,2,3,4,5,6,7,8,9,10},{36,37,38,39,40,41,42,43,44,11},{35,64,65,66,67,68,69,70,45,12},{34,63,84,85,86,87,88,71,46,13},{33,62,83,96,97,98,89,72,47,14},{32,61,82,95,100,99,90,73,48,15},{31,60,81,94,93,92,91,74,49,16},{30,59,80,79,78,77,76,75,50,17},{29,58,57,56,55,54,53,52,51,18},{28,27,26,25,24,23,22,21,20,19}});
		std::cout << "===== Test n = " << n << ", expected output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.generateMatrix(n);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestGenerateMatrix test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}