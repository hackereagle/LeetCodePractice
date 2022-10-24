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

    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::vector<std::string> ret;
        
        std::unordered_map<std::string, int> table;
        size_t len = s.size();
        if(len > 10){
            for(int i = 0; i <= (len - this->LEN); i++){
                std::string key = s.substr(i, LEN);

                if ( table.find(key) == table.end() ) {
                    table.insert(std::pair<std::string, int>(key, 1));
                }
                else{
                    if (table[key] == 1)
                        ret.push_back(key);
                    
                    table[key]++;
                }
            }
        }
        return ret;
    }

private:
    size_t LEN = 10;
};

class TestFindRepeatedDnaSequences
{
public:
	TestFindRepeatedDnaSequences()
	{}

	~TestFindRepeatedDnaSequences()
	{}

    void Test_Input_AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT_Output_AAAAACCCCC_CCCCCAAAAA()
    {
        std::cout << "========= Test input AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT output [AAAAACCCCC,CCCCCAAAAA] =========" << std::endl;
        std::string dna = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
        std::vector<std::string> ans({"AAAAACCCCC", "CCCCCAAAAA"});

        std::vector<std::string> result = this->mSolution.findRepeatedDnaSequences(dna);
        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, ans));
    }

    void Test_Input_AAAAAAAAAAAAA_Output_AAAAAAAAAA()
    {
        std::cout << "========= Test input AAAAAAAAAAAAA output [AAAAAAAAAA] =========" << std::endl;
        std::string dna = "AAAAAAAAAAAAA";
        std::vector<std::string> ans({"AAAAAAAAAA"});

        std::vector<std::string> result = this->mSolution.findRepeatedDnaSequences(dna);
        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, ans));
    }

    void Test_Input_AAAAAAAAAAA_Output_AAAAAAAAAA()
    {
        std::cout << "========= Test input AAAAAAAAAAA output [AAAAAAAAAA] =========" << std::endl;
        std::string dna = "AAAAAAAAAAA";
        std::vector<std::string> ans({"AAAAAAAAAA"});

        std::vector<std::string> result = this->mSolution.findRepeatedDnaSequences(dna);
        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, ans));
    }


private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestFindRepeatedDnaSequences test;
    test.Test_Input_AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT_Output_AAAAACCCCC_CCCCCAAAAA();
    test.Test_Input_AAAAAAAAAAAAA_Output_AAAAAAAAAA();
    test.Test_Input_AAAAAAAAAAA_Output_AAAAAAAAAA();
	getchar();
	return EXIT_SUCCESS;
}