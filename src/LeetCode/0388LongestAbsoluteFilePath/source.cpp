#include <iostream>
#include <string>
#include <stack>
#include "StringMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int lengthLongestPath(std::string input) {
		int ret = 0;

		std::stack<int> pathsLen;
		std::string folderOrFile = "";
		int curLevel = 1;
		int tmpLen = 0;
		while (input != "") {
			//std::cout << "/*** " << std::endl;
			UpdateCurLevel(input, pathsLen, tmpLen, curLevel);
			folderOrFile = GetFolderOrFilename(input);
			//std::cout << "*** folderOrFile = " << folderOrFile << std::endl;

			int curFolderOrFileLen = 0;
			if (IsFile(folderOrFile)) {
				curFolderOrFileLen = folderOrFile.size();
				tmpLen = tmpLen + curFolderOrFileLen;
				ret = std::max(ret, tmpLen);
			}
			else {
				curFolderOrFileLen = folderOrFile.size() + 1;
				tmpLen = tmpLen + curFolderOrFileLen;
			}
			pathsLen.push(curFolderOrFileLen);

			//std::cout << "***/ tmpLen = " << tmpLen << ", folderOrFile = " << folderOrFile << ", input = " << input << std::endl; // debug
			
		}
		return ret;
	}

private:
	bool IsFile(std::string str)
	{
		return str.find('.') != std::string::npos;
	}

	std::string GetFolderOrFilename(std::string &str)
	{
		std::string ret = "";
		int pos = str.find('\n');
		if (pos != std::string::npos) {
			ret = str.substr(0, pos);
			str = str.substr(pos + 1);
		}
		else if (str != "") {
			ret = str;
			str = "";
		}
		return ret;
	}

	void UpdateCurLevel(std::string &input, std::stack<int> &pathsLen, int &tmpLen, int &curLevel)
	{
		if (input.size() < 1) 
			return;

		int i =0;
		int level = 1;
		while (input[i] == '\t') {
			//std::cout << "=== i = " << i << std::endl;
			level = level + 1;
			i++;
		}
		input = input.substr(i);
		//std::cout << "=== In PopStackToNextItemLevel: level = " << level << ", curLevel = " << curLevel << std::endl; // debug

		if (level > curLevel) {
			curLevel = curLevel + 1;
		}
		else if (level == curLevel || level == 1) {
			if (pathsLen.size() > 1 && level > 1) {
				int tmp = pathsLen.top();
				tmpLen = tmpLen - tmp;
				pathsLen.pop();
			}
			else {
				tmpLen = 0;
				curLevel = 1;
			}
			
			//std::cout << "=== curLevel == level || level == 1, input = " << input << ", curLevel = " << curLevel << std::endl; // debug
		}
		else {
			// pop stack to coresponding level and update current level
			while (curLevel >= level) {
				int tmp = pathsLen.top();
				//std::cout << "=== stack size = " << pathsLen.size() << ", tmp = " << tmp << std::endl; // debug
				tmpLen = tmpLen - tmp;
				pathsLen.pop();
				curLevel = curLevel - 1;
			}
			curLevel = level;
			//std::cout << "=== curLevel = " << curLevel << ", level = " << level << ", tmpLen = " << tmpLen << std::endl; // debug
		}
	}
};

class TestLengthLongestPath
{
public:
	TestLengthLongestPath()
	{}

	~TestLengthLongestPath()
	{}

	void Example1()
	{
		std::string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
		int expected = 32;
		std::cout << "===== Test input \"" << ReplaceEscapeCharStr(input) << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.lengthLongestPath(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		std::string input = "a";
		int expected = 0;
		std::cout << "===== Test input \"" << ReplaceEscapeCharStr(input) << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.lengthLongestPath(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		std::string input = "file1.txt\nfile2.txt\nlongfile.txt";
		int expected = 12;
		std::cout << "===== Test input \"" << ReplaceEscapeCharStr(input) << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.lengthLongestPath(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		std::string input = "dir\nfile1.txt\nfile2.txt\nlongfile.txt";
		int expected = 12;
		std::cout << "===== Test input \"" << ReplaceEscapeCharStr(input) << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.lengthLongestPath(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example5()
	{
		std::string input = "a\n\tb.txt\na2\n\tb2.txt";
		int expected = 9;
		std::cout << "===== Test input \"" << ReplaceEscapeCharStr(input) << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.lengthLongestPath(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example6()
	{
		std::string input = "skd\n\talskjv\n\t\tlskjf\n\t\t\tklsj.slkj\n\t\tsdlfkj.sdlkjf\n\t\tslkdjf.sdfkj\n\tsldkjf\n\t\tlskdjf\n\t\t\tslkdjf.sldkjf\n\t\t\tslkjf\n\t\t\tsfdklj\n\t\t\tlskjdflk.sdkflj\n\t\t\tsdlkjfl\n\t\t\t\tlskdjf\n\t\t\t\t\tlskdjf.sdlkfj\n\t\t\t\t\tlsdkjf\n\t\t\t\t\t\tsldkfjl.sdlfkj\n\t\t\t\tsldfjlkjd\n\t\t\tsdlfjlk\n\t\t\tlsdkjf\n\t\tlsdkjfl\n\tskdjfl\n\t\tsladkfjlj\n\t\tlskjdflkjsdlfjsldjfljslkjlkjslkjslfjlskjgldfjlkfdjbljdbkjdlkjkasljfklasjdfkljaklwejrkljewkljfslkjflksjfvsafjlgjfljgklsdf.a";
		int expected = 133;
		std::cout << "===== Test input \"" << ReplaceEscapeCharStr(input) << "\", output " << expected << " =====" << std::endl;

		int result = this->mSolution.lengthLongestPath(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestLengthLongestPath test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	getchar();
	return EXIT_SUCCESS;
}