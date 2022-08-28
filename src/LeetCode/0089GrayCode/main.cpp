#include <iostream>
#include <vector>
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

    std::vector<int> grayCode(int n) { 
        std::vector<int> ret; 
        int len = 1 << n;
        ret.reserve(len);
        helper(1, n, ret); 
        return ret;         
    } 

private: 
    void helper(int cur, const int target, std::vector<int>& result) 
    { 
        if(cur > target) 
            return; 
        if(cur == 1){ 
            result.push_back(0); 
            result.push_back(1); 
        } 
        else if(cur == 2){ 
            result.push_back(3);  
            result.push_back(2); 
        } 
        else{ 
            int len = result.size(); 
            for(int i = 0; i < len; i++){ 
                int temp = result[i]; 
                temp = temp ^ (1 << (cur - 2)); 
                temp = temp | (1 << (cur - 1)); 
                result.push_back(temp); 
            } 
        } 
        helper(cur + 1, target, result); 
    }
};

class TestGrayCode
{
public:
	TestGrayCode()
	{}

	~TestGrayCode()
	{}

    void Test_Input_n_1()
    {
        std::cout << "========= Test input n = 1 =========" << std::endl;
        int n = 1;

        std::vector<int> result = this->mSolution.grayCode(n);
        PrintVector<int>(result);
    }

    void Test_Input_n_2()
    {
        std::cout << "========= Test input n = 2 =========" << std::endl;
        int n = 2;

        std::vector<int> result = this->mSolution.grayCode(n);
        PrintVector<int>(result);
    }


private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestGrayCode test;
    test.Test_Input_n_1();
    test.Test_Input_n_2();
	getchar();
	return EXIT_SUCCESS;
}