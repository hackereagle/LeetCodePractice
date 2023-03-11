#include <iostream>
#include <memory>
#include "IUniquePathsII.hpp"
#include "UniquePathsIIUsingBfsClass.hpp"
#include "UniquePathsIIUsingDpClass.hpp"
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

enum class UniquePathsIIMethod : int
{
	UsingBfs = 0,
	UsingDp = 1,
	Total
};

class TestUniquePathsWithObstacles
{
public:
	TestUniquePathsWithObstacles(UniquePathsIIMethod method = UniquePathsIIMethod::UsingDp)
	{
		std::unique_ptr<IUniquePathsII> bfs = std::make_unique<UniquePathsIIUsingBfsClass>();
		this->mSolutions.push_back(std::move(bfs));
		std::unique_ptr<IUniquePathsII> dp = std::make_unique<UniquePathsIIUsingDpClass>();
		this->mSolutions.push_back(std::move(dp));

		this->mMethod = method;
	}

	~TestUniquePathsWithObstacles()
	{}

	void Example1()
	{
		// Arrange
		std::vector<std::vector<int>> obstacleGrid({{0,0,0},{0,1,0},{0,0,0}});
		int expected = 2;
		std::cout << "===== Test input \"" << Vector2Str(obstacleGrid) << "\", output " << expected << "=====" << std::endl;

		// Act
		int reslut = this->mSolutions[(int)this->mMethod]->uniquePathsWithObstacles(obstacleGrid);

		// Assert
		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example2()
	{
		// Arrange
		std::vector<std::vector<int>> obstacleGrid({{0,1},{0,0}});
		int expected = 1;
		std::cout << "===== Test input \"" << Vector2Str(obstacleGrid) << "\", output " << expected << "=====" << std::endl;

		// Act
		int reslut = this->mSolutions[(int)this->mMethod]->uniquePathsWithObstacles(obstacleGrid);

		// Assert
		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example3()
	{
		// Arrange
		std::vector<std::vector<int>> obstacleGrid({{1}});
		int expected = 0;
		std::cout << "===== Test input \"" << Vector2Str(obstacleGrid) << "\", output " << expected << "=====" << std::endl;

		// Act
		int reslut = this->mSolutions[(int)this->mMethod]->uniquePathsWithObstacles(obstacleGrid);

		// Assert
		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example4()
	{
		// Arrange
		std::vector<std::vector<int>> obstacleGrid({{0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0},
													{0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0},
													{1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1},
													{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
													{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
													{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0},
													{0,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0},
													{1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0},
													{0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0},
													{0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
													{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
													{1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},
													{0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
													{0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
													{0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
													{0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
													{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
													{1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0},
													{0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,1,0},
													{0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
													{0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0},
													{0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,0},
													{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1},
													{0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0},
													{1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0},
													{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
													{0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0},
													{1,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1},
													{1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0}});
		int expected = 0;
		std::cout << "===== Test input \"" << Vector2Str(obstacleGrid) << "\", output " << expected << "=====" << std::endl;

		// Act
		int reslut = this->mSolutions[(int)this->mMethod]->uniquePathsWithObstacles(obstacleGrid);

		// Assert
		AssertClass::GetInstance().Assert(reslut == expected);
	}

private:
	std::vector<std::unique_ptr<IUniquePathsII>> mSolutions;
	UniquePathsIIMethod mMethod;
};

int main(int argc, char** argv)
{
	TestUniquePathsWithObstacles test(UniquePathsIIMethod::UsingDp);
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}