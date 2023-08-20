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
	
	int searchInsert(std::vector<int>& nums, int target) {
		int idx = 0;

		int low = 0, high = nums.size() - 1, mid = high;
		while (high > low) {
			mid = (low + high) >> 1;
			//std::cout << low << ", " << mid << ", " << high << std::endl;

			if (target == nums[mid]) {
				idx = mid;
				break;
			}
			else if (target > nums[mid]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		//std::cout << "End while loop: " << low << ", " << mid << ", " << high << ", " << idx << std::endl;

		if (low == high) {
			//std::cout << "ya" << std::endl;
			if (target > nums[low]) {
				idx = low + 1;
			}
			else {
				idx = low;
			}
		}
		else if (mid == low) {
			idx = low;
		}
		else if (mid == high) {
			idx = high;
		}
		//std::cout << "Final: " << low << ", " << mid << ", " << high << ", " << idx << std::endl;

		if (idx < 0)
			idx = 0;
		//std::cout << "yo~" << std::endl;

		return idx;
	}
};

class TestSearchInsert
{
public:
	TestSearchInsert()
	{}

	~TestSearchInsert()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> nums({1,3,5,6});
		int target = 5;
		int expectOutput = 2;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", target = " << target << "; expected output " << expectOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.searchInsert(nums, target);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> nums({1,3,5,6});
		int target = 2;
		int expectOutput = 1;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", target = " << target << "; expected output " << expectOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.searchInsert(nums, target);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> nums({1,3,5,6});
		int target = 7;
		int expectOutput = 4;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", target = " << target << "; expected output " << expectOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.searchInsert(nums, target);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestSearchInsert test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}