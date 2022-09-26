#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "LeetcodeLinkListMiscs.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}

	int minNumberOperations(std::vector<int>& target) {
        
    }

private:
};

class TestMinNumberOperations
{
public:
	TestMinNumberOperations()
	{}

	~TestMinNumberOperations()
	{}

	void TestInput_1_2_3_2_1_Output_4()
	{
        std::cout << "===== [1, 2, 3, 2, 1], output = 4 =====" << std::endl;
		std::vector<int> input({1, 2, 3, 2, 1});

        int result = mSolution.minNumberOperations(input);
        AssertClass::GetInstance().Assert(result == 4);
	}

	void TestInput_3_1_1_2_Output_4()
	{
        std::cout << "===== [3, 1, 1, 2], output = 4 =====" << std::endl;
		std::vector<int> input({3, 1, 1, 2});

        int result = mSolution.minNumberOperations(input);
        AssertClass::GetInstance().Assert(result == 4);
	}

	void TestInput_3_1_5_4_2_Output_7()
	{
        std::cout << "===== [3, 1, 5, 4, 2], output = 7 =====" << std::endl;
		std::vector<int> input({3, 1, 5, 4, 2});

        int result = mSolution.minNumberOperations(input);
        AssertClass::GetInstance().Assert(result == 4);
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestMinNumberOperations test;
	getchar();
	return EXIT_SUCCESS;
}