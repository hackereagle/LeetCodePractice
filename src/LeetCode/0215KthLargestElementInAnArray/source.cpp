#include <iostream>
#include <string>
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
	
	int findKthLargest(std::vector<int>& nums, int k) { 
		int ret = 0; 
		RadixSort(nums); 
		//PrintVector(nums); // debug 
		ret = nums[nums.size() - k]; 
		return ret; 
	} 
private: 
	const int ZERO_INDEX = 9; 
	void RadixSort(std::vector<int> &nums) 
	{ 
		int radix = 1; 
		int len = nums.size(); 
		std::vector<int> bucket[19]; // -9 ~ +9 
		int zeroCount = 0; 
		while (zeroCount != len) { 
			zeroCount = 0; 
			for (auto &n : nums) { 
				int idx = ((n / radix) % 10) + 9; 
				bucket[idx].push_back(n); 
				if (n < radix) 
					zeroCount = zeroCount + 1; 
			} 
			int index = 0; 
			for (int i = 0; i < 19; i++) { 
				for (auto &b : bucket[i]) { 
					nums[index] = b; 
					index = index + 1; 
				} 
				bucket[i].clear(); 
			} 
			radix = radix * 10; 
		} 
	} 
	void PrintVector(std::vector<int> &nums) { 
		std::cout << "["; 
		for (auto &n : nums) { 
			std::cout << " " << n; 
		} 
		std::cout << "]" << std::endl; 
	}
};

class TestIsValid
{
public:
	TestIsValid()
	{}

	~TestIsValid()
	{}

	void Example1()
	{
		// arrange
		std::vector<int> nums({3,2,1,5,6,4});
		int k = 2;
		int expected = 5;
		std::cout << "===== Test input " << Vector2Str(nums) << ", k = " << k << ", expectecd output = " << expected << " =====" << std::endl;

		// action
		int result = this->mSolution.findKthLargest(nums, k);

		// assert
		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		// arrange
		std::vector<int> nums({3,2,3,1,2,4,5,5,6});
		int k = 4;
		int expected = 4;
		std::cout << "===== Test input " << Vector2Str(nums) << ", k = " << k << ", expectecd output = " << expected << " =====" << std::endl;

		// action
		int result = this->mSolution.findKthLargest(nums, k);

		// assert
		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		// arrange
		std::vector<int> nums({3,2,1,5,6,4});
		int k = 6;
		int expected = 1;
		std::cout << "===== Test input " << Vector2Str(nums) << ", k = " << k << ", expectecd output = " << expected << " =====" << std::endl;

		// action
		int result = this->mSolution.findKthLargest(nums, k);

		// assert
		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		// arrange
		std::vector<int> nums({-1,-1});
		int k = 2;
		int expected = -1;
		std::cout << "===== Test input " << Vector2Str(nums) << ", k = " << k << ", expectecd output = " << expected << " =====" << std::endl;

		// action
		int result = this->mSolution.findKthLargest(nums, k);

		// assert
		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestIsValid test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}