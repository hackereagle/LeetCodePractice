#include <iostream>
#include <sstream>
#include <string>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::string countAndSay(int n) {
        //std::cout << CreateHierarchy() << "n = " << n << std::endl; // debug
        if (n == 1)
            return "1";

        //_hierarchy = _hierarchy + 1; // for debug show
        std::string preStr = countAndSay(n - 1);
        //_hierarchy = _hierarchy + 1; // for debug show
        //std::cout << CreateHierarchy() << "preStr = " << preStr << std::endl; // debug
        std::vector<Counter> cnter = CountNumber(preStr);
        //std::cout << CreateHierarchy() << PrintCounters(cnter) << std::endl; // dubug

        size_t len = cnter.size() * 2;
        std::string ret(len, '0');
        for (int i = 0, j = 0; i < len; i = i + 2, j++) {
            ret[i] = cnter[j].Count + '0';
            ret[i + 1] = cnter[j].Number + '0';
        }
        //std::cout << CreateHierarchy() << "ret = " << ret << std::endl; // debug

        return ret;
    }

private:
    int _hierarchy = 0; // debug
    struct counter
    {
        int Number = 0;
        int Count = 0;

        counter() = default;
        counter(int n, int c) : Number(n), Count(c) {}
        std::string ToString()
        {
            std::ostringstream ss;
            ss << "[" << this->Number << ", " << this->Count << "]";
            return ss.str();
        }
    };
    typedef struct counter Counter;

    std::vector<Counter> CountNumber(std::string &str)
    {
        std::vector<Counter> ret;
        int curNum = 0;
        size_t len = str.size();
        for (int i = 0; i < len; i++) {
            curNum = str[i] - '0';
            if (ret.size() == 0 || curNum != ret.back().Number) {
                ret.push_back(Counter(curNum, 1));
            }
            else {
                ret.back().Count = ret.back().Count + 1;
            }
        }

        return ret;
    }

    std::string CreateHierarchy()
    {
        std::ostringstream ss;
        for (int i = 0; i < this->_hierarchy; i++)
            ss << "\t";
        return ss.str();
    }

    std::string PrintCounters(std::vector<Counter> &counters)
    {
        std::ostringstream ss;
        ss << "[";
        for (auto &c : counters) {
            ss << c.ToString() << " ";
        }
        ss << "]";
        return ss.str();
    }
};

class TestCountAndSay
{
public:
	TestCountAndSay()
	{}

	~TestCountAndSay()
	{}

	void Example1()
	{
		// ARRANGE
		int input = 1;
		std::string expectedOutput = "1";
		std::cout << "===== Test input " << input << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.countAndSay(input);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		int input = 4;
		std::string expectedOutput = "1211";
		std::cout << "===== Test input " << input << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.countAndSay(input);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		int input = 5;
		std::string expectedOutput = "111221";
		std::cout << "===== Test input " << input << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.countAndSay(input);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestCountAndSay test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}