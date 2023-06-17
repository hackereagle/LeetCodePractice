#include <iostream>
#include <string>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int numDecodings(std::string s) {
		std::vector<int> dp(s.size(), -1);
		dp.push_back(1);
		int possibility = DecodingHelper(s, 0, dp);
		//PrintVector(dp); // debug
		//std::cout << "=> possibility = " << possibility << std::endl; // debug
		return possibility;
	}

private:
	int DecodingHelper(std::string &str, int pos, std::vector<int> &dp)
	{
		//std::cout << "==== pos = " << pos << std::endl; // deubg

		if (pos >= str.size()) {
			//std::cout << "\t over range" << std::endl; // debug
			return dp[dp.size() - 1];
		}

		if (dp[pos] != -1) {
			//std::cout << "\t had been calculated" << std::endl; // debug
			return dp[pos];
		}

		if (str[pos] == '0')
			return 0;
		
		int possibility1 = 0, possibility2 = 0;
		//std::cout << "\t pos = " << pos << " calculate decoding one" << std::endl; // debug
		if (str[pos] > '0')
			possibility1 = DecodingHelper(str, pos + 1, dp);
		//std::cout <<  "\t pos = " << pos << " possibility1 = " << possibility1 << std::endl; // debug

		//std::cout << "\t pos = " << pos << " calculate decoding two" << std::endl; // debug
		int num = std::stoi(str.substr(pos, 2));
		if (num > 9 && num <=26)
			possibility2 = DecodingHelper(str, pos + 2, dp);
		//std::cout <<  "\t pos = " << pos << " possibility2 = " << possibility2 << std::endl; // debug

		dp[pos] = possibility1 + possibility2;
		//std::cout << "\t possibility1 = " << possibility1 << ", possibility2 = " << possibility2 << ", dp[" << pos << "] = " << dp[pos] << std::endl; // debug
		
		return dp[pos];
	}

	void PrintVector(std::vector<int> &vec)
	{
		std::cout << "[";
		for (auto &v : vec)
			std::cout << v << " ";
		std::cout << "]" << std::endl;
	}
};

class TestNumDecodings
{
public:
	TestNumDecodings()
	{}

	~TestNumDecodings()
	{}

	void Example1()
	{
		std::string input = "12";
		int expected = 2;
		std::cout << "===== Test s = \"" << input << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.numDecodings(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		std::string input = "226";
		int expected = 3;
		std::cout << "===== Test s = \"" << input << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.numDecodings(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		std::string input = "06";
		int expected = 0;
		std::cout << "===== Test s = \"" << input << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.numDecodings(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		std::string input = "876498";
		int expected = 1;
		std::cout << "===== Test s = \"" << input << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.numDecodings(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example5()
	{
		std::string input = "876490";
		int expected = 0;
		std::cout << "===== Test s = \"" << input << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.numDecodings(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example6()
	{
		std::string input = "876098";
		int expected = 0;
		std::cout << "===== Test s = \"" << input << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.numDecodings(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example7()
	{
		std::string input = "123124523";
		int expected = 18;
		std::cout << "===== Test s = \"" << input << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.numDecodings(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestNumDecodings test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	getchar();
	return EXIT_SUCCESS;
}