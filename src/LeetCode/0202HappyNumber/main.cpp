#include <iostream>
#include <map>
#include "AssertClass.hpp"

class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
    }

    bool isHappy(int n) {
        bool ret = false; 
        int sum = n; 
        while(!IsEndlessLoop(sum)){ 
            int num = sum; 
            sum = 0;
            // calculate sum of square of its digit 
            for(int tmp = num; tmp > 0; tmp = tmp / 10){ 
                int digit = tmp % 10; 
                sum = sum + (digit * digit); 
            }

            // add to map 
            this->mNumAndItsDigitSqrSum.insert(std::pair<int, int>(num, sum)); 
            if(sum == 1){ 
                ret = true; 
                break; 
            } 
        } 
        return ret; 
    }

private: 
    std::map<int, int> mNumAndItsDigitSqrSum;

    bool IsEndlessLoop(int num) 
    { 
        bool isEndlessLoop = false; 
        // find num from map. If find success, the loop is endlessloop 
        if(this->mNumAndItsDigitSqrSum.find(num) != this->mNumAndItsDigitSqrSum.end()){ 
            isEndlessLoop = true; 
        } 
        return isEndlessLoop; 
    }
};

class TestIsHappy
{
public:
	TestIsHappy()
	{}

	~TestIsHappy()
	{}

    void Test_19_true()
    {
        std::cout << "========= Test input n = 19 , output true =========" << std::endl;
        int n = 19;

        bool ret = this->mSolution.isHappy(n);

        AssertClass::GetInstance().Assert(ret == true);
    }

    void Test_2_false()
    {
        std::cout << "========= Test input n = 2 , output false =========" << std::endl;
        int n = 2;

        bool ret = this->mSolution.isHappy(n);

        AssertClass::GetInstance().Assert(ret == false);

    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestIsHappy test;
    test.Test_19_true();
    test.Test_2_false();
	getchar();
	return EXIT_SUCCESS;
}