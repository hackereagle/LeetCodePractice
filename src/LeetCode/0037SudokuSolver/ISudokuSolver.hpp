#pragma once

#include <vector>
#include <string>

class ISudokuSolver
{
public:
	ISudokuSolver() {}
	virtual ~ISudokuSolver() {}
	virtual void solveSudoku(std::vector<std::vector<char>>& board) = 0;
};