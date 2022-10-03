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
        int count = 0;

        int len = target.size();
        std::vector<int>::iterator it = target.begin();
        for(int i = 1; i < len; i++){
            if(*(it + i -1) > *(it + i)){
                count = count + (*(it + i - 1) - *(it + i));
            }
        }
        count = count + target.back();

        return count;
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

	void TestInput_1_2_3_2_1_Output_3()
	{
        std::cout << "===== [1, 2, 3, 2, 1], output = 4 =====" << std::endl;
		std::vector<int> input({1, 2, 3, 2, 1});

        int result = mSolution.minNumberOperations(input);
        AssertClass::GetInstance().Assert(result == 3);
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
        AssertClass::GetInstance().Assert(result == 7);
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestMinNumberOperations test;
	test.TestInput_1_2_3_2_1_Output_3();
	test.TestInput_3_1_1_2_Output_4();
	test.TestInput_3_1_5_4_2_Output_7();
	getchar();
	return EXIT_SUCCESS;
}