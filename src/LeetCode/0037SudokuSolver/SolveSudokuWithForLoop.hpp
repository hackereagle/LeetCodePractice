#pragma once

#include <iostream>
#include "ISudokuSolver.hpp"

class SolveSudokuWithForLoop : public ISudokuSolver
{
public:
	SolveSudokuWithForLoop() {}
	virtual ~SolveSudokuWithForLoop() {}

	void solveSudoku(std::vector<std::vector<char>>& board) override
	{
		SolveSudokuHelper(board);
	}

private:
    bool SolveSudokuHelper(std::vector<std::vector<char>>& board)
    {
        //PrintVector(board);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    return TryNum(board, i, j);
                }
            }
        }

        // it is very important! If sudoku is solved, all cell will be filled number. So it need return trun.
        return true; 
    }

    bool TryNum(std::vector<std::vector<char>>& board, int row, int col)
    {
        for (int num = 0; num < 9; num++) {       
            if (IsValidSudoku(board, row, col, num)) {
                board[row][col] = (char)((int)'1' + num);

                if (SolveSudokuHelper(board))
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