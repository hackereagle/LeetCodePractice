#include <iostream>
#include <vector>
#include <string>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> ret;

		_results.clear();
		if (n == 1) {
			ret.push_back("()");
		}
		else {
			_results = std::vector<std::vector<std::string>>(n);
			_results[0].push_back("()");
			Helper(n, 2);

			ret = _results[n - 1];
		}
		
		return ret;
	}

private:
	std::vector<std::vector<std::string>> _results;

	void Helper(const int target, int curLevel)
	{
		std::unordered_map<std::string, bool> notes;
		int currentLevel = curLevel - 1;
		std::string nextResult = "", parenthesis = "";
		int len = 0;
		for (auto &p : _results[currentLevel - 1]) {
			parenthesis = p;
			len = parenthesis.size();
			for (int i = 0; i < len; i++) {
				nextResult = parenthesis.substr(0, i + 1) + "()";
				if (i < len - 1) {
					nextResult = nextResult + parenthesis.substr(i + 1, len - i - 1);
				}

				if (notes.find(nextResult) == notes.end()) {
					_results[currentLevel].push_back(nextResult);
					notes.insert(std::pair<std::string, bool>(nextResult, true));
				}
			}
		}

		if (curLevel != target) {
			Helper(target, curLevel + 1);
		}
	}
};

class TestGenerateParenthesis
{
public:
	TestGenerateParenthesis()
	{}

	~TestGenerateParenthesis()
	{}

	void Example1()
	{
		int n = 3;
		std::vector<std::string> expected({"((()))","(()())","(())()","()(())","()()()"});
		std::cout << "===== Test n = " << n << ", expected output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::string> result = this->mSolution.generateParenthesis(n);

		AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, expected));
	}

	void Example2()
	{
		int n = 1;
		std::vector<std::string> expected({"()"});
		std::cout << "===== Test n = " << n << ", expected output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::string> result = this->mSolution.generateParenthesis(n);

		AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, expected));
	}

	void Example3()
	{
		int n = 5;
		std::vector<std::string> expected({"((((()))))","(((()())))","(((())()))","(((()))())","(((())))()","((()(())))","((()()()))","((()())())","((()()))()","((())(()))","((())()())","((())())()","((()))(())","((()))()()","(()((())))","(()(()()))","(()(())())","(()(()))()","(()()(()))","(()()()())","(()()())()","(()())(())","(()())()()","(())((()))","(())(()())","(())(())()","(())()(())","(())()()()","()(((())))","()((()()))","()((())())","()((()))()","()(()(()))","()(()()())","()(()())()","()(())(())","()(())()()","()()((()))","()()(()())","()()(())()","()()()(())","()()()()()"});
		std::cout << "===== Test n = " << n << ", expected output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::string> result = this->mSolution.generateParenthesis(n);

		AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, expected));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestGenerateParenthesis test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}