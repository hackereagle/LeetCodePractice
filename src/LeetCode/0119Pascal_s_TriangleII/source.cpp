#include <iostream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<int> getRow(int rowIndex) {
		if (rowIndex == 0)
			return std::vector<int>({1});

		if (rowIndex == 1)
			return std::vector<int>({1, 1});

		std::vector<int> ret({1, 1});
		std::vector<int> lastResult;
		int idx = 0;
		int len = 0;
		for (int i = 2; i <= rowIndex; i++) {
			lastResult = ret;
			len = lastResult.size();
			ret.clear();
			ret = std::vector(len + 1, 1);
			//PrintVector(ret); // debug
			//std::cout << "size = " << ret.size() << std::endl; // debug
			for (idx = 1; idx < len; idx++) {
				//std::cout << "\t" << idx << std::endl; // debug
				ret[idx] = lastResult[idx - 1] + lastResult[idx];
			}
		}

		return ret;
	}

private:
	void PrintVector(std::vector<int> vec)
	{
		std::cout << "[";
		for (auto &v : vec)
			std::cout << v << " ";
		std::cout << "]" << std::endl;
	}
};

class TestGetRow
{
public:
	TestGetRow()
	{}

	~TestGetRow()
	{}

	void Example1()
	{
		int rowIndex = 0;
		std::vector<int> expected({1});
		std::cout << "===== Test rowIndex = " << rowIndex << ", output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<int> result = this->mSolution.getRow(rowIndex);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example2()
	{
		int rowIndex = 1;
		std::vector<int> expected({1, 1});
		std::cout << "===== Test rowIndex = " << rowIndex << ", output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<int> result = this->mSolution.getRow(rowIndex);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestGetRow test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}