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

    int numMatchingSubseq(std::string s, std::vector<std::string>& words) {
        int count = 0;

        int len = s.size();
        for (auto w : words) {
            if (w.size() > s.size())
                continue;

            if (IsSubstr(w, s))
                count = count + 1;
        }
        return count;
    }

private:
    bool IsSubstr(std::string &str, std::string &parent)
    {
        bool isSubstr = true;

        int begin = 0;
        for (int i = 0; i < str.size(); i++){
            //int pos = FindCharFromStr(str[i], parent, begin, parent.size() - 1);
            //std::cout << i << "-th: pos = " << pos << ", begin = " << begin << std::endl;  // debug
            int pos = parent.find(str[i], begin);
            if (pos == -1) {
                isSubstr = false;
                break;
            }
            else
                begin = pos + 1;
        }
        return isSubstr;
    }

	// it need more time than std::string::find
    int FindCharFromStr(char c, std::string& str, size_t begin, size_t end)
    {
        int pos = -1;

        for (int i = begin; i <= end; i++) {
            if (str[i] == c) {
                pos = i;
                break;
            }
        }
        return pos;
    }
};

class TestNumMatchingSubseq
{
public:
	TestNumMatchingSubseq()
	{}

	~TestNumMatchingSubseq()
	{}

    void Example1()
    {
        std::string s = "abcde";
        std::vector<std::string> words({"a","bb","acd","ace"});
        std::cout << "===== Target string = " << s << ", words = " << Vector2Str(words) << ", expected result = " << 3 << " =====" << std::endl;

        int result = this->mSolution.numMatchingSubseq(s, words);

        AssertClass::GetInstance().Assert(result == 3);
    }

    void Example2()
    {
        std::string s = "dsahjpjauf";
        std::vector<std::string> words({"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"});
        std::cout << "===== Target string = " << s << ", words = " << Vector2Str(words) << ", expected result = " << 2 << " =====" << std::endl;

        int result = this->mSolution.numMatchingSubseq(s, words);

        AssertClass::GetInstance().Assert(result == 2);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestNumMatchingSubseq test;
    test.Example1();
    test.Example2();
	getchar();
	return EXIT_SUCCESS;
}