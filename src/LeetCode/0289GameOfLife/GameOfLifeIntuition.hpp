#pragma once

#include "IGameOfLife.hpp"

class GameOfLifeIntuition : public IGameOfLife
{
public:
	~GameOfLifeIntuition() {}
	virtual void gameOfLife(std::vector<std::vector<int>> &board) override
	{
		std::vector<std::vector<int>> dup(board);
        //PrintBoard(dup);

        int row = board.size();
        int col = board[0].size();
        int liveCount = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                liveCount = 0;
                StatisticsNeighbors(dup, i, j, liveCount);
                board[i][j] = NextGeneration(dup[i][j], liveCount);
            }
        }
	}

private:
    const int offset[8][2] {{-1, -1}, {-1, 0}, {-1, 1},
                            { 0, -1},          { 0, 1},
                            { 1, -1}, { 1, 0}, { 1, 1}};

    void StatisticsNeighbors(std::vector<std::vector<int>>& board, int curRow, int curCol, int& liveCount)
    {
        liveCount = 0;

        int row = 0, col = 0;
        int cellState = 0;
        for (int i = 0; i < 8; i++) {
            row = curRow + offset[i][0];
            col = curCol + offset[i][1];

            if ((row >= 0 && row < board.size()) &&
                (col >= 0 && col < board[0].size())) {
                cellState = board[row][col];
                if (cellState)
                    liveCount = liveCount + 1;
            }
        }
    }

    int NextGeneration(int curVal, int liveCount)
    {
        int nextGen = curVal;
        if (curVal == 1) {
            if (liveCount < 2) {
                nextGen = 0;
            }
            else if (liveCount == 2 || 
                     liveCount == 3) {
                nextGen = 1;
            }
            else if (liveCount > 3) {
                nextGen = 0;
            }
        }
        else {
            if (liveCount == 3) {
                nextGen = 1;
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