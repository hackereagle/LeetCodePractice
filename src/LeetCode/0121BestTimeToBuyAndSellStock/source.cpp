#include <iostream>
#include <vector>
#include <string>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int maxProfit(std::vector<int>& prices) {
		int minPrice = 10001;
		int maxProfit = 0;

		size_t len = prices.size();
		int tmpProfit = 0;
		for (int i = 0; i < len; i++) {
			if (prices[i] < minPrice) {
				minPrice = prices[i];
			}
			else {
				tmpProfit = prices[i] - minPrice;
				if (tmpProfit > maxProfit) {
					maxProfit = tmpProfit;
				}
			}
		}

		return maxProfit;
	}
};

class TestMaxProfit
{
public:
	TestMaxProfit()
	{}

	~TestMaxProfit()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> prices({7,1,5,3,6,4});
		int expectedOutput = 5;
		std::cout << "===== Test prices = " << Vector2Str(prices) << "; output = " << expectedOutput << " true =====" << std::endl;

		// ACT
		int result = this->mSolution.maxProfit(prices);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> prices({7,1,5,3,6,4});
		int expectedOutput = 5;
		std::cout << "===== Test prices = " << Vector2Str(prices) << "; output = " << expectedOutput << " true =====" << std::endl;

		// ACT
		int result = this->mSolution.maxProfit(prices);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMaxProfit test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}