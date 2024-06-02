#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "VectorMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> ret;
        std::vector<std::map<char, int>> anagrams;
        
        int len = strs.size();
        int idx = -1;
        //std::cout << "1" << std::endl; // debug
        for (int i = 0; i < len; i++) {
            //std::cout << "\t" << i << std::endl; // debug
            idx = FindIndexStrBelongAnagram(strs[i], anagrams);
            //std::cout << "\tidx = " << idx << ", ret.size = " << ret.size() << ", anagrams.size() = " << anagrams.size() << std::endl; // debug
            if (idx == -1) {
                std::vector<std::string> vec({strs[i]});
                ret.push_back(vec);
            }
            else {
                ret[idx].push_back(strs[i]);
            }
        }

        return ret;
    }

private:
    
    std::map<char, int> CountCharTimes(std::string &strs) 
    {
        std::map<char, int> count;
        for (auto c : strs) {
            count[c] = count[c] + 1;
        }
        return count;
    }

    int FindIndexStrBelongAnagram(std::string &str, std::vector<std::map<char, int>> &anagrams)
    {
        std::map<char, int> count = CountCharTimes(str);

        int index = -1;
        int len = anagrams.size();
        for (int i = 0; i < len; i++) {
            if (IsTwoMapSame(count, anagrams[i])) {
                index = i;
                break;
            }
        }

        if (index == -1)
            anagrams.push_back(count);
        
        return index;
    }

    bool IsTwoMapSame(std::map<char, int> &l, std::map<char, int> &r)
    {
        if (l.size() != r.size())
            return false;
    
        bool isSame = true;
        int len = l.size();
        auto lIt = l.begin();
        auto rIt = r.begin();
        for (int i = 0; i < len; i++, lIt++, rIt++) {
            if (lIt->first != rIt->first ||
                lIt->second != rIt->second) {
                isSame = false;
                break;
            }
        }

        return isSame;
    }
};

class TestGroupAnagrams
{
public:
	TestGroupAnagrams()
	{}

	~TestGroupAnagrams()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::string> strs({"eat","tea","tan","ate","nat","bat"});
		std::vector<std::vector<std::string>> expectedOutput({{"ate","eat","tea"},{"nat","tan"},{"bat"}});
		std::cout << "===== Test strs = " << Vector2Str(strs) << "; output = " << Vector2Str(expectedOutput) << " true =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<std::vector<std::string>> result = this->mSolution.groupAnagrams(strs);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		bool isSame = true;
		for (int i = 0; i < result.size(); i++) {
			isSame = isSame && IsTwoVectorSimilar(result[i], expectedOutput[i]);
		}
		AssertClass::GetInstance().Assert(isSame);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<std::string> strs({""});
		std::vector<std::vector<std::string>> expectedOutput({{""}});
		std::cout << "===== Test strs = " << Vector2Str(strs) << "; output = " << Vector2Str(expectedOutput) << " true =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<std::vector<std::string>> result = this->mSolution.groupAnagrams(strs);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example3()
	{
		// ARRANGE
		std::vector<std::string> strs({"a"});
		std::vector<std::vector<std::string>> expectedOutput({{"a"}});
		std::cout << "===== Test strs = " << Vector2Str(strs) << "; output = " << Vector2Str(expectedOutput) << " true =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<std::vector<std::string>> result = this->mSolution.groupAnagrams(strs);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestGroupAnagrams test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}