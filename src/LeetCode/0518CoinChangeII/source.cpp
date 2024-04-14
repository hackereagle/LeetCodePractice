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
	
	int change(int amount, std::vector<int>& coins) {
		size_t coinsLen = coins.size();
		std::vector<int> dp(amount + 1, 0);
		//std::cout << "rows = " << dp.size() << ", cols = " << dp[0].size() << std::endl;
		dp[0] = 1;
		int remain = 0;
		for (int i = 1; i <= coinsLen; i++) {
			for (int j = 1; j <= amount; j++) {
				//std::cout << i << " - th coin = " << coins[i - 1] << ", amount = " << j << ", remain = " << remain << 
				//		", last coins result = " << dp[i - 1][j]; // debug
				remain = j - coins[i - 1];
				if (remain >= 0) {
					dp[j] = dp[j] + dp[remain];
					//std::cout << ", remain result = " << dp[i][remain]; // debug
				}
				//std::cout << ", current result = " << dp[i][j] << std::endl; // debug
			}
		}
		return dp[amount];
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
		int amount = 5;
		std::vector<int> coins({1,2,5});
		int expectedOutput = 4;
		std::cout << "===== Test amount = " <<  amount << ", coins = " << Vector2Str(coins) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.change(amount, coins);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		int amount = 3;
		std::vector<int> coins({2});
		int expectedOutput = 0;
		std::cout << "===== Test amount = " <<  amount << ", coins = " << Vector2Str(coins) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.change(amount, coins);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		int amount = 10;
		std::vector<int> coins({10});
		int expectedOutput = 1;
		std::cout << "===== Test amount = " <<  amount << ", coins = " << Vector2Str(coins) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.change(amount, coins);
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