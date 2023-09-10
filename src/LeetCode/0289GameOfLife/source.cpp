#include <iostream>
#include <string>
#include <memory>
#include "IGameOfLife.hpp"
#include "GameOfLifeIntuition.hpp"
#include "GameOfLifeInPlace.hpp"
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

enum class GameOfLifeMethod : int
{
	Intuition,
	InPlace
};

class TestGameOfLife
{
public:
	TestGameOfLife(GameOfLifeMethod m = GameOfLifeMethod::InPlace)
	{
		if (GameOfLifeMethod::Intuition == m)
			this->_solution = std::make_unique<GameOfLifeIntuition>();
		else
			this->_solution = std::make_unique<GameOfLifeInPlace>();
	}

	~TestGameOfLife()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<int>> board({{0,1,0},{0,0,1},{1,1,1},{0,0,0}});
		std::vector<std::vector<int>> expectedOutput({{0,0,0},{1,0,1},{0,1,1},{0,1,0}});
		std::cout << "===== Test board = " << Vector2Str(board) << "; output " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		this->_solution->gameOfLife(board);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(board, expectedOutput));
	}

	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<int>> board({{1,1},{1,0}});
		std::vector<std::vector<int>> expectedOutput({{1,1},{1,1}});
		std::cout << "===== Test board = " << Vector2Str(board) << "; output " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		this->_solution->gameOfLife(board);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(board, expectedOutput));
	}

private:
	std::unique_ptr<IGameOfLife> _solution;
};

int main(int argc, char** argv)
{
	TestGameOfLife test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}