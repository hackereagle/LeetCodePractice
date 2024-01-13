#include <iostream>
#include <sstream>
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
	
	std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
		std::vector<int> ret;

		std::sort(nums.begin(), nums.end());
		_len = nums.size();
		_maxLenTable = std::vector<int>(_len, 0);
		_preEleIndex = std::vector<int>(_len, _len);
		_maxLen = 0;
		_maxLenIndexBegin = 0;
		for (int i = _len - 1; i >= 0; i--) {
			_maxLenTable[i] = 1;
			FindSetFromNumsWithNum(nums[i], nums, i);
		}

		/*std::cout << Vec2Str(nums) << std::endl;
		std::cout << Vec2Str(maxLenTable) << std::endl;
		std::cout << Vec2Str(preEleIndex) << std::endl;
		std::cout << maxLenIndexBegin << std::endl;*/

		int idx = _maxLenIndexBegin;
		while (idx < _len) {
			ret.push_back(nums[idx]);
			idx = _preEleIndex[idx];
		}
		
		return ret;
	}

private:
	std::vector<int> _maxLenTable;
	std::vector<int> _preEleIndex;
	int _maxLen = 0;
	int _maxLenIndexBegin = 0;
	size_t _len = 0;

	void FindSetFromNumsWithNum(int Num, std::vector<int> &nums, int numIndex)
	{
		for (int j = numIndex + 1; j < _len; j++) {
			if (nums[j] % Num == 0 && _maxLenTable[j] + 1 > _maxLenTable[numIndex]) {
				_maxLenTable[numIndex] = _maxLenTable[j] + 1;
				_preEleIndex[numIndex] = j;

				if (_maxLenTable[numIndex] > _maxLen) {
					_maxLen = _maxLenTable[numIndex];
					_maxLenIndexBegin = numIndex;
				}
			}
		}
	}

	std::string Vec2Str(std::vector<int> vec)
	{
		std::ostringstream ss;
		ss << "[";
		for (auto &e : vec) {
			ss << e << " ";
		}
		ss << "]";
		return ss.str();
	}
};

class TestLargestDivisibleSubset
{
public:
	TestLargestDivisibleSubset()
	{}

	~TestLargestDivisibleSubset()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> nums({1,2,3});
		std::vector<int> expectedOutput({1,2});
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<int> result = this->mSolution.largestDivisibleSubset(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> nums({1,2,4,8});
		std::vector<int> expectedOutput({1,2,4,8});
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<int> result = this->mSolution.largestDivisibleSubset(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> nums({1,2,4,5,8});
		std::vector<int> expectedOutput({1,2,4,8});
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<int> result = this->mSolution.largestDivisibleSubset(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example4()
	{
		// ARRANGE
		std::vector<int> nums({100, 7, 8, 10, 40, 20});
		std::vector<int> expectedOutput({10,20,40});
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<int> result = this->mSolution.largestDivisibleSubset(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example5()
	{
		// ARRANGE
		std::vector<int> nums({2,3,4,8});
		std::vector<int> expectedOutput({2,4,8});
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<int> result = this->mSolution.largestDivisibleSubset(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestLargestDivisibleSubset test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}