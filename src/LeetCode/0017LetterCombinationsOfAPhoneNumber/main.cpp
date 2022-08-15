#include <iostream>
#include <vector>
#include <map>
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
        InitializeNumAlphaMap(this->mNumAlphaMap);
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> ret; 
        if(digits.size() < 1) 
            return ret; 
         
        int len = CalculateLength(digits); 
        ret.resize(len); 
        std::vector<std::string>::iterator it = ret.begin(); 
        std::vector<ForLoopData> forLoopData = this->InitializeForLoopData(digits); 
        bool isContinuous = true; 
        while(isContinuous){ 
            for(auto e : forLoopData){ 
                *it = *it + *(e.data + e.index); 
            } 
            it++; 
            isContinuous = ForLoopContinuous(forLoopData); 
        } 
        return ret;
    }

private:
    struct ForLoopData{ 
        int index = 0; 
        int endCount = 0; 
        const char* data = nullptr; 
    }; 
    std::map<char, std::string> mNumAlphaMap; 
    void InitializeNumAlphaMap(std::map<char, std::string>& m) 
    { 
        m['1'] = ""; 
        m['2'] = "abc"; 
        m['3'] = "def"; 
        m['4'] = "ghi"; 
        m['5'] = "jkl"; 
        m['6'] = "mno";  
        m['7'] = "pqrs";  
        m['8'] = "tuv";  
        m['9'] = "wxyz";  
        m['0'] = ""; 
    } 
    std::vector<ForLoopData> InitializeForLoopData(std::string digits) 
    { 
        std::vector<ForLoopData> ret; 
        ret.resize(digits.size()); 
        std::vector<ForLoopData>::iterator it = ret.begin(); 
        std::vector<ForLoopData>::iterator end = ret.end(); 
        for(int i = 0; it != end; i++, it++){ 
            *it = {0, static_cast<int>(this->mNumAlphaMap[digits[i]].size()), this->mNumAlphaMap[digits[i]].c_str()}; 
        } 
        return ret; 
    } 
    int CalculateLength(std::string digits) 
    { 
        int ret = 1; 
        for(int i = 0; i < digits.size(); i++){ 
            ret = ret * static_cast<int>(this->mNumAlphaMap[digits[i]].size()); 
        } 
        return ret; 
    } 
    bool ForLoopContinuous(std::vector<ForLoopData> &data) 
    { 
        bool forLoopContinuous = true; 
        int count = 0, i = 0; 
        data[0].index++; 
        for(; i < data.size(); i++){ 
            if(data[i].index == data[i].endCount){ 
                count++; 
                data[i].index = 0; 
                if(i < data.size() - 1) { 
                    data[i + 1].index++; 
                } 
            } 
            else{ 
                break; 
            }  
        } 
        if(count == data.size()) 
            forLoopContinuous = false; 
        return forLoopContinuous; 
    }
};

class TestLetterCombinations
{
public:
	TestLetterCombinations()
	{}

	~TestLetterCombinations()
	{}

    void Test_Input_23()
    {
        std::cout << "========= Test input 23 =========" << std::endl;
        std::string input = "23";
        std::string arr[] = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
        std::vector<std::string> answer = ConvertArrayToVector<std::string>(arr, sizeof(arr) / sizeof(std::string));

        std::vector<std::string> result = this->mSolution.letterCombinations(input);
        AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, answer));
    }

    void Test_Input_Empty()
    {
        std::cout << "========= Test input empty =========" << std::endl;
        std::string input = "";
        std::string arr[] = {};
        std::vector<std::string> answer = ConvertArrayToVector<std::string>(arr, sizeof(arr) / sizeof(std::string));

        std::vector<std::string> result = this->mSolution.letterCombinations(input);
        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, answer));
    }

    void Test_Input_2()
    {
        std::cout << "========= Test input 2 =========" << std::endl;
        std::string input = "2";
        std::string arr[] = {"a", "b", "c"};
        std::vector<std::string> answer = ConvertArrayToVector<std::string>(arr, sizeof(arr) / sizeof(std::string));

        std::vector<std::string> result = this->mSolution.letterCombinations(input);
        AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, answer));
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestLetterCombinations test;
    test.Test_Input_23();
    test.Test_Input_Empty();
    test.Test_Input_2();
	getchar();
	return EXIT_SUCCESS;
}