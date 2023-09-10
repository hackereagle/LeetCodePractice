#pragma once

#include "IGameOfLife.hpp"

class GameOfLifeInPlace : public IGameOfLife
{
public:
	~GameOfLifeInPlace() {}
	virtual void gameOfLife(std::vector<std::vector<int>> &board) override
	{
		int row = board.size();
        int col = board[0].size();
        int liveCount = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                liveCount = StatisticsNeighbors(board, i, j);
                board[i][j] = NextGeneration(board[i][j], liveCount);
            }
        }
        //PrintBoard(board);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 3)
                    board[i][j] = 0;
                else if (board[i][j] == 4)
                    board[i][j] = 1;
            }
        }
	}

private:
    const int offset[8][2] {{-1, -1}, {-1, 0}, {-1, 1},
                            { 0, -1},          { 0, 1},
                            { 1, -1}, { 1, 0}, { 1, 1}};

    int StatisticsNeighbors(std::vector<std::vector<int>>& board, int curRow, int curCol)
    {
        int liveCount = 0;

        int row = 0, col = 0;
        int cellState = 0;
        for (int i = 0; i < 8; i++) {
            row = curRow + offset[i][0];
            col = curCol + offset[i][1];

            if ((row >= 0 && row < board.size()) &&
                (col >= 0 && col < board[0].size())) {
                cellState = board[row][col];
                if (cellState == 1 || cellState == 3)
                    liveCount = liveCount + 1;
            }
        }

        return liveCount;
    }

    int NextGeneration(int curVal, int liveCount)
    {
        int nextGen = curVal;
        
        if (curVal == 1) {
            if (liveCount < 2) {
                nextGen = 3;
            }
            else if (liveCount > 3) {
                nextGen = 3;
            }
        }
        else {
            if (liveCount == 3) {
                nextGen = 4;
            }
        }
        //std::cout << "cur = " << curVal << ", live neighbors = " << liveCount << ", die neighbors = " << 8 - liveCount << ", next generation = " << nextGen << std::endl;

        return nextGen;
    }

    void PrintBoard(std::vector<std::vector<int>> &board)
    {
        for (auto r : board) {
            for (auto c : r) {
                std::cout << c << " ";
            }
            std::cout << std::endl;
        }
    }
};