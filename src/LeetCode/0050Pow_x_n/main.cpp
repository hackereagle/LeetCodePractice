#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "LeetcodeLinkListMiscs.hpp"

class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
    }

    double myPow(double x, int n) {
        if(n == 0) return 1.0; 
        if(n < 0){ 
            if(n == (1 << 31)){ 
                n = n + 1; 
                n = ~n + 1; 
                x = 1.0 / (x * myPow(x, n)); 
            } 
            else{ 
                n = ~n + 1; 
                x = 1.0 / myPow(x, n); 
            } 
        } 
        else{ 
            if(n & 1){  
                x = x * myPow(x, n - 1);  
            }  
            else{  
                x = myPow(x * x, n >> 1);  
            } 
        } 
        return x;
    }
};

class TestMyPow
{
public:
	TestMyPow()
	{}

	~TestMyPow()
	{}

    void Test_Input_2_10_Output_1024()
    {
        std::cout << "========= Test input x = 2.0 and n = 10, output 1024.0 =========" << std::endl;
        int n = 1;

    }

    void Test_Input_2_1_3_Output_9_261()
    {
        std::cout << "========= Test input x = 2.1 and n = 3, output 9.261 =========" << std::endl;
        int n = 1;

    }

    void Test_Input_2_negative_2_Output_0_25()
    {
        std::cout << "========= Test input x = 2.0 and n = -2, output 0.25 =========" << std::endl;
        int n = 1;

    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestMyPow test;
    test.Test_Input_2_10_Output_1024();
    test.Test_Input_2_1_3_Output_9_261();
    test.Test_Input_2_negative_2_Output_0_25();
	getchar();
	return EXIT_SUCCESS;
}