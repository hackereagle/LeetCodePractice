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
	
	void setZeroes(std::vector<std::vector<int>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();

		std::vector<bool> zerosRow(rows, false);
		std::vector<bool> zerosCol(cols, false);
		TagZerosPosition(matrix, zerosRow, zerosCol);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (zerosRow[i] || zerosCol[j]) {
					matrix[i][j] = 0;
				}
			}
		}
	}

private:
	void TagZerosPosition(std::vector<std::vector<int>> &matrix, std::vector<bool> &zerosRow, std::vector<bool> &zerosCol)
	{
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == 0) {
					zerosRow[i] = true;
					zerosCol[j] = true;
				}
			}
		}
	}
};

class TestSetZeroes
{
public:
	TestSetZeroes()
	{}

	~TestSetZeroes()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{1,1,1},{1,0,1},{1,1,1}});
		std::vector<std::vector<int>> expected({{1,0,1},{0,0,0},{1,0,1}});
		std::cout << "===== Test matrix = \n" << Vector2Str(matrix) << "; expected output \n" << Vector2Str(expected) << " =====" << std::endl;

		// ACT
		this->mSolution.setZeroes(matrix);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(matrix, expected));
	}

	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{0,1,2,0},{3,4,5,2},{1,3,1,5}});
		std::vector<std::vector<int>> expected({{0,0,0,0},{0,4,5,0},{0,3,1,0}});
		std::cout << "===== Test matrix = \n" << Vector2Str(matrix) << "; expected output \n" << Vector2Str(expected) << " =====" << std::endl;

		// ACT
		this->mSolution.setZeroes(matrix);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(matrix, expected));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestSetZeroes test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}