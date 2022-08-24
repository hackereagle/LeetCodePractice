#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> ret; 
        std::vector<int>::iterator begin = nums.begin(); 
        int probCount = (1 << nums.size()); 
        //std::cout << "len = " << probCount << std::endl; 
         
        for(int i = 0; i < probCount; i++){ 
            int flag = i; 
            std::vector<int> temp; 
            for(int bit = 0; flag; bit++){ 
                //std::cout << "flag = " << flag << std::endl; 
                if(flag & 1){ 
                    temp.push_back(*(begin + bit)); 
                } 
                flag = flag >> 1; 
            } 
            ret.push_back(temp); 
        } 
         
        return ret;
    }

private:
};

class TestSubset
{
public:
	TestSubset()
	{}

	~TestSubset()
	{}

    void Test_Input_1_2_3()
    {
        std::cout << "========= Test input [1, 2, 3] =========" << std::endl;
        int arr[] = {1, 2, 3};
        std::vector<int> input = ConvertArrayToVector(arr, sizeof(arr) / sizeof(int));
        std::vector<std::vector<int>> answer;

        std::vector<std::vector<int>> result = this->mSolution.subsets(input);
        PrintVector<std::vector<int>>(result);
        // TODO: Implement std::vector<std::vector<int>> IsTowVectorSimilar, please refer to https://jimmy-shen.medium.com/stl-map-unordered-map-with-a-vector-for-the-key-f30e5f670bae
        //AssertClass::GetInstance().Assert(result == 3);
    }

    void Test_Input_0()
    {
        std::cout << "========= Test input [0] =========" << std::endl;
        int arr[] = {0};
        std::vector<int> input = ConvertArrayToVector(arr, sizeof(arr) / sizeof(int));
        std::vector<std::vector<int>> answer;

        std::vector<std::vector<int>> result = this->mSolution.subsets(input);
        // TODO: Implement std::vector<std::vector<int>> IsTowVectorSimilar, please refer to https://jimmy-shen.medium.com/stl-map-unordered-map-with-a-vector-for-the-key-f30e5f670bae
        //AssertClass::GetInstance().Assert(result == -2);
    }


private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
    //std::vector<int> a, b;
    //a.push_back(1);
    //a.push_back(2);
    //b.push_back(1);
    //b.push_back(2);
    //std::unordered_map<std::vector<int>, int> m;
	TestSubset test;
    test.Test_Input_1_2_3();
	getchar();
	return EXIT_SUCCESS;
}