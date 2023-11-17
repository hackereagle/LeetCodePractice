#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
		bool containAlmostDuplct = false;
		
		std::multiset<int> window;
		size_t len = nums.size();
		std::multiset<int>::iterator adj;
		int start = 0;
		for (int i = 0; i < len; i++) {
			adj = window.upper_bound(nums[i]);
			//std::cout << "nums[" << i << "] = " << nums[i] << ", multiset = " << MultisetToString(window) << ", upper = " << *adj << std::endl;

			if ((adj != window.end() && *adj - nums[i] <= valueDiff) || 
				(adj != window.begin() && nums[i] - *(--adj) <= valueDiff)) {
				//std::cout << "\tNearby almost duplicate: nums[" << i << "] = " << nums[i] << ", lower = " << *adj << std::endl;
				containAlmostDuplct = true;
				break;
			}

			window.insert(nums[i]);
			if (window.size() > indexDiff) {
				window.erase(nums[start]);
				start = start + 1;
			}
		}

		return containAlmostDuplct;
	}

private: 
	std::string MultisetToString(std::multiset<int> &muls)
	{
		std::ostringstream ss;
		ss << "[";
		for (auto n : muls) {
			ss << n << " ";
		}
		ss << "]";

		return ss.str();
	}
};

class TestContainsNearbyAlmostDuplicate
{
public:
	TestContainsNearbyAlmostDuplicate()
	{}

	~TestContainsNearbyAlmostDuplicate()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> nums({1,2,3,1});
		int indexDiff = 3;
		int valueDiff = 0;
		bool expectedOutput = true;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", indexDiff = " << indexDiff << ", valueDiff" << valueDiff << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> nums({1,5,9,1,5,9});
		int indexDiff = 2;
		int valueDiff = 3;
		bool expectedOutput = false;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", indexDiff = " << indexDiff << ", valueDiff" << valueDiff << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> nums({1,2,1,1});
		int indexDiff = 1;
		int valueDiff = 0;
		bool expectedOutput = true;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", indexDiff = " << indexDiff << ", valueDiff" << valueDiff << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestContainsNearbyAlmostDuplicate test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}