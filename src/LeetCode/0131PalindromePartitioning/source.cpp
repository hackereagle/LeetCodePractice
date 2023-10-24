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
	
	std::vector<std::vector<std::string>> partition(std::string s) {
		std::vector<std::vector<std::string>> res;

		std::vector<std::string> tmpAns;
		PartitionHelper(s, tmpAns, res);

		return res;
	}

private:
	void PartitionHelper(std::string &s, std::vector<std::string> &tmp, std::vector<std::vector<std::string>> &res)
	{
		if (s.size() == 0 || s == "")
		{
			res.push_back(tmp);
			return;
		}

		size_t len = s.size();
		std::string subStr = "";
		std::string remain = "";
		for (int i = 0; i < len; i++) {
			subStr = s.substr(0, i + 1);
			if (IsPalindrome(subStr)) {
				tmp.push_back(subStr);

				remain = s.substr(i + 1);
				//PrintDebugInformaiotn(subStr, remain, tmp); // debug
				PartitionHelper(remain, tmp, res);

				tmp.pop_back();
			}
		}
	}

	bool IsPalindrome(std::string &s)
	{
		bool isPalindrome = true;
		
		size_t head = 0;
		size_t tail = s.size() - 1;
		while (tail > head) {
			if (s[head] != s[tail]) {
				isPalindrome = false;
				break;
			}

			head = head + 1;
			tail = tail - 1;
		}

		return isPalindrome;
	}

	void PrintDebugInformaiotn(std::string &subStr, std::string &remain, std::vector<std::string> &tmp)
	{
		int tabNum = tmp.size() - 1;
		for (int i = 0; i < tabNum; i++) {
			std::cout << "\t";
		}
		std::cout << "subStr = " << subStr << ", remain = " << remain << std::endl;
	}
};

class TestPartition
{
public:
	TestPartition()
	{}

	~TestPartition()
	{}

	void Example1()
	{
		// ARRANGE
		std::string s = "aab";
		std::vector<std::vector<std::string>> expectedOutput({{"a","a","b"},{"aa","b"}});
		std::cout << "===== Test s = " << s << "; output = " << Vector2Str(expectedOutput) << " true =====" << std::endl;

		// ACT
		std::vector<std::vector<std::string>> result = this->mSolution.partition(s);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestPartition test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}