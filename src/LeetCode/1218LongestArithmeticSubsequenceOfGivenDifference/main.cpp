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

	int longestSubsequence(std::vector<int>& arr, int difference) {
        int maxCount = 0;  
         
        std::unordered_map<int, int> dp; 
        int len = arr.size(); 
        for (int i = len - 1; i >= 0; i--) { 
            int last = arr[i] + difference; 
            if (dp.find(last) == dp.end()) { 
                dp.insert(std::pair<int, int>(arr[i], 1)); 
            } 
            else { 
                dp[arr[i]] = 1 + dp[arr[i] + difference]; 
            } 
            //std::cout << "dp[" << arr[i] << "] = " << dp[arr[i]] << std::endl; // debug 
            maxCount = std::max(maxCount, dp[arr[i]]); 
        } 
        return maxCount;
    }

private:
};

class TestlongestSubsequence
{
public:
	TestlongestSubsequence()
	{}

	~TestlongestSubsequence()
	{}

	void TestInput_1_2_3_4_Difference_1_Output_4()
	{
        std::cout << "===== [1, 2, 3, 4], difference = 1, output = 4 =====" << std::endl;
		std::vector<int> input({1, 2, 3, 4});
		int difference = 1;

        int result = mSolution.longestSubsequence(input, difference);
        AssertClass::GetInstance().Assert(result == 4);
	}

	void TestInput_1_3_5_7_Difference_1_Output_1()
	{
        std::cout << "===== [1,3,5,7], difference = 1, output = 1 =====" << std::endl;
		std::vector<int> input({1,3,5,7});
		int difference = 1;

        int result = mSolution.longestSubsequence(input, difference);
        AssertClass::GetInstance().Assert(result == 1);
	}

	void TestInput_1_5_7_8_5_3_4_2_1_Difference_negtive2_Output_4()
	{
        std::cout << "===== [1,5,7,8,5,3,4,2,1], difference = -2, output = 4 =====" << std::endl;
		std::vector<int> input({1,5,7,8,5,3,4,2,1});
		int difference = -2;

        int result = mSolution.longestSubsequence(input, difference);
        AssertClass::GetInstance().Assert(result == 4);
	}

	void TestInput_1_2_4_6_3_Difference_2_Output_3()
	{
        std::cout << "===== [1,2,4,6,3], difference = 2, output = 3 =====" << std::endl;
		std::vector<int> input({1,2,4,6,3});
		int difference = 2;

        int result = mSolution.longestSubsequence(input, difference);
        AssertClass::GetInstance().Assert(result == 3);
	}

	void TestInput_1_2_4_6_3_7_9_11_13_15_17_6_Difference_2_Output_6()
	{
        std::cout << "===== [1,2,4,6,3,7,9,11,13,15,17,6], difference = 2, output = 6 =====" << std::endl;
		std::vector<int> input({1,2,4,6,3,7,9,11,13,15,17,6});
		int difference = 2;

        int result = mSolution.longestSubsequence(input, difference);
        AssertClass::GetInstance().Assert(result == 6);
	}

	void TestInput_3_0_negative3_4_negative4_7_6_Difference_3_Output_2()
	{
        std::cout << "===== [3,0,-3,4,-4,7,6], difference = 3, output = 2 =====" << std::endl;
		std::vector<int> input({3,0,-3,4,-4,7,6});
		int difference = 3;

        int result = mSolution.longestSubsequence(input, difference);
        AssertClass::GetInstance().Assert(result == 2);
	}


private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestlongestSubsequence test;
	test.TestInput_1_2_3_4_Difference_1_Output_4();
	test.TestInput_1_3_5_7_Difference_1_Output_1();
	test.TestInput_1_5_7_8_5_3_4_2_1_Difference_negtive2_Output_4();
	test.TestInput_1_2_4_6_3_Difference_2_Output_3();
	test.TestInput_1_2_4_6_3_7_9_11_13_15_17_6_Difference_2_Output_6();
	test.TestInput_3_0_negative3_4_negative4_7_6_Difference_3_Output_2();
	getchar();
	return EXIT_SUCCESS;
}