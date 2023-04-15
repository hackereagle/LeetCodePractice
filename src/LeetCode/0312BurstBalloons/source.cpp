#include <iostream>
#include <vector>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int maxCoins(std::vector<int>& nums) { 
		int ret = 0; 

		std::vector<int> newNums = nums; 
		newNums.insert(newNums.begin(), 1); 
		newNums.push_back(1); 
		//this->PrintVector(newNums); // debug 

		size_t len = newNums.size(); 
		this->_dp = std::vector<std::vector<int>>(len, std::vector<int>(len, -1)); 
		ret = this->Helper(newNums, 1, len - 2, this->_dp); 
		//PrintVector(this->_dp); 

		return ret; 
	} 

private: 
	std::vector<std::vector<int>> _dp; 

	int Helper(std::vector<int> &nums, int l, int r, std::vector<std::vector<int>> &dp) 
	{ 
		//std::cout << "\t" << "[l, r] = [" << l << ", " << r << "]" << std::endl; // debug 
		 
		if (dp[l][r] != -1) 
			return dp[l][r]; 

		dp[l][r] = 0; 
		//std::cout << "\tBegin calculate!" << std::endl; // debug 
		for (int i = l; i <= r; i++) { 
			//std::cout << "\t\ti = " << i << ": " << nums[l - 1] << ", " << nums[i] << ", " << nums[r + 1] << std::endl; 
			int coins = (nums[l - 1] * nums[i] * nums[r + 1]) +  
					  this->Helper(nums, l, i - 1, dp) +  
					  this->Helper(nums, i + 1, r, dp); 
			dp[l][r] = std::max(dp[l][r], coins); 
			//std::cout << "\t\t" << "dp[" << l << "][" << r << "] = " << dp[l][r] << std::endl; // debug 
		} 
		//std::cout << "\t" << "dp[" << l << "][" << r << "] = " << dp[l][r] << std::endl; // debug 
		return dp[l][r]; 
	}

	void PrintVector(std::vector<int> &nums) 
	{ 
		std::cout << "["; 
		for (auto &n : nums) { 
			std::cout << " " << n; 
		} 
		std::cout << "]" << std::endl; 
	} 

	void PrintVector(std::vector<std::vector<int>> &nums) 
	{ 
		std::cout << "["; 
		for (auto &ns : nums) { 
			std::cout << "["; 
			for (auto &n : ns) 
				std::cout << " " << n; 
			std::cout << "]" << std::endl; 
		} 
		std::cout << "]" << std::endl; 
	}
};

class TestMaxCoins
{
public:
	TestMaxCoins()
	{}

	~TestMaxCoins()
	{}

	void Example1()
	{
		// arrange
		std::vector<int> nums({3, 1, 5, 8});
		int expected = 167;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output " << expected << " =====" << std::endl;

		// action
		int result = this->mSolution.maxCoins(nums);

		// assert
		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		// arrange
		std::vector<int> nums({1, 5});
		int expected = 10;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output " << expected << " =====" << std::endl;

		// action
		int result = this->mSolution.maxCoins(nums);

		// assert
		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		// arrange
		std::vector<int> nums({3});
		int expected = 3;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output " << expected << " =====" << std::endl;

		// action
		int result = this->mSolution.maxCoins(nums);

		// assert
		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		// arrange
		std::vector<int> nums({100, 90, 80, 30, 70, 90});
		int expected = 2139100;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output " << expected << " =====" << std::endl;

		// action
		int result = this->mSolution.maxCoins(nums);

		// assert
		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMaxCoins test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}