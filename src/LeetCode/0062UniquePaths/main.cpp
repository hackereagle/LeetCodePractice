#include <iostream>
#include <string>
#include <string.h>
#include "AssertClass.hpp"

class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
        memset(this->mTable, -1, sizeof(int) * 100 * 100);
        for(int i = 0; i < 100; i++){
            this->mTable[0][i] = 1;
            this->mTable[i][0] = 1;
        }
    }

    int uniquePaths(int m, int n) {
        return getFromTable(m, n);
    }

private:
    int mTable[100][100];

    int getFromTable(int m, int n)
    {
        if (this->mTable[m - 1][n - 1] == -1)
            this->mTable[m - 1][n - 1] = getFromTable(m - 1, n) + getFromTable(m, n - 1);
        return this->mTable[m - 1][n - 1];
    }
};

class TestUniquePaths
{
public:
	TestUniquePaths()
	{}

	~TestUniquePaths()
	{}

    void Test_Input_3_7_Output_28()
    {
        std::cout << "========= Test m = 3, n = 7 and output 28 =========" << std::endl;
        int m = 3;
        int n = 7;

        int result = this->mSolution.uniquePaths(m, n);
        AssertClass::GetInstance().Assert(result == 28);
    }

    void Test_Input_3_2_Output_3()
    {
        std::cout << "========= Test m = 3, n = 2 and output 3 =========" << std::endl;
        int m = 3;
        int n = 2;

        int result = this->mSolution.uniquePaths(m, n);
        AssertClass::GetInstance().Assert(result == 3);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestUniquePaths test;
    test.Test_Input_3_7_Output_28();
    test.Test_Input_3_2_Output_3();
	getchar();
	return EXIT_SUCCESS;
}