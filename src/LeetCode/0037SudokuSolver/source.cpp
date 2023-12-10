#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "ISudokuSolver.hpp"
#include "SolveSudokuWithForLoop.hpp"
#include "SolveSudokuWithRecursion.hpp"
#include "OtherMiscs.hpp"
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

enum class SudokuSolverMethod : int
{
	ForLoop,
	Recursion
};

class TestSolveSudoku
{
public:
	TestSolveSudoku(SudokuSolverMethod method = SudokuSolverMethod::Recursion)
	{
		if (SudokuSolverMethod::ForLoop == method) {
			this->_solution = std::make_unique<SolveSudokuWithForLoop>();
		}
		else if (SudokuSolverMethod::Recursion == method) {
			this->_solution = std::make_unique<SolveSudokuWithRecursion>();
		}
		else {
			std::cout << "Invalid method" << std::endl;
		}
	}

	~TestSolveSudoku()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<char>> board = 
		{{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}};
		std::vector<std::vector<char>> expectedOutput =
		{{'5','3','4','6','7','8','9','1','2'},
		{'6','7','2','1','9','5','3','4','8'},
		{'1','9','8','3','4','2','5','6','7'},
		{'8','5','9','7','6','1','4','2','3'},
		{'4','2','6','8','5','3','7','9','1'},
		{'7','1','3','9','2','4','8','5','6'},
		{'9','6','1','5','3','7','2','8','4'},
		{'2','8','7','4','1','9','6','3','5'},
		{'3','4','5','2','8','6','1','7','9'}};
		std::cout << "===== Test board = \n" << Vector2Str(board) << "; \noutput = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		this->_solution->solveSudoku(board);

		// ASSERT
		AssertClass::GetInstance().Assert(board == expectedOutput);
	}
	

private:
	std::unique_ptr<ISudokuSolver> _solution;
};

int main(int argc, char** argv)
{
	TestSolveSudoku test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}