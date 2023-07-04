#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;

        int rows = grid.size(), cols = grid[0].size();
        std::vector<std::vector<bool>> visisted(rows, std::vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                //std::cout << "row = " << i << ", col = " << j << std::endl; // debug
                if (!visisted[i][j] && grid[i][j] == '1') {
                    Bfs(i, j, grid, visisted);
                    count = count + 1;
                }
            }
        }

        return count;
    }

private:
    struct Point
    {
        int Row = 0;
        int Col = 0;

        Point() = default;
        Point(int r, int c) : Row(r), Col(c) {}
    };

    void Bfs(int r, int c, std::vector<std::vector<char>> &grid, std::vector<std::vector<bool>> &visisted)
    {
        std::queue<struct Point> next;

        next.push(Point(r, c));
        visisted[r][c] = true;
        Point cur;
        while (next.size()) {
            cur = next.front();
            next.pop();
            //std::cout << "\tBFS, row = " << cur.Row << ", col = " << cur.Col << std::endl; // debug

            if (cur.Row < (grid.size() - 1) &&
                grid[cur.Row + 1][cur.Col] == '1' && !visisted[cur.Row + 1][cur.Col]) {
                next.push(Point(cur.Row + 1, cur.Col));
                visisted[cur.Row + 1][cur.Col] = true;
            }

            if (cur.Row > 0 &&
                grid[cur.Row - 1][cur.Col] == '1' && !visisted[cur.Row - 1][cur.Col]) {
                next.push(Point(cur.Row - 1, cur.Col));
                visisted[cur.Row - 1][cur.Col] = true;
            }

            if (cur.Col < (grid[0].size() - 1) &&
                grid[cur.Row][cur.Col + 1] == '1' && !visisted[cur.Row][cur.Col + 1]) {
                next.push(Point(cur.Row, cur.Col + 1));
                visisted[cur.Row][cur.Col + 1] = true;
            }

            if (cur.Col > 0 &&
                grid[cur.Row][cur.Col - 1] == '1' && !visisted[cur.Row][cur.Col - 1]) {
                next.push(Point(cur.Row, cur.Col - 1));
                visisted[cur.Row][cur.Col - 1] = true;
            }
        }
    }
};

class TestNumIslands
{
public:
	TestNumIslands()
	{}

	~TestNumIslands()
	{}

	void Example1()
	{
		std::vector<std::vector<char>> grid({
											{'1','1','1','1','0'},
											{'1','1','0','1','0'},
											{'1','1','0','0','0'},
											{'0','0','0','0','0'}
											});
		int expectedNumIsland = 1;
		std::cout << "===== Test grid = " << Vector2Str(grid) << ", output = " << expectedNumIsland << " =====" << std::endl;

		int result = this->mSolution.numIslands(grid);

		AssertClass::GetInstance().Assert(result == expectedNumIsland);
	}

	void Example2()
	{
		std::vector<std::vector<char>> grid({
											{'1','1','0','0','0'},
											{'1','1','0','0','0'},
											{'0','0','1','0','0'},
											{'0','0','0','1','1'}
											});
		int expectedNumIsland = 3;
		std::cout << "===== Test grid = " << Vector2Str(grid) << ", output = " << expectedNumIsland << " =====" << std::endl;

		int result = this->mSolution.numIslands(grid);

		AssertClass::GetInstance().Assert(result == expectedNumIsland);
	}

	void Example3()
	{
		std::vector<std::vector<char>> grid({
											{'1','1','1'},
											{'0','1','0'},
											{'1','1','1'}
											});
		int expectedNumIsland = 1;
		std::cout << "===== Test grid = " << Vector2Str(grid) << ", output = " << expectedNumIsland << " =====" << std::endl;

		int result = this->mSolution.numIslands(grid);

		AssertClass::GetInstance().Assert(result == expectedNumIsland);
	}

	void Example4()
	{
		std::vector<std::vector<char>> grid({
											{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},
											{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},
											{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},
											{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
											{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
											{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},
											{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},
											{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},
											{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},
											{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
											{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},
											{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
											{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
											{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},
											{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},
											{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},
											{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},
											{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
											{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
											{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
											});
		int expectedNumIsland = 1;
		std::cout << "===== Test grid = " << Vector2Str(grid) << ", output = " << expectedNumIsland << " =====" << std::endl;

		int result = this->mSolution.numIslands(grid);

		AssertClass::GetInstance().Assert(result == expectedNumIsland);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestNumIslands test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}