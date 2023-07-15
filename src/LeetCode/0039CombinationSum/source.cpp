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
	
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
		_combinations.clear();

		std::sort(candidates.begin(), candidates.end());
		int curSum = 0;
		std::vector<int> buffer;
		FindCombinations(candidates, 0, buffer, curSum, target);
		return _combinations;
	}

private:
	std::vector<std::vector<int>> _combinations;

	void FindCombinations(std::vector<int> &candidates, int idx, std::vector<int> &buffer, int &curSum, int target){
		if (idx >= candidates.size())
			return;
		
		for (int i = idx; i < candidates.size(); i++) {
			curSum = curSum + candidates[i];
			buffer.push_back(candidates[i]);

			if (curSum == target) {
				Added2Result(buffer);
				RecoverChange(buffer, curSum, candidates[i]);
				break;
			}
			else if (curSum > target) {
				RecoverChange(buffer, curSum, candidates[i]);
				break;
			}
			else {
				FindCombinations(candidates, i, buffer, curSum, target);
				FindCombinations(candidates, i + 1, buffer, curSum, target);
				RecoverChange(buffer, curSum, candidates[i]);
			}
		}
	}

	void RecoverChange(std::vector<int> &buffer, int &curSum, int curVal)
	{
		buffer.pop_back();
		curSum = curSum - curVal;
	}

	void Added2Result(std::vector<int> &buffer)
	{
		bool isExist = false;
		int num = 0;
		for (auto cnt : _combinations) {
			num = 0;
			for (int i = 0; i < cnt.size() && i < buffer.size(); i++) {
				if (cnt[i] == buffer[i])
					num = num + 1;
			}

			if (num == buffer.size()) {
				isExist = true;
				break;
			}
		}

		if (!isExist) {
			_combinations.push_back(buffer);
		}
	}
};

class TestCombinationSum
{
public:
	TestCombinationSum()
	{}

	~TestCombinationSum()
	{}

	void Example1()
	{
		std::vector<int> candidates({2,3,6,7});
		int target = 7;
		std::vector<std::vector<int>> expected({{2,2,3},{7}});
		std::cout << "===== Test candidates = " << Vector2Str(candidates) << " and target = " << target << ", expected = " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.combinationSum(candidates, target);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example2()
	{
		std::vector<int> candidates({2,3,5});
		int target = 8;
		std::vector<std::vector<int>> expected({{2,2,2,2},{2,3,3},{3,5}});
		std::cout << "===== Test candidates = " << Vector2Str(candidates) << " and target = " << target << ", expected = " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.combinationSum(candidates, target);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example3()
	{
		std::vector<int> candidates({2});
		int target = 1;
		std::vector<std::vector<int>> expected({});
		std::cout << "===== Test candidates = " << Vector2Str(candidates) << " and target = " << target << ", expected = " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.combinationSum(candidates, target);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example4()
	{
		std::vector<int> candidates({8,7,4,3});
		int target = 11;
		std::vector<std::vector<int>> expected({{3, 4, 4}, {3, 8}, {4, 7}});
		std::cout << "===== Test candidates = " << Vector2Str(candidates) << " and target = " << target << ", expected = " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.combinationSum(candidates, target);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestCombinationSum test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}