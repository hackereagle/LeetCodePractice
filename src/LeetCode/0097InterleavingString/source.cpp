#include <iostream>
#include <string>
#include <vector>
#include "OtherMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	bool isInterleave(std::string s1, std::string s2, std::string s3) {		
		size_t len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
		if (len1 + len2 != len3)
			return false;

		std::vector<std::vector<bool>> dp(len1 + 1, std::vector<bool>(len2 + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= len1; i++) {
			dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
		}

		for (int j = 1; j <= len2; j++) {
			dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
		}

		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) ||
							(dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		
		return dp[len1][len2];
	}
};

class TestIsInterleave
{
public:
	TestIsInterleave()
	{}

	~TestIsInterleave()
	{}

	void Example1()
	{
		// ARRANGE
		std::string s1 = "aabcc";
		std::string s2 = "dbbca";
		std::string s3 = "aadbbcbcac";
		bool expectedOutput = true;
		std::cout << "===== Test s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isInterleave(s1, s2, s3);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::string s1 = "aabcc";
		std::string s2 = "dbbca";
		std::string s3 = "aadbbbaccc";
		bool expectedOutput = false;
		std::cout << "===== Test s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isInterleave(s1, s2, s3);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::string s1 = "";
		std::string s2 = "";
		std::string s3 = "";
		bool expectedOutput = true;
		std::cout << "===== Test s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isInterleave(s1, s2, s3);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		std::string s1 = "abcdef";
		std::string s2 = "abcdeesat";
		std::string s3 = "abcdeeabcdsatef";
		bool expectedOutput = true;
		std::cout << "===== Test s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isInterleave(s1, s2, s3);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		std::string s1 = "abcdefg";
		std::string s2 = "hijklmn";
		std::string s3 = "ahbicjdkelfmgn";
		bool expectedOutput = true;
		std::cout << "===== Test s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isInterleave(s1, s2, s3);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestIsInterleave test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}