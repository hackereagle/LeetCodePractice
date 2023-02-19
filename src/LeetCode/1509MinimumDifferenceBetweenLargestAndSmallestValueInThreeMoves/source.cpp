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
	
	int minDifference(std::vector<int>& nums) {
		int minDiff = 0;

		//PrintVector(nums); // debug
		if (nums.size() <= 4) 
			return minDiff;

		std::sort(nums.begin(), nums.end());
		//std::cout << "After sorted:" << std::endl << "\t";
		//PrintVector(nums); // debug

		int min1 = nums[nums.size() - 1] - nums[3];
		int min2 = nums[nums.size() - 4] - nums[0];
		int min3 = nums[nums.size() - 2] - nums[2];
		int min4 = nums[nums.size() - 3] - nums[1];

		minDiff = min1 > min2 ? min2 : min1;
		minDiff = minDiff > min3 ? min3 : minDiff;
		minDiff = minDiff > min4 ? min4 : minDiff;

		return minDiff;

	}

private:
	void PrintVector(std::vector<int> vec)
	{
		std::cout << "[";
		for (auto v : vec) {
			std::cout << v << " ";
		}
		std::cout << "]" << std::endl;
	}
};

class TestMinDifference
{
public:
	TestMinDifference()
	{}

	~TestMinDifference()
	{}

	void Example1()
	{
		std::vector<int> nums({5,3,2,4});
		int diff = 0;
		std::cout << "===== Test input \"" << Vector2Str(nums) << "\", min difference = " << diff << " =====" << std::endl;

		int reslut = this->mSolution.minDifference(nums);

		AssertClass::GetInstance().Assert(reslut == diff);
	}

	void Example2()
	{
		std::vector<int> nums({1,5,0,10,14});
		int diff = 1;
		std::cout << "===== Test input \"" << Vector2Str(nums) << "\", min difference = " << diff << " =====" << std::endl;

		int reslut = this->mSolution.minDifference(nums);

		AssertClass::GetInstance().Assert(reslut == diff);
	}

	void Example3()
	{
		std::vector<int> nums({3,100,20});
		int diff = 0;
		std::cout << "===== Test input \"" << Vector2Str(nums) << "\", min difference = " << diff << " =====" << std::endl;

		int reslut = this->mSolution.minDifference(nums);

		AssertClass::GetInstance().Assert(reslut == diff);
	}

	void Example4()
	{
		std::vector<int> nums({1,3,4,-10,-3});
		int diff = 1;
		std::cout << "===== Test input \"" << Vector2Str(nums) << "\", min difference = " << diff << " =====" << std::endl;

		int reslut = this->mSolution.minDifference(nums);

		AssertClass::GetInstance().Assert(reslut == diff);
	}

	void Example5()
	{
		std::vector<int> nums({3,5,5,5,5});
		int diff = 0;
		std::cout << "===== Test input \"" << Vector2Str(nums) << "\", min difference = " << diff << " =====" << std::endl;

		int reslut = this->mSolution.minDifference(nums);

		AssertClass::GetInstance().Assert(reslut == diff);
	}

	void Example6()
	{
		std::vector<int> nums({3,3,3,3,5,5,5,5});
		int diff = 2;
		std::cout << "===== Test input \"" << Vector2Str(nums) << "\", min difference = " << diff << " =====" << std::endl;

		int reslut = this->mSolution.minDifference(nums);

		AssertClass::GetInstance().Assert(reslut == diff);
	}

	void Example7()
	{
		std::vector<int> nums({3,3,5,6,9,7,9,9});
		int diff = 3;
		std::cout << "===== Test input \"" << Vector2Str(nums) << "\", min difference = " << diff << " =====" << std::endl;

		int reslut = this->mSolution.minDifference(nums);

		AssertClass::GetInstance().Assert(reslut == diff);
	}

	void Example8()
	{
		std::vector<int> nums({82,81,95,75,20});
		int diff = 1;
		std::cout << "===== Test input \"" << Vector2Str(nums) << "\", min difference = " << diff << " =====" << std::endl;

		int reslut = this->mSolution.minDifference(nums);

		AssertClass::GetInstance().Assert(reslut == diff);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMinDifference test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	test.Example8();
	getchar();
	return EXIT_SUCCESS;
}