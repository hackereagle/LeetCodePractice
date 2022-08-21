#include <iostream>
#include <vector>
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

    void Test_Input_()
    {
        std::cout << "========= Test input 10 and 3 output 3 =========" << std::endl;
        int dividend = 10, divisor = 3;

        int result = this->mSolution.divide(dividend, divisor);
        AssertClass::GetInstance().Assert(result == 3);
    }

    void Test_Input_()
    {
        std::cout << "========= Test input 7 and -3 output -2 =========" << std::endl;
        int dividend = 7, divisor = -3;

        int result = this->mSolution.divide(dividend, divisor);
        AssertClass::GetInstance().Assert(result == -2);
    }


private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestSubset test;
	getchar();
	return EXIT_SUCCESS;
}