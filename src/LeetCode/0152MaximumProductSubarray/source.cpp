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
	
	int maxProduct(std::vector<int>& nums) {
		int maxProd = nums[0];
		int curMax = 1;
		int curMin = 1;
		for (auto &n : nums) {
			if (n < 0)
				std::swap(curMin, curMax);
			
			curMax = std::max(curMax * n, n);
			curMin = std::min(curMin * n, n);
			maxProd = std::max(curMax, maxProd);
		}
		return maxProd;
	}
};

class TestMaxProduct
{
public:
	TestMaxProduct()
	{}

	~TestMaxProduct()
	{}

	void Example1()
	{
		std::vector<int> nums({2,3,-2,4});
		int expected = 6;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << expected << " =====" << std::endl;

		int result = this->mSolution.maxProduct(nums);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		std::vector<int> nums({-2,0,-1});
		int expected = 0;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << expected << " =====" << std::endl;

		int result = this->mSolution.maxProduct(nums);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		std::vector<int> nums({1,2,3,4});
		int expected = 24;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << expected << " =====" << std::endl;

		int result = this->mSolution.maxProduct(nums);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		std::vector<int> nums({1,-2,3,-4});
		int expected = 24;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << expected << " =====" << std::endl;

		int result = this->mSolution.maxProduct(nums);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example5()
	{
		std::vector<int> nums({-2});
		int expected = -2;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << expected << " =====" << std::endl;

		int result = this->mSolution.maxProduct(nums);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example6()
	{
		std::vector<int> nums({-4,-3});
		int expected = 12;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << expected << " =====" << std::endl;

		int result = this->mSolution.maxProduct(nums);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example7()
	{
		std::vector<int> nums({0,2});
		int expected = 2;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << expected << " =====" << std::endl;

		int result = this->mSolution.maxProduct(nums);

		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMaxProduct test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	getchar();
	return EXIT_SUCCESS;
}