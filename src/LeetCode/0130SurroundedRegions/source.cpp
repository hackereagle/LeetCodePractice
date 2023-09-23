#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include "ISurroundedRegions.hpp"
#include "SurroundedRegionsWithRle.hpp"
#include "SurroundedRegionsWithBfs.hpp"
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

enum class SurroundMethod : int
{
	Rle,
	Bfs,
};

class TestSurroundedRegions
{
public:
	TestSurroundedRegions(SurroundMethod m = SurroundMethod::Rle)
	{
		if (SurroundMethod::Bfs == m)
			_solution = std::make_unique<SurroundedRegionswithBfs>();
		else
			_solution = std::make_unique<SurroundedRegionsWithRle>();
	}

	~TestSurroundedRegions()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<char>> board({{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}});
		std::vector<std::vector<char>> expected({{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}});
		std::cout << "===== Test board = \n" << Board2Str(board) << "; expected output = \n" << Board2Str(expected) << " =====" << std::endl;

		// ACT
		this->_solution->solve(board);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(board, expected));
	}

	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<char>> board({{'X'}});
		std::vector<std::vector<char>> expected({{'X'}});
		std::cout << "===== Test board = \n" << Board2Str(board) << "; expected output = \n" << Board2Str(expected) << " =====" << std::endl;

		// ACT
		this->_solution->solve(board);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(board, expected));
	}

	void Example3()
	{
		// ARRANGE
		std::vector<std::vector<char>> board({{'X','X','X','X'},
											{'X','O','O','X'},
											{'X','O','X','O'},
											{'X','O','X','X'}});
		std::vector<std::vector<char>> expected({{'X','X','X','X'},{'X','O','O','X'},{'X','O','X','O'},{'X','O','X','X'}});
		std::cout << "===== Test board = \n" << Board2Str(board) << "; expected output = \n" << Board2Str(expected) << " =====" << std::endl;

		// ACT
		this->_solution->solve(board);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(board, expected));
	}

	void Example4()
	{
		// ARRANGE
		std::vector<std::vector<char>> board({{'X','X','O','X','X'},
											{'X','O','X','X','O'},
											{'X','O','X','O','X'},
											{'X','O','O','O','X'},
											{'X','X','O','X','X'}});
		std::vector<std::vector<char>> expected({{'X','X','O','X','X'},{'X','O','X','X','O'},{'X','O','X','O','X'},{'X','O','O','O','X'},{'X','X','O','X','X'}});
		std::cout << "===== Test board = \n" << Board2Str(board) << "; expected output = \n" << Board2Str(expected) << " =====" << std::endl;

		// ACT
		this->_solution->solve(board);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(board, expected));
	}

	void Example5()
	{
		// ARRANGE
		std::vector<std::vector<char>> board({{'X','X','X','X'},
											{'O','X','O','X'},
											{'X','O','X','O'},
											{'X','O','X','X'}});
		std::vector<std::vector<char>> expected({{'X','X','X','X'},{'O','X','X','X'},{'X','O','X','O'},{'X','O','X','X'}});
		std::cout << "===== Test board = \n" << Board2Str(board) << "; expected output = \n" << Board2Str(expected) << " =====" << std::endl;

		// ACT
		this->_solution->solve(board);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(board, expected));
	}

	void Example6()
	{
		// ARRANGE
		std::vector<std::vector<char>> board({{'X','O','X','X','O','O','X','O','X','X','X','X','O','X','O','X','X','X','X','O'},{'O','X','O','O','X','O','X','O','X','X','X','X','X','X','O','X','X','O','X','X'},{'X','O','O','X','O','X','O','X','O','X','X','O','X','X','X','O','O','X','X','O'},{'O','X','X','O','O','X','X','O','X','X','X','X','O','O','X','O','O','O','X','X'},{'X','X','O','X','O','O','X','O','O','O','X','O','X','O','X','X','X','O','X','X'},{'O','O','O','O','X','O','X','X','O','O','X','O','O','X','O','X','X','X','X','O'},{'X','O','X','X','X','X','O','X','X','O','X','X','O','X','X','X','O','O','X','O'},{'O','X','X','O','O','O','X','O','O','X','O','X','X','X','O','O','X','X','O','X'},{'O','O','O','O','X','X','O','X','O','O','X','X','O','X','O','O','X','O','X','O'},{'O','O','X','X','X','O','X','O','X','O','X','X','X','O','X','X','X','X','X','O'},{'X','O','X','O','X','X','X','O','X','X','X','O','X','O','X','O','X','O','X','X'},{'O','O','X','X','X','X','O','X','X','X','O','X','O','O','O','X','X','X','O','X'},{'X','X','X','O','O','O','O','O','X','X','O','X','X','X','O','X','X','X','X','O'},{'O','O','X','X','X','O','O','X','O','O','X','X','X','X','X','X','O','X','X','O'},{'O','O','O','X','X','O','O','O','O','X','X','O','X','O','O','X','X','X','X','X'},{'O','X','X','X','O','X','O','O','X','X','X','X','X','O','X','X','X','O','O','X'},{'O','O','O','O','X','X','X','X','O','O','O','O','X','O','O','O','O','X','X','O'},{'X','X','X','X','X','X','X','X','X','X','O','X','X','O','X','X','X','X','X','X'},{'O','X','O','O','X','O','O','X','X','X','X','X','X','O','X','O','X','X','X','X'},{'O','O','X','X','X','X','X','O','O','O','X','X','X','X','X','X','O','X','X','O'}});
		std::vector<std::vector<char>> expected({{'X','O','X','X','O','O','X','O','X','X','X','X','O','X','O','X','X','X','X','O'},{'O','X','X','X','X','O','X','O','X','X','X','X','X','X','O','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','O'},{'O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X','X','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'O','O','O','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','O'},{'X','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','O'},{'O','X','X','O','O','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'O','O','O','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','O'},{'O','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','O'},{'X','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'O','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','O'},{'O','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','O'},{'O','O','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'O','O','O','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','O'},{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'O','O','X','X','X','X','X','O','O','O','X','X','X','X','X','X','O','X','X','O'}});
		std::cout << "===== Test board = \n" << Board2Str(board) << "; expected output = \n" << Board2Str(expected) << " =====" << std::endl;

		// ACT
		this->_solution->solve(board);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(board, expected));
	}

private:
	std::unique_ptr<ISurroundedRegions> _solution;

	std::string Board2Str(std::vector<std::vector<char>> &board)
	{
		std::ostringstream ss;
		for (auto r : board) {
            for (auto c : r) {
                ss << (char)c << " ";
            }
            ss << std::endl;
        }

		return ss.str();
	}
};

int main(int argc, char** argv)
{
	TestSurroundedRegions test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	getchar();
	return EXIT_SUCCESS;
}