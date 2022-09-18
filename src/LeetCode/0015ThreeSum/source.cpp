#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
	{
        std::vector<std::vector<int>> ret; 
        int len = nums.size(); 
        std::sort(nums.begin(), nums.end());  
        for(int i = 0; i < len - 2; i++){ 
            int l = i + 1; 
            int r = len - 1; 
            int target = 0 - nums[i]; 
            while(r > l){ 
                //std::cout << nums[i] << ", " << nums[l] << ", " << nums[r] << std::endl; 
                if(nums[l] + nums[r] == target){ 
                    std::vector<int> ans;  
                    ans.push_back(nums[i]);  
                    ans.push_back(nums[l]);   
                    ans.push_back(nums[r]);    
                    ret.push_back(ans); 
                    while(r > l && nums[r] == nums[r - 1]) r = r - 1; // important! avoid exist vector
                    while(r > l && nums[l] == nums[l + 1]) l = l + 1; // important! avoid exist vector
                    l = l + 1; 
                    r = r - 1; 
                    //std::cout << "1" << std::endl; 
                } 
                else if(target < nums[l] + nums[r]){ 
                    r = r - 1; 
                    //std::cout << "2" << std::endl; 
                } 
                else{ 
                    l = l + 1; 
                    //std::cout << "3" << std::endl; 
                } 
            } 
            while(i + 1 < len && nums[i] == nums[i + 1]){ // important! avoid exist vector 
                i++; 
                //std::cout << "5: " << i << std::endl; 
            } 
        } 
        return ret;
    }
};

class TestThreeSum
{
public:
	TestThreeSum()
	{}

	~TestThreeSum()
	{}

	void TestInput_n1_0_1_2_n1_n4_Output_n1_n1_2_And_n1_0_1()
	{
		std::cout << "===== Test input [-1, 0, 1, 2, -1, -4] output [[-1, -1, 2], [-1, 0, 1]] =====" << std::endl;
		std::vector<int> input({-1, 0, 1, 2, -1, -4});
		std::vector<std::vector<int>> ans;
		ans.push_back(std::vector({-1, -1, 2}));
		ans.push_back(std::vector({-1, 0, 1}));

		std::vector<std::vector<int>> reslut = this->mSolution.threeSum(input);

		//AssertClass::GetInstance().Assert();
		PrintVector(reslut);
	}

	void TestInput_0_1_1_Output_Empty()
	{
		std::cout << "===== Test input [0, 1, 1] output [] =====" << std::endl;
		std::vector<int> input({0, 1, 1});
		std::vector<std::vector<int>> ans;

		std::vector<std::vector<int>> reslut = this->mSolution.threeSum(input);

		//AssertClass::GetInstance().Assert();
		PrintVector(reslut);
	}

	void TestInput_0_0_0_Output_0_0_0()
	{
		std::cout << "===== Test input [0, 0, 0] output [[0, 0, 0]] =====" << std::endl;
		std::vector<int> input({0, 0, 0});
		std::vector<std::vector<int>> ans;
		ans.push_back(std::vector({0, 0, 0}));

		std::vector<std::vector<int>> reslut = this->mSolution.threeSum(input);

		//AssertClass::GetInstance().Assert();
		PrintVector(reslut);
	}

	void TestInput_1_2_2_n1_Output_Empty()
	{
		std::cout << "===== Test input [1, 2, 2, -1] output [] =====" << std::endl;
		std::vector<int> input({1, 2, 2, -1});
		std::vector<std::vector<int>> ans;

		std::vector<std::vector<int>> reslut = this->mSolution.threeSum(input);

		//AssertClass::GetInstance().Assert();
		PrintVector(reslut);
	}

	void TestInput_n2_0_0_2_2_Output_n2_0_2()
	{
		std::cout << "===== Test input [-2, 0, 0, 2, 2] output [-2, 0, 2] =====" << std::endl;
		std::vector<int> input({-2, 0, 0, 2, 2});
		std::vector<std::vector<int>> ans;
		ans.push_back({-2, 0, 2});

		std::vector<std::vector<int>> reslut = this->mSolution.threeSum(input);

		//AssertClass::GetInstance().Assert();
		PrintVector(reslut);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestThreeSum test;
	test.TestInput_n1_0_1_2_n1_n4_Output_n1_n1_2_And_n1_0_1();
	test.TestInput_1_2_2_n1_Output_Empty();
	test.TestInput_0_1_1_Output_Empty();
	test.TestInput_0_0_0_Output_0_0_0();
	test.TestInput_n2_0_0_2_2_Output_n2_0_2();
	getchar();
	return EXIT_SUCCESS;
}