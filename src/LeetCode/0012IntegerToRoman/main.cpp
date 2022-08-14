#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:

	Solution() 
    { 
        this->mRomanNumTable[1] = "I"; 
        this->mRomanNumTable[2] = "II"; 
        this->mRomanNumTable[3] = "III"; 
        this->mRomanNumTable[4] = "IV"; 
        this->mRomanNumTable[5] = "V"; 
        this->mRomanNumTable[6] = "VI"; 
        this->mRomanNumTable[7] = "VII"; 
        this->mRomanNumTable[8] = "VIII"; 
        this->mRomanNumTable[9] = "IX";   
        this->mRomanNumTable[10] = "X";  
        this->mRomanNumTable[20] = "XX";  
        this->mRomanNumTable[30] = "XXX";  
        this->mRomanNumTable[40] = "XL";  
        this->mRomanNumTable[50] = "L";  
        this->mRomanNumTable[60] = "LX";  
        this->mRomanNumTable[70] = "LXX";  
        this->mRomanNumTable[80] = "LXXX";  
        this->mRomanNumTable[90] = "XC"; 
        this->mRomanNumTable[100] = "C";   
        this->mRomanNumTable[200] = "CC";   
        this->mRomanNumTable[300] = "CCC";   
        this->mRomanNumTable[400] = "CD";   
        this->mRomanNumTable[500] = "D";   
        this->mRomanNumTable[600] = "DC";   
        this->mRomanNumTable[700] = "DCC";   
        this->mRomanNumTable[800] = "DCCC";   
        this->mRomanNumTable[900] = "CM"; 
        this->mRomanNumTable[1000] = "M";    
        this->mRomanNumTable[2000] = "MM";    
        this->mRomanNumTable[3000] = "MMM"; 
    } 

	~Solution()
	{}

    std::string intToRoman(int num) { 
        std::string roman = ""; 
        for(int i = 1000; i > 0; i = i / 10){ 
            int digit = num / i; 
            digit = digit * i; 
            roman.append(this->mRomanNumTable[digit]); 
            num = num - digit; 
        } 
         
        return roman; 
    }

private:
    std::unordered_map<int, std::string> mRomanNumTable;
};

class TestIntToRoman
{
public:
	TestIntToRoman()
	{}

	~TestIntToRoman()
	{}

    void Test_input_3_Output_III()
    {
        std::cout << "========== Test input 3 Output III ==========" << std::endl;
        int input = 3;

        std::string result = this->mSolution.intToRoman(input);
        AssertClass::GetInstance().Assert(result == "III");
    }

    void Test_input_58_Output_LVIII()
    {
        std::cout << "========== Test input 58 Output LVIII ==========" << std::endl;
        int input = 58;

        std::string result = this->mSolution.intToRoman(input);
        AssertClass::GetInstance().Assert(result == "LVIII");
    }

    void Test_input_1994_Output_MCMXCIV()
    {
        std::cout << "========== Test input 58 Output LVIII ==========" << std::endl;
        int input = 1994;

        std::string result = this->mSolution.intToRoman(input);
        AssertClass::GetInstance().Assert(result == "MCMXCIV");
    }

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestIntToRoman test;
	getchar();
	return EXIT_SUCCESS;
}