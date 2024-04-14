#include <iostream>
#include <string>
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	bool isAnagram(std::string s, std::string t) {
		if (s.size() != t.size())
			return false;
		bool is_anagram = true;
		int s_count[256];
		memset(s_count, 0, sizeof(int) * 256);
		int t_count[256];
		memset(t_count, 0, sizeof(int) * 256);
		size_t len = s.size();
		for (int i = 0; i < len; i++) {
			s_count[s[i]] = s_count[s[i]] + 1;
			t_count[t[i]] = t_count[t[i]] + 1;
		}
		for (int i = 0; i < 256; i++) {
			if (s_count[i] != t_count[i]) {
				is_anagram = false;
				break;
			}
		}
		return is_anagram;
	}
};

class TestIsAnagram
{
public:
	TestIsAnagram()
	{}

	~TestIsAnagram()
	{}

	void Example1()
	{
		// ARRANGE
		std::string s = "anagram";
		std::string t = "nagaram";
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", t = " << t << "; output true =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isAnagram(s, t);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::string s = "rat";
		std::string t = "car";
		bool expectedOutput = false;
		std::cout << "===== Test s = " << s << ", t = " << t << "; output true =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isAnagram(s, t);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::string s = "abcde";
		std::string t = "abcd";
		bool expectedOutput = false;
		std::cout << "===== Test s = " << s << ", t = " << t << "; output true =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isAnagram(s, t);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		std::string s = "phrase";
		std::string t = "prshae";
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", t = " << t << "; output true =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isAnagram(s, t);
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
	TestIsAnagram test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}