#include <iostream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int coinChange(std::vector<int>& coins, int amount) {
		std::sort(coins.begin(), coins.end(), std::less<int>());
		//PrintVector(coins); // debug
		
		std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());
		dp[0] = 0;
		for (int i = 1; i < dp.size(); i++) {
			//std::cout << "amount = " << i << ": \n"; // debug
			CalculateAmountCoins(i, dp, coins);
		}
		//PrintVector(dp);
		
		int numberOfCoins = -1;
		if (dp.back() != std::numeric_limits<int>::max())
			numberOfCoins = dp.back();
		return numberOfCoins;
	}

private:
	void CalculateAmountCoins(int amount, std::vector<int> &dp, std::vector<int> &coins)
	{
		int temp = 0;
		int remain = 0;
		for (auto c : coins) {
			remain = amount - c;
			if (remain >= 0 && dp[remain] != std::numeric_limits<int>::max()) {
				dp[amount] = std::min(dp[amount], 1 + dp[remain]);
			}
		}
	}

	void PrintVector(std::vector<int> &vec)
	{
		std::cout << "[";
		for(auto v : vec) {
			std::cout << v << " ";
		}
		std::cout << "]" << std::endl ;
	}
};

class TestCoinChange
{
public:
	TestCoinChange()
	{}

	~TestCoinChange()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> coins({1,2,5});
		int amount = 11;
		int expectedOutput = 3;
		std::cout << "===== Test coins = " << Vector2Str(coins) << ", amount = " << amount << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.coinChange(coins, amount);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> coins({2});
		int amount = 3;
		int expectedOutput = -1;
		std::cout << "===== Test coins = " << Vector2Str(coins) << ", amount = " << amount << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.coinChange(coins, amount);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> coins({1});
		int amount = 0;
		int expectedOutput = 0;
		std::cout << "===== Test coins = " << Vector2Str(coins) << ", amount = " << amount << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.coinChange(coins, amount);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestCoinChange test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}