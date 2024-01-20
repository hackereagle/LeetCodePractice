#include <iostream>
#include <vector>
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
	
	std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;

        if (n == 2 || n == 3)
            return ans;

        std::vector<std::string> board(n, std::string(n, '.'));
        _usedCol = std::vector<bool>(n, false);
        findNQueensSolutions(board, ans, 0, n);

        return ans;
    }

private:
    std::vector<bool> _usedCol;

    void findNQueensSolutions(std::vector<std::string> &board, std::vector<std::vector<std::string>> &ans, int row, const int n)
    {
        if (row == n)
            ans.push_back(board);

        int len = board.size();
        for (int j = 0; j < len; j++) {
            if (!_usedCol[j])
                TryPlaceQueen(row, j, board, ans, n);
        }
    }

    void TryPlaceQueen(int row, int col, std::vector<std::string> &board, std::vector<std::vector<std::string>> &ans, const int n)
    {
        if (board[row][col] == '.') {
            _usedCol[col] = true;
            board[row][col] = 'Q';
            if (IsValid(board, row, col))
                findNQueensSolutions(board, ans, row + 1, n);
            board[row][col] = '.';
            _usedCol[col] = false;
        }
    }

    bool IsValid(std::vector<std::string> &board, int QRow, int QCol)
    {
        return IsNoOtherQueenInSameDiag(board, QRow, QCol);
    }

    bool IsNoOtherQueenInSameDiag(std::vector<std::string> &board, int QRow, int QCol)
    {
        bool isNoOtherQueenInSameDiag = true;
        int row = QRow - 1, col = QCol - 1;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                isNoOtherQueenInSameDiag = false;
                break;
            }

            row = row - 1;
            col = col - 1;
        }

        if (isNoOtherQueenInSameDiag) {
            size_t len = board.size();
            row = QRow + 1, col = QCol + 1;
            while (row < len && col < len) {
                if (board[row][col] == 'Q') {
                    isNoOtherQueenInSameDiag = false;
                    break;
                }

                row = row + 1;
                col = col + 1;
            }
        }

        if (isNoOtherQueenInSameDiag) {
            size_t len = board.size();
            row = QRow - 1, col = QCol + 1;
            while (row >= 0 && col < len) {
                if (board[row][col] == 'Q') {
                    isNoOtherQueenInSameDiag = false;
                    break;
                }

                row = row - 1;
                col = col + 1;
            }
        }

        if (isNoOtherQueenInSameDiag) {
            size_t len = board.size();
            row = QRow + 1, col = QCol - 1;
            while (row < len && col >= 0) {
                if (board[row][col] == 'Q') {
                    isNoOtherQueenInSameDiag = false;
                    break;
                }

                row = row + 1;
                col = col - 1;
            }
        }
        return isNoOtherQueenInSameDiag;
    }
};

class TestSolveNQueens
{
public:
	TestSolveNQueens()
	{}

	~TestSolveNQueens()
	{}

	void Example1()
	{
		// ARRANGE
		int n = 4;
		std::vector<std::vector<std::string>> expectedOutput({{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}});
		std::cout << "===== Test n = " << n << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<std::string>> result = this->mSolution.solveNQueens(n);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example2()
	{
		// ARRANGE
		int n = 1;
		std::vector<std::vector<std::string>> expectedOutput({{"Q"}});
		std::cout << "===== Test n = " << n << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<std::string>> result = this->mSolution.solveNQueens(n);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example3()
	{
		// ARRANGE
		int n = 2;
		std::vector<std::vector<std::string>> expectedOutput;
		std::cout << "===== Test n = " << n << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<std::string>> result = this->mSolution.solveNQueens(n);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example4()
	{
		// ARRANGE
		int n = 3;
		std::vector<std::vector<std::string>> expectedOutput;
		std::cout << "===== Test n = " << n << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<std::string>> result = this->mSolution.solveNQueens(n);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example5()
	{
		// ARRANGE
		int n = 6;
		std::vector<std::vector<std::string>> expectedOutput({{".Q....","...Q..",".....Q","Q.....","..Q...","....Q."},{"..Q...",".....Q",".Q....","....Q.","Q.....","...Q.."},{"...Q..","Q.....","....Q.",".Q....",".....Q","..Q..."},{"....Q.","..Q...","Q.....",".....Q","...Q..",".Q...."}});
		std::cout << "===== Test n = " << n << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<std::string>> result = this->mSolution.solveNQueens(n);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestSolveNQueens test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}