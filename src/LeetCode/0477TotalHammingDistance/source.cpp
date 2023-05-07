#include <iostream>
#include <string>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int totalHammingDistance(std::vector<int>& nums) {
		int totalHd = 0;

		int mask = 0;
		int bitOnCounter = 0;
		int len = nums.size();
		for (int i = 0; i < 32; i++) {
			mask = 1 << i;
			bitOnCounter = 0; 
			for (auto &n : nums) {
				if (n & mask)
					bitOnCounter = bitOnCounter + 1;
			}

			totalHd = totalHd + (bitOnCounter * (len - bitOnCounter));
		}

		return totalHd;
	}
};

class TestTotalHammingDistance
{
public:
	TestTotalHammingDistance()
	{}

	~TestTotalHammingDistance()
	{}

	void Example1()
	{
		std::vector<int> nums({4, 14, 2});
		int expectedOuptut = 6;
		std::cout << "===== Test input " << Vector2Str(nums) << ", output = " << expectedOuptut << " =====" << std::endl;

		int result = this->mSolution.totalHammingDistance(nums);

		AssertClass::GetInstance().Assert(result == expectedOuptut);
	}

	void Example2()
	{
		std::vector<int> nums({4, 14, 4});
		int expectedOuptut = 4;
		std::cout << "===== Test input " << Vector2Str(nums) << ", output = " << expectedOuptut << " =====" << std::endl;

		int result = this->mSolution.totalHammingDistance(nums);

		AssertClass::GetInstance().Assert(result == expectedOuptut);
	}

	void Example3()
	{
		std::vector<int> nums({4, 14, 2, 4, 15, 7});
		int expectedOuptut = 29;
		std::cout << "===== Test input " << Vector2Str(nums) << ", output = " << expectedOuptut << " =====" << std::endl;

		int result = this->mSolution.totalHammingDistance(nums);

		AssertClass::GetInstance().Assert(result == expectedOuptut);
	}

	void Example4()
	{
		std::vector<int> nums({1000000000, 99999999, 99999998});
		int expectedOuptut = 44;
		std::cout << "===== Test input " << Vector2Str(nums) << ", output = " << expectedOuptut << " =====" << std::endl;

		int result = this->mSolution.totalHammingDistance(nums);

		AssertClass::GetInstance().Assert(result == expectedOuptut);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestTotalHammingDistance test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}