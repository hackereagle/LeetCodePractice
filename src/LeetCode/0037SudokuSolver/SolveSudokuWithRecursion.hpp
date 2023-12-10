#pragma once

#include <iostream>
#include "ISudokuSolver.hpp"

class SolveSudokuWithRecursion : public ISudokuSolver
{
public:
	SolveSudokuWithRecursion() {}
	~SolveSudokuWithRecursion() {}
	void solveSudoku(std::vector<std::vector<char>>& board) override
	{
		SolveSudokuHelper(board, 0, 0);
	}

private:
	bool SolveSudokuHelper(std::vector<std::vector<char>>& board, int row, int col)
	{
		if (col == 9)
			return SolveSudokuHelper(board, row + 1, 0);

		if (row == 9)
			return true;
	
		if (board[row][col] != '.')
			return SolveSudokuHelper(board, row, col + 1);

		for (int num = 0; num < 9; num++) {
			if (IsValidSudoku(board, row, col, num)) {
				board[row][col] = num + '1';
				if (SolveSudokuHelper(board, row, col + 1))
					return true;

				board[row][col] = '.';
			}
		}

		return false;
	}

	bool IsValidSudoku(std::vector<std::vector<char>> & board, int row, int col, int num)
	{
		for (int i = 0; i < 9; i++) 
			if ((board[row][i] - '1') == num) 
				return false;
		
		for (int i = 0; i < 9; i++)
			if ((board[i][col] - '1') == num)
				return false;

		int blockRow = row / 3;
		int blockCol = col / 3;
		int beginRow = blockRow * 3;
		int endRow = beginRow + 2;
		int beginCol = blockCol * 3;
		int endCol = beginCol + 2;
		for (int i = beginRow; i <= endRow; i++) {
			for (int j = beginCol; j <= endCol; j++) {
				if ((board[i][j] - '1') == num)
					return false;
			}
		}
		return true;
	}

	void PrintVector(std::vector<std::vector<char>> &board)
	{
		std::cout << "[";
		for (int i = 0; i < 9; i++) {
			std::cout << "[";
			for (int j = 0; j < 9; j++) {
				std::cout << (char)board[i][j] << " ";
			}
			std::cout << "]" << std::endl;
		}
		std::cout << "]" << std::endl;
	}
};