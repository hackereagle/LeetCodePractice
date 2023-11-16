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
	
	bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
		bool containNearby = false;

		std::unordered_map<int, int> table;
		size_t len = nums.size();
		int diff = 0;
		for (int i = 0; i < len; i++) {
			if (table.find(nums[i]) == table.end()) {
				table.insert(std::pair<int, int>(nums[i], i));
			}
			else {
				diff = i - table[nums[i]];
				if (diff <= k) {
					containNearby = true;
					break;
				}
				else {
					table[nums[i]] = i;
				}
			}
		}
		return containNearby;
	}
};

class TestContainsNearbyDuplicate
{
public:
	TestContainsNearbyDuplicate()
	{}

	~TestContainsNearbyDuplicate()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> nums({1,2,3,1});
		int k = 3;
		bool expectedOutput = true;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", k = " << k << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution.containsNearbyDuplicate(nums, k);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> nums({1,0,1,1});
		int k = 1;
		bool expectedOutput = true;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", k = " << k << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution.containsNearbyDuplicate(nums, k);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> nums({1,2,3,1,2,3});
		int k = 2;
		bool expectedOutput = false;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", k = " << k << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution.containsNearbyDuplicate(nums, k);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestContainsNearbyDuplicate test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}