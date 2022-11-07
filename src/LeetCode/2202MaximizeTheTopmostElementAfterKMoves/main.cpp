#include <iostream>
#include <vector>
#include <algorithm>
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

	int maximumTop(std::vector<int>& nums, int k) {
        size_t len = nums.size(); 
        if (len < 2 && k%2) { 
            return -1; 
        } 
        /*else if (k < 2 && len > 1) {
            return nums[1];
        }*/
        
        int i = 0, max = -999; 
        for(; i < len; i++){
            if (i < k-1)
                max = std::max(max, nums[i]);
        }

        if (k < len) {
            max = std::max(max, nums[k]);
        }

        return max;
    }

private:
};

class TestMaximumTop
{
public:
	TestMaximumTop()
	{}

	~TestMaximumTop()
	{}

	void TestInput_5_2_2_4_0_6_k_4_Output_5()
	{
        std::cout << "===== [5, 2, 2, 4, 0, 6] and k = 4, output = 5 =====" << std::endl;
		std::vector<int> input({5, 2, 2, 4, 0, 6});
		int k = 4;

        int result = mSolution.maximumTop(input, k);
        AssertClass::GetInstance().Assert(result == 5);
	}

	void TestInput_2_k_1_Output_minus1()
	{
        std::cout << "===== [2] and k = 1, output = -1 =====" << std::endl;
		std::vector<int> input({2});
		int k = 1;

        int result = mSolution.maximumTop(input, k);
        AssertClass::GetInstance().Assert(result == -1);
	}

	void TestInput_3_2_1_k_4_Output_3()
	{
        std::cout << "===== [3, 2, 1] and k = 4, output = 3 =====" << std::endl;
		std::vector<int> input({3, 2, 1});
		int k = 4;

        int result = mSolution.maximumTop(input, k);
        AssertClass::GetInstance().Assert(result == 3);
	}

	void TestInput_4_5_6_k_3_Output_5()
	{
        std::cout << "===== [4, 5, 6] and k = 3, output = 5 =====" << std::endl;
		std::vector<int> input({4, 5, 6});
		int k = 3;

        int result = mSolution.maximumTop(input, k);
        AssertClass::GetInstance().Assert(result == 5);
	}

	void TestEdgeCase1()
	{
        std::cout << "===== [35,43,23,86,23,45,84,2,18,83,79,28,54,81,12,94,14,0,0,29,94,12,13,1,48,85,22,95,24,5,73,10,96,97,72,41,52,1,91,3,20,22,41,98,70,20,52,48,91,84,16,30,27,35,69,33,67,18,4,53,86,78,26,83,13,96,29,15,34,80,16,49] and k = 15, output = 94 =====" << std::endl;
		std::vector<int> input({35,43,23,86,23,45,84,2,18,83,79,28,54,81,12,94,14,0,0,29,94,12,13,1,48,85,22,95,24,5,73,10,96,97,72,41,52,1,91,3,20,22,41,98,70,20,52,48,91,84,16,30,27,35,69,33,67,18,4,53,86,78,26,83,13,96,29,15,34,80,16,49});
		int k = 15;

        int result = mSolution.maximumTop(input, k);
        AssertClass::GetInstance().Assert(result == 94);
	}

	void TestEdgeCase2()
	{
        std::cout << "===== [68,76,53,73,85,87,58,24,48,59,38,80,38,65,90,38,45,22,3,28,11] and k = 1, output = 76 =====" << std::endl;
		std::vector<int> input({68,76,53,73,85,87,58,24,48,59,38,80,38,65,90,38,45,22,3,28,11});
		int k = 1;

        int result = mSolution.maximumTop(input, k);
        AssertClass::GetInstance().Assert(result == 76);
	}

	void TestEdgeCase3()
	{
        std::cout << "===== [4,6,1,0,6,2,4] and k = 0, output = 4 =====" << std::endl;
		std::vector<int> input({4,6,1,0,6,2,4});
		int k = 0;

        int result = mSolution.maximumTop(input, k);
        AssertClass::GetInstance().Assert(result == 4);
	}

	void TestEdgeCase4()
	{
        std::cout << "===== [91,98,17,79,15,55,47,86,4,5,17,79,68,60,60,31,72,85,25,77,8,78,40,96,76,69,95,2,42,87,48,72,45,25,40,60,21,91,32,79,2,87,80,97,82,94,69,43,18,19,21,36,44,81,99] and k = 2, output = 91 =====" << std::endl;
		std::vector<int> input({91,98,17,79,15,55,47,86,4,5,17,79,68,60,60,31,72,85,25,77,8,78,40,96,76,69,95,2,42,87,48,72,45,25,40,60,21,91,32,79,2,87,80,97,82,94,69,43,18,19,21,36,44,81,99});
		int k = 2;

        int result = mSolution.maximumTop(input, k);
        AssertClass::GetInstance().Assert(result == 91);
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestMaximumTop test;
	test.TestInput_5_2_2_4_0_6_k_4_Output_5();
	test.TestInput_2_k_1_Output_minus1();
	test.TestInput_3_2_1_k_4_Output_3();
	test.TestInput_4_5_6_k_3_Output_5();
	test.TestEdgeCase1();
	test.TestEdgeCase2();
	test.TestEdgeCase3();
	test.TestEdgeCase4();
	getchar();
	return EXIT_SUCCESS;
}