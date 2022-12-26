#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
    Solution()
    {}

    ~Solution()
    {}

    std::string findReplaceString(std::string s, std::vector<int>& indices, std::vector<std::string>& sources, std::vector<std::string>& targets) 
    {
        std::string res = "";

        std::map<int, std::vector<std::string>> table; 
        int len = indices.size(); 
        for (int i = 0; i < len; i++) { 
            std::vector<std::string> data; 
            data.push_back(sources[i]); 
            data.push_back(targets[i]); 
            table.insert(std::pair<int,std::vector<std::string>>(indices[i], data)); 
        }

        int index = 0; 
        for (auto it = table.begin(), end = table.end(); it != end; it++){ 
            // copied characters until reach indices 
            size_t copyLen = it->first - index; 
            res = res + s.substr(index, copyLen); 
            index = index + copyLen; 
            if (s.substr(it->first, it->second[0].size()) == it->second[0]) { 
                // if occur sources, replace source with target 
                res = res + it->second[1]; 
                index = index + it->second[0].size(); 
            } 
        }

        if (index < s.size()){ 
            res = res + s.substr(index, len - index - 1); 
        } 
         
        return res;
    }
};

class TestFindReplaceString
{
public:
	TestFindReplaceString()
	{}

	~TestFindReplaceString()
	{}

    void Example1()
    {
        std::string s = "abcd";
        std::vector<int> indices({0, 2});
        std::vector<std::string> sources({"a", "cd"});
        std::vector<std::string> targets({"eee", "ffff"});
        std::cout << "\ninput string = " << s << ", indeices = [0, 2], sources = [\"a\", \"cd\"], targets = [\"eee\", \"ffff\"]" << std::endl;;

        std::string result = this->mSolution.findReplaceString(s, indices, sources, targets);

        AssertClass::GetInstance().Assert(result == "eeebffff");
    }

    void Example2()
    {
        std::string s = "abcd";
        std::vector<int> indices({0, 2});
        std::vector<std::string> sources({"ab", "ec"});
        std::vector<std::string> targets({"eee", "ffff"});
        std::cout << "\ninput string = " << s << ", indeices = [0, 2], sources = [\"a\", \"cd\"], targets = [\"eee\", \"ffff\"]" << std::endl;;

        std::string result = this->mSolution.findReplaceString(s, indices, sources, targets);

        AssertClass::GetInstance().Assert(result == "eeecd");

    }


private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestFindReplaceString test;
    test.Example1();
    test.Example2();
	getchar();
	return EXIT_SUCCESS;
}