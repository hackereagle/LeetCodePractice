#pragma once

#include <unordered_set>
#include "IWordBreak.hpp"

class WordBreakUsingDp : public IWordBreak
{
public:
	WordBreakUsingDp() {}
	~WordBreakUsingDp() {}
	bool wordBreak(std::string s, std::vector<std::string>& wordDict) override
	{
		std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        std::vector<bool> dp(s.size() + 1, false);

        
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            FindAWord(s, dict, i, dp);
        }

        //PrintVector(dp);
        return dp[s.size()];
	}

private:
    void PrintVector(std::vector<bool> &vec)
    {
        std::cout << "[";
        for (auto v : vec)
            std::cout << v << " ";
        std::cout << "]" << std::endl;
    }

    void FindAWord(std::string &s, std::unordered_set<std::string> &dict, int curIdx, std::vector<bool> &dp)
    {
        std::string prefix;
        int len = 0;
        for (int j = curIdx; j >= 0; j--) { 
            if (dp[j]) {
                //std::cout << j << "-th have true. "; // debug
                len = curIdx - j;
                prefix = s.substr(j, len);
                if (dict.find(prefix) != dict.end()) {
                    dp[curIdx] = true;
                    //std::cout << "To " << i << " is a word" << std::endl; // debug
                    break;
                }
                //std::cout << std::endl; // debug
            }
        }
    }
};