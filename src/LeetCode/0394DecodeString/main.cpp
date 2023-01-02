#include <iostream>
#include <string>
#include <stack>
#include "AssertClass.hpp"

class Solution
{
public:
    Solution()
    {}

    ~Solution()
    {}

    std::string decodeString(std::string s) {
        std::string res;
        
        size_t len = s.size();
        std::stack<std::string> _strsStack;
        std::string tmp = "";
        for (int i = 0; i < len; i++) {
            //std::cout << "s[" << i << "] = " << s[i] << std::endl; // debug
            if (s[i] == '[') {
                //std::cout << "\toccur left, tmp = " << tmp << std::endl; // debug
                _strsStack.push(tmp);
                tmp = "";
            }
            else if (IsNumber(s[i])) {
                //std::cout << "\ts[i] is number" << std::endl; // debug
                if (tmp != "" && !IsNumber(tmp)) {
                    //std::cout << "\t\ttmp is not number, tmp = " << tmp << std::endl; // debug
                    _strsStack.push(tmp);
                    tmp = "";
                }
                tmp = tmp + s[i];
                //std::cout << "\ttmp = " << tmp << std::endl; // debug
            }
            else if (s[i] == ']') {
                std::string tmpRes = "";

                std::string base = "";
                if (tmp != "")
                    base = tmp;
                else {
                    base = _strsStack.top();
                    _strsStack.pop();
                }

                std::string times = _strsStack.top();
                _strsStack.pop();
                int t = 0;
                if (IsNumber(times)) {
                    t = std::stoi(times);
                    for (int j = 0; j < t; j++) {
                        tmpRes = tmpRes + base;
                    }

                    while (!_strsStack.empty() && !IsNumber(_strsStack.top())) {
                        tmpRes = _strsStack.top() + tmpRes;
                        _strsStack.pop();
                    }
                }
                else {
                    tmpRes = times + base;
                }
                //std::cout << "\toccur left, base = " << base << ", tiimes = " << times << ", tmpRes = " << tmpRes << std::endl; // debug
                tmp = tmpRes;
            }
            else {
                //std::cout << "\tother character" << std::endl; // debug
                if (tmp != "" && IsNumber(tmp)) {
                    //std::cout << "\t\ttmp is number, tmp = " << tmp << std::endl; // debug
                    _strsStack.push(tmp);
                    tmp = "";
                }
                tmp = tmp + s[i];
                //std::cout << "\ttmp = " << tmp << std::endl; // debug
            }
        }

        if (tmp != "")
            _strsStack.push(tmp);

        //std::cout << "\n\nBegin combine" << std::endl;; // debug
        while(!_strsStack.empty()) {
            std::string ss = _strsStack.top();
            _strsStack.pop();

            //std::cout << ss << std::endl; // debug
            if (IsNumber(ss)) {
                int t = std::stoi(ss);
                std::string base = res;
                for (int j = 0; j < t - 1; j++) {
                    res = res + base;
                }
            }
            else {
                res = ss + res;
            }
        }
        return res;
    }

private:
    bool IsNumber(std::string s)
    {
        bool isNumber = false;
        for (auto _s : s) {
            if (_s >= 48 && _s <= 57) {
                isNumber = true;
            }
            else {
                isNumber = false;
                break;
            }
        }
        return isNumber;
    }

    bool IsNumber(char s)
    {
        bool isNumber = false;
        if (s >= 48 && s <= 57) {
            isNumber = true;
        }
        else {
            isNumber = false;
        }
        return isNumber;
    }
};

class TestDecodeString
{
public:
	TestDecodeString()
	{}

	~TestDecodeString()
	{}

    void Example1()
    {
        std::cout << "Test input \"3[a]2[bc]\" and output \"aaabcbc\"" << std::endl;;
        std::string input = "3[a]2[bc]";
        std::string answer = "aaabcbc";

        std::string result = this->mSolution.decodeString(input);

        AssertClass::GetInstance().Assert(result == answer);
    }

    void Example2()
    {
        std::cout << "Test input \"3[a2[c]]\" and output \"accaccacc\"" << std::endl;;
        std::string input = "3[a2[c]]";
        std::string answer = "accaccacc";

        std::string result = this->mSolution.decodeString(input);

        AssertClass::GetInstance().Assert(result == answer);
    }

    void Example3()
    {
        std::cout << "Test input \"2[abc]3[cd]ef\" and output \"abcabccdcdcdef\"" << std::endl;;
        std::string input = "2[abc]3[cd]ef";
        std::string answer = "abcabccdcdcdef";

        std::string result = this->mSolution.decodeString(input);

        AssertClass::GetInstance().Assert(result == answer);
    }

    void Example4()
    {
        std::cout << "Test input \"10[aaa2[c]]\" and output \"aaaccaaaccaaaccaaaccaaaccaaaccaaaccaaaccaaaccaaacc\"" << std::endl;;
        std::string input = "10[aaa2[c]]";
        std::string answer = "aaaccaaaccaaaccaaaccaaaccaaaccaaaccaaaccaaaccaaacc";

        std::string result = this->mSolution.decodeString(input);

        AssertClass::GetInstance().Assert(result == answer);
    }

    void Example5()
    {
        std::cout << "Test input \"3[z]2[2[y]pq4[2[jk]e1[f]]]ef\" and output \"zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef\"" << std::endl;;
        std::string input = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
        std::string answer = "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef";

        std::string result = this->mSolution.decodeString(input);

        AssertClass::GetInstance().Assert(result == answer);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
    TestDecodeString test;
    test.Example1();
    test.Example2();
    test.Example3();
    test.Example4();
    test.Example5();
	getchar();
	return EXIT_SUCCESS;
}