#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int findCircleNum(std::vector<std::vector<int>>& isConnected) {
		int count = 0;
		std::vector<bool> visisted(isConnected.size(), false);

		for (int i = 0; i < isConnected.size(); i++) {
			if (!visisted[i]) {
				Dfs(isConnected, visisted, i);
				count = count + 1;
			}
		}

		return count;
	}

private:
	void Dfs(std::vector<std::vector<int>> &isConnected, std::vector<bool> &visisted, int node)
	{
		int len = isConnected.size();
		int n = node;
		std::stack<int> next;
		next.push(n);
		visisted[n] = true;
		while (next.size()) {
			n = next.top();
			next.pop();
			visisted[n] = true;

			for (int i = 0; i < len; i++) {
				if (!visisted[i] && isConnected[n][i] == 1) {
					next.push(i);
				}
			}
		}
	}
};

class TestFindCircleNum
{
public:
	TestFindCircleNum()
	{}

	~TestFindCircleNum()
	{}

	void Example1()
	{
		std::vector<std::vector<int>> isConnected({{1,1,0},{1,1,0},{0,0,1}});
		int expectedNumProvinces = 2;
		std::cout << "===== Test isConnected = " << Vector2Str(isConnected) << ", output = " << expectedNumProvinces << " =====" << std::endl;

		int result = this->mSolution.findCircleNum(isConnected);

		AssertClass::GetInstance().Assert(result == expectedNumProvinces);
	}

	void Example2()
	{
		std::vector<std::vector<int>> isConnected({{1,0,0},{0,1,0},{0,0,1}});
		int expectedNumProvinces = 3;
		std::cout << "===== Test isConnected = " << Vector2Str(isConnected) << ", output = " << expectedNumProvinces << " =====" << std::endl;

		int result = this->mSolution.findCircleNum(isConnected);

		AssertClass::GetInstance().Assert(result == expectedNumProvinces);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestFindCircleNum test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}