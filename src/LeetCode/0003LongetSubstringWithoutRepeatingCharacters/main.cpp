#include <iostream>
#include <vector>
#include <string>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"


class Solution { 
public: 
    int lengthOfLongestSubstring(std::string s) { 
        int maxUniqueStrLen = 0; 
        const char* ptr = s.c_str(); 
        const char* ptr2 = ptr; 
        const char* end = ptr + s.size(); 
        std::unordered_map<char, int> charBeUsed; 
        int count = 0; 
        while(ptr2 != end){ 
            if(charBeUsed.find(*ptr2) == charBeUsed.end()){ 
                count = count + 1; 
                charBeUsed[*ptr2] = 1; 
            } 
            else{ 
                if(count > maxUniqueStrLen) 
                    maxUniqueStrLen = count; 
                charBeUsed.clear(); 
                ptr = ptr + 1; 
                ptr2 = ptr; 
                count = 1; 
                charBeUsed[*ptr2] = 1; 
            } 
            ptr2++; 
        } 
        if(count > maxUniqueStrLen) 
         
                maxUniqueStrLen = count; 
        return maxUniqueStrLen; 
    } 
};

class TestLengthOfLongestSubstring
{
public:
	TestLengthOfLongestSubstring()
	{}

	~TestLengthOfLongestSubstring()
	{}

    void Test_abcabcbb_Output_3()
    {
        std::cout << "========== Testing input abcabcbb output 3 ==========" << std::endl;
        std::string input = "abcabcbb";

        int result = this->mSolution.lengthOfLongestSubstring(input);
        AssertClass::GetInstance().Assert(result == 3);
    }

    void Test_bbbbb_Output_1()
    {
        std::cout << "========== Testing input bbbbb output 1 ==========" << std::endl;
        std::string input = "bbbbb";

        int result = this->mSolution.lengthOfLongestSubstring(input);
        AssertClass::GetInstance().Assert(result == 1);
    }

    void Test_pwwkew_Output_1()
    {
        std::cout << "========== Testing input pwwkew output 3 ==========" << std::endl;
        std::string input = "pwwkew";

        int result = this->mSolution.lengthOfLongestSubstring(input);
        AssertClass::GetInstance().Assert(result == 3);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestLengthOfLongestSubstring test;
    test.Test_abcabcbb_Output_3();
    test.Test_bbbbb_Output_1();
    test.Test_pwwkew_Output_1();
	getchar();
	return EXIT_SUCCESS;
}