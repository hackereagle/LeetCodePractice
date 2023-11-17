#include <iostream>
#include <string>
#include <memory>
#include "IBestTimeToBuyAndSellStockII.hpp"
#include "BestTimeToBuyAndSellStockIIDp.hpp"
#include "BestTimeToBuyAndSellStockIIGreedy.hpp"
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

enum class SolutionType : int
{
	DP,
	Greedy
};

class TestMaxProfit
{
public:
	TestMaxProfit(SolutionType m = SolutionType::Greedy)
	{
		if (SolutionType::DP == m)
		{
			this->_solution = std::make_unique<BestTimeToBuyAndSellStockIIDp>();
		}
		else if (SolutionType::Greedy == m)
		{
			this->_solution = std::make_unique<BestTimeToBuyAndSellStockIIGreedy>();
		}
	}

	~TestMaxProfit()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> prices({7,1,5,3,6,4});
		int expectedOutput = 7;
		std::cout << "===== Test prices = " << Vector2Str(prices) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->_solution->maxProfit(prices);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> prices({1,2,3,4,5});
		int expectedOutput = 4;
		std::cout << "===== Test prices = " << Vector2Str(prices) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->_solution->maxProfit(prices);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> prices({7,6,4,3,1});
		int expectedOutput = 0;
		std::cout << "===== Test prices = " << Vector2Str(prices) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->_solution->maxProfit(prices);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	std::unique_ptr<IBestTimeToBuyAndSellStockII> _solution;
};

int main(int argc, char** argv)
{
	TestMaxProfit test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}