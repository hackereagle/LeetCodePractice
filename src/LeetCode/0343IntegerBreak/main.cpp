#include <iostream>
#include <map>
#include <string>
#include "AssertClass.hpp"

class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
        this->mLookupTable.insert(std::pair<int, Table>(2, {{1, 1}, 1}));
        this->mLookupTable.insert(std::pair<int, Table>(3, {{2, 1}, 2}));
        this->mLookupTable.insert(std::pair<int, Table>(4, {{2, 2}, 4})); 
        this->mLookupTable.insert(std::pair<int, Table>(5, {{3, 2}, 6}));
        this->mLookupTable.insert(std::pair<int, Table>(6, {{3, 3}, 9})); 
        this->mLookupTable.insert(std::pair<int, Table>(7, {{3, 4}, 12}));  
        this->mLookupTable.insert(std::pair<int, Table>(8, {{3, 3, 2}, 18}));
    }

    int integerBreak(int n) {
        Table ret = GetIntegerBreak(n);

        return ret.product;
    }

private:
    struct _table
    {
        int composition[20]{0};
        int product;
    };
    typedef struct _table Table;

    std::map<int, Table> mLookupTable;

    Table GetIntegerBreak(int n)
    {
        Table ret;
        if (this->mLookupTable.find(n) != this->mLookupTable.end()) {
            ret = this->mLookupTable[n];
        }
        else {
            ret = this->GetIntegerBreak(n - 1);

            int lastIndex = n / 3;
            int remain = n % 3;
            if (remain == 0) {
                ret.composition[lastIndex - 1] = 3;
            }
            else if (remain == 1) {
                ret.composition[lastIndex - 1] = 4;
            }
            else if (remain == 2) { 
                ret.composition[lastIndex - 1] = 3;
                ret.composition[lastIndex] = 2; 
            }

            ret.product = 1;
            for(int i = 0; i < 20; i++){
                //std::cout << ret.composition[i] << ", ";
                if (!ret.composition[i])
                    break;

                ret.product = ret.product * ret.composition[i];
            }
            //std::cout << std::endl;
        }

        return ret;
    }
};

class TestIntegerBreak
{
public:
	TestIntegerBreak()
	{}

	~TestIntegerBreak()
	{}

    void Test_Input_2_Output_1()
    {
        std::cout << "========= Test input 2 and output 1 =========" << std::endl;
        int n = 2;

        int result = this->mSolution.integerBreak(n);
        AssertClass::GetInstance().Assert(result == 1);
    }

    void Test_Input_10_Output_36()
    {
        std::cout << "========= Test input 10 and output 36 =========" << std::endl;
        int n = 10;

        int result = this->mSolution.integerBreak(n);
        AssertClass::GetInstance().Assert(result == 36);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestIntegerBreak test;
    test.Test_Input_2_Output_1();
    test.Test_Input_10_Output_36();
	getchar();
	return EXIT_SUCCESS;
}