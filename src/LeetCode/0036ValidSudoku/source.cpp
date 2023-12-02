#include <iostream>
#include <string>
#include <vector>
#include "OtherMiscs.hpp"
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	bool isValidSudoku(std::vector<std::vector<char>>& board) {
		bool valid = true;

		std::vector<std::vector<bool>> rowUsedNum(9, std::vector<bool>(10, false));
		std::vector<std::vector<bool>> colUsedNum(9, std::vector<bool>(10, false));
		std::vector<std::vector<bool>> blockUsedNum(9, std::vector<bool>(10, false));

		int blockRow = 0, blockCol = 0, blockOrder = 0;
		int num = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					num = (int)board[i][j] - (int)'0';
					
					blockRow = i / 3;
					blockCol = j / 3;
					blockOrder = blockRow * 3 + blockCol;
					//std::cout << "board[" << i << "][" << j << "] = " << num << ", block row = " << blockRow << ", block col = " << blockCol << ", block order = " << blockOrder << std::endl;
					if (rowUsedNum[i][num] || colUsedNum [j][num] || blockUsedNum [blockOrder][num]) {
						valid = false;
						break;
					}
	
					rowUsedNum[i][num] = true;
					colUsedNum[j][num] = true;
					blockUsedNum[blockOrder][num] = true;
				}
			}
		}
		return valid;
	}
};

class TestIsValidSudoku
{
public:
	TestIsValidSudoku()
	{}

	~TestIsValidSudoku()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<char>> board = 
		{{'5','3','.','.','7','.','.','.','.'}
		,{'6','.','.','1','9','5','.','.','.'}
		,{'.','9','8','.','.','.','.','6','.'}
		,{'8','.','.','.','6','.','.','.','3'}
		,{'4','.','.','8','.','3','.','.','1'}
		,{'7','.','.','.','2','.','.','.','6'}
		,{'.','6','.','.','.','.','2','8','.'}
		,{'.','.','.','4','1','9','.','.','5'}
		,{'.','.','.','.','8','.','.','7','9'}};
		bool expectedOutput = true;
		std::cout << "===== Test board = \n" << Vector2Str(board) << "; \noutput = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		bool result = this->mSolution.isValidSudoku(board);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}
	
	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<char>> board = 
		{{'8','3','.','.','7','.','.','.','.'}
		,{'6','.','.','1','9','5','.','.','.'}
		,{'.','9','8','.','.','.','.','6','.'}
		,{'8','.','.','.','6','.','.','.','3'}
		,{'4','.','.','8','.','3','.','.','1'}
		,{'7','.','.','.','2','.','.','.','6'}
		,{'.','6','.','.','.','.','2','8','.'}
		,{'.','.','.','4','1','9','.','.','5'}
		,{'.','.','.','.','8','.','.','7','9'}};
		bool expectedOutput = false;
		std::cout << "===== Test board = \n" << Vector2Str(board) << "; \noutput = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		bool result = this->mSolution.isValidSudoku(board);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestIsValidSudoku test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}