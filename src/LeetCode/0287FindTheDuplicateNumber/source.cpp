#include <iostream>
#include <vector>
#include <VectorMiscs.hpp>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	#define MAX_LEN (100001)
	int findDuplicate(std::vector<int>& nums) {
		int duplicate = 0;

		bool appeared[MAX_LEN];
		memset(appeared, 0, sizeof(bool) * MAX_LEN);

		size_t len = nums.size();
		for (int i = 0; i < len; i++) {
			//std::cout << nums[i] << std::endl; // debug
			if (!appeared[nums[i]])
				appeared[nums[i]] = true;
			else {
				duplicate = nums[i];
				break;
			}
		}

		return duplicate;
	}
};

class TestFindDuplicate
{
public:
	TestFindDuplicate()
	{}

	~TestFindDuplicate()
	{}

	void Example1()
	{
		std::vector<int> input({1,3,4,2,2});
		int expected = 2;
		std::cout << "===== Test input " << Vector2Str(input) << ", output " << expected << "=====" << std::endl;

		int reslut = this->mSolution.findDuplicate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example2()
	{
		std::vector<int> input({3,1,3,4,2});
		int expected = 3;
		std::cout << "===== Test input " << Vector2Str(input) << ", output " << expected << "=====" << std::endl;

		int reslut = this->mSolution.findDuplicate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example3()
	{
		std::vector<int> input({3,1,3,4,2});
		int expected = 3;
		std::cout << "===== Test input " << Vector2Str(input) << ", output " << expected << "=====" << std::endl;

		int reslut = this->mSolution.findDuplicate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestFindDuplicate test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}