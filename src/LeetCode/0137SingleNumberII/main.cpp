#include <iostream>
#include <vector>
#include <string>
#include <map>
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

    int singleNumber(std::vector<int>& nums) {
        // hash table: key = num, value = appear times 
        std::map<int, int> counter;

        // iterate nums 
        for(auto n : nums){ 
            if(counter.find(n) != counter.end()){ 
                // if in hash table, counter add one 
                counter[n] = counter[n] + 1;

                // if count equal to three, erease it 
                if(counter[n] == 3){ 
                    counter.erase(n); 
                } 
            } 
            else{ 
                // if not found in hash table， create it 
                counter.insert(std::pair<int, int>(n, 1)); 
            } 
        }

        // return last key 
        return counter.begin()->first;
    }

private:
};

class TestSingleNumber
{
public:
	TestSingleNumber()
	{}

	~TestSingleNumber()
	{}

    void Test_Input_2_2_3_2_Output_3()
    {
        std::cout << "========= Test input [2, 2, 3, 2] output 3 =========" << std::endl;
        std::vector<int> input({2, 2, 3, 2});

        int result = this->mSolution.singleNumber(input);
        AssertClass::GetInstance().Assert(result == 3);
    }

    void Test_Input_0_1_0_1_0_1_99_Output_99()
    {
        std::cout << "========= Test input [0, 1, 0, 1, 0, 1, 99] output 99 =========" << std::endl;
        std::vector<int> input({0, 1, 0, 1, 0, 1, 99});

        int result = this->mSolution.singleNumber(input);
        AssertClass::GetInstance().Assert(result == 99);
    }


private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestSingleNumber test;
    test.Test_Input_2_2_3_2_Output_3();
    test.Test_Input_0_1_0_1_0_1_99_Output_99();
	getchar();
	return EXIT_SUCCESS;
}