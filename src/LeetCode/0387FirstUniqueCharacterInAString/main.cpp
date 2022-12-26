#include <iostream>
#include <vector>
#include <string>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
    Solution()
    {}

    ~Solution()
    {}

    int firstUniqChar(std::string s) {
        int index = -1; 
        std::unordered_map<char, std::vector<int>> table; 
        size_t len = s.size(); 
        for (int i = 0; i < len; i++) { 
            if (table.find(s[i]) == table.end()) { 
                std::vector<int> indices; 
                indices.push_back(i); 
                table.insert(std::pair<char, std::vector<int>>(s[i], indices)); 
            } 
            else { 
                table[s[i]].push_back(i); 
            } 
        } 

        int minIndex = 999999; 
        for (auto b = table.begin(); b != table.end(); b++) { 
            if (b->second.size() == 1) { 
                if (b->second[0] < minIndex) 
                    minIndex = b->second[0]; 
            } 
        } 

        if (minIndex != 999999) 
            index = minIndex; 

        return index;
    }

};

class TestFirstUniqChar
{
public:
	TestFirstUniqChar()
	{}

	~TestFirstUniqChar()
	{}

    void Input_leetcode_Output_0()
    {
        std::cout << "Test input leetcode and output 0" << std::endl;;
        std::string s = "leetcode";

        int result = this->mSolution.firstUniqChar(s);

        AssertClass::GetInstance().Assert(result == 0);
    }

    void Input_loveleetcode_Output_0()
    {
        std::cout << "Test input loveleetcode and output 2" << std::endl;;
        std::string s = "loveleetcode";

        int result = this->mSolution.firstUniqChar(s);

        AssertClass::GetInstance().Assert(result == 2);
    }

    void Input_aabb_Output_0()
    {
        std::cout << "Test input aabb and output 2" << std::endl;;
        std::string s = "aabb";

        int result = this->mSolution.firstUniqChar(s);

        AssertClass::GetInstance().Assert(result == -1);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestFirstUniqChar test;
    test.Input_leetcode_Output_0();
    test.Input_loveleetcode_Output_0();
    test.Input_aabb_Output_0();
	getchar();
	return EXIT_SUCCESS;
}