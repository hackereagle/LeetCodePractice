#include <iostream>
#include <string>
#include <memory>
#include "IWordBreak.hpp"
#include "WordBreakUsingDp.hpp"
#include "WordBreakUsingTrie.hpp"
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

enum class WordBreakMethod : int
{
	Trie,
	Dp,
};

class TestWordBreak
{
public:
	TestWordBreak(WordBreakMethod m = WordBreakMethod::Trie)
	{
		if (WordBreakMethod::Trie == m) {
			mSolution = std::make_unique<WordBreakUsingTrie>();
		}
		else {
			mSolution = std::make_unique<WordBreakUsingDp>();
		}
	}

	~TestWordBreak()
	{}

	void Example1()
	{
		// ARRANGE
		std::string s = "leetcode";
		std::vector<std::string> wordDict({"leet","code"});
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", wordDict = " << Vector2Str(wordDict) << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution->wordBreak(s, wordDict);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::string s = "applepenapple";
		std::vector<std::string> wordDict({"apple","pen"});
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", wordDict = " << Vector2Str(wordDict) << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution->wordBreak(s, wordDict);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::string s = "catsandog";
		std::vector<std::string> wordDict({"cats","dog","sand","and","cat"});
		bool expectedOutput = false;
		std::cout << "===== Test s = " << s << ", wordDict = " << Vector2Str(wordDict) << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution->wordBreak(s, wordDict);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		std::string s = "abcdefghijklmn";
		std::vector<std::string> wordDict({"abcd","abcdefgh","ijklmn","aa","abczdif"});
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", wordDict = " << Vector2Str(wordDict) << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution->wordBreak(s, wordDict);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		std::string s = "abcdefghijklmn";
		std::vector<std::string> wordDict({"abcdefghijklmn","abcdefgh","aa","abczdif"});
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", wordDict = " << Vector2Str(wordDict) << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution->wordBreak(s, wordDict);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example6()
	{
		// ARRANGE
		std::string s = "abcdefghijklmn";
		std::vector<std::string> wordDict({"abcd","abcdefgh","efghijklmn","aa","abczdif"});
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", wordDict = " << Vector2Str(wordDict) << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution->wordBreak(s, wordDict);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example7()
	{
		// ARRANGE
		std::string s = "aaaaaaa";
		std::vector<std::string> wordDict({"aaaa","aa"});
		bool expectedOutput = false;
		std::cout << "===== Test s = " << s << ", wordDict = " << Vector2Str(wordDict) << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution->wordBreak(s, wordDict);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example8()
	{
		// ARRANGE
		std::string s = "goalspecial";
		std::vector<std::string> wordDict({"go","goal","goals","special"});
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", wordDict = " << Vector2Str(wordDict) << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution->wordBreak(s, wordDict);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example9()
	{
		// ARRANGE
		std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
		std::vector<std::string> wordDict({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
		bool expectedOutput = false;
		std::cout << "===== Test s = " << s << ", wordDict = " << Vector2Str(wordDict) << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution->wordBreak(s, wordDict);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	std::unique_ptr<IWordBreak> mSolution;
};

int main(int argc, char** argv)
{
	TestWordBreak test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	test.Example8();
	test.Example9();
	getchar();
	return EXIT_SUCCESS;
}