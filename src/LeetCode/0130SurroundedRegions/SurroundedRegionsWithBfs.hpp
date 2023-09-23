#pragma once

#include <queue>
#include "ISurroundedRegions.hpp"

class SurroundedRegionswithBfs : public ISurroundedRegions
{
public:
	~SurroundedRegionswithBfs() override {}

	void solve(std::vector<std::vector<char>>& board) override 
	{
		_bRows = board.size();
		_bCols = board[0].size();
		std::vector<std::vector<bool>> visisted(_bRows, std::vector<bool>(_bCols, false));

		std::vector<std::vector<Point>> needChgRegs;
		for (int i = 0; i < _bRows; i++) {
			for (int j = 0; j < _bCols; j++) {
				if (!visisted[i][j] && board[i][j] == 'O') {
					CollectRegionWithBfs(board, i, j, visisted, needChgRegs);
				}
				else {
					visisted[i][j] = true;
				}
			}
		}

		for (auto &reg : needChgRegs) {
			for (auto &p : reg) {
				board[p.Row][p.Col] = 'X';
			}
		}
	}

private:
	typedef struct point {
		int Row = 0;
		int Col = 0;

		point() = default;
		point (int r, int c) : Row(r), Col(c) {}

		friend std::ostream& operator<<(std::ostream& os, const point& p)
		{
		  os << "[" << p.Row << ", " << p.Col << "]";
		  return os;
		}
	}Point;
	int _bRows = 0;
	int _bCols = 0;

	void CollectRegionWithBfs (std::vector<std::vector<char>> &board, int r, int c, std::vector<std::vector<bool>> &visisted, std::vector<std::vector<Point>> &needChgRegs)
	{
		bool needChg = true;
		std::vector<Point> reg;
		std::queue<Point> q;

		SetToNextStep(r, c, visisted, q, needChg); 
		Point cur;
		while (!q.empty()){
			cur = q.front();
			q.pop();

			reg.push_back(cur);

			if (cur.Row - 1 >= 0 && !visisted[cur.Row - 1][cur.Col] && board[cur.Row - 1][cur.Col] == 'O') {
				SetToNextStep(cur.Row - 1, cur.Col, visisted, q, needChg); 
			}

			if (cur.Row + 1 < _bRows && !visisted[cur.Row + 1][cur.Col] && board[cur.Row + 1][cur.Col] == 'O') {
				SetToNextStep(cur.Row + 1, cur.Col, visisted, q, needChg); 
			}

			if (cur.Col - 1 >= 0 && !visisted[cur.Row][cur.Col - 1] && board[cur.Row][cur.Col - 1] == 'O') {
				SetToNextStep(cur.Row, cur.Col - 1, visisted, q, needChg); 
			}

			if (cur.Col + 1 < _bCols && !visisted[cur.Row][cur.Col + 1] && board[cur.Row][cur.Col + 1] == 'O') {
				SetToNextStep(cur.Row, cur.Col + 1, visisted, q, needChg); 
			}
		}

		if (needChg) {
			//PrintPoints(reg); // debug
			needChgRegs.push_back(reg);
		}
	}

	void SetToNextStep(const int r, const int c, std::vector<std::vector<bool>> &visisted, std::queue<Point> &q, bool &needChg) {
		q.push(Point(r, c));
		visisted[r][c] = true;

		if (r == _bRows - 1 || r == 0) {
			needChg = false;
		}

		if (c == _bCols - 1 || c == 0) {
			needChg = false;
		}
	}

	void PrintPoints(std::vector<Point> &ps)
	{
	  for (auto &p : ps)
		std::cout << p << " ";
	  std::cout << std::endl;
	}
};