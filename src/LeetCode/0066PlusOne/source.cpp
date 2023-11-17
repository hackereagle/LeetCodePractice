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
	
	std::vector<int> plusOne(std::vector<int>& digits) {
		std::vector<int> res = digits;

		int len = res.size(), idx = len - 1;
		int carrier = 1;
		while (idx >= 0 && carrier > 0) {
			res[idx] = res[idx] + carrier;
			if (res[idx] >= 10) {
				res[idx] = res[idx] - 10;
				carrier = 1;
			}
			else {
				carrier = 0;
			}

			idx = idx - 1;
		}
		//std::cout << "When while-loop end, carrier = " << carrier << std::endl;

		if (carrier > 0) {
			res.insert(res.begin(), 1);
			carrier = 0;
		}

		return res;
	}
};

class TestPlusOne
{
public:
	TestPlusOne()
	{}

	~TestPlusOne()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> digits({1,2,3});
		std::vector<int> expectedOutput({1,2,4});
		std::cout << "===== Test digits = " << Vector2Str(digits) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<int> result = this->mSolution.plusOne(digits);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result,expectedOutput));
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> digits({4,3,2,1});
		std::vector<int> expectedOutput({4,3,2,2});
		std::cout << "===== Test digits = " << Vector2Str(digits) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<int> result = this->mSolution.plusOne(digits);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result,expectedOutput));
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> digits({9});
		std::vector<int> expectedOutput({1,0});
		std::cout << "===== Test digits = " << Vector2Str(digits) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<int> result = this->mSolution.plusOne(digits);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result,expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestPlusOne test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}