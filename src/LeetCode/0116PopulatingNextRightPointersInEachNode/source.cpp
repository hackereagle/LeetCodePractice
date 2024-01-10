#include <iostream>
#include <string>
#include <queue>
#include "LeetcodeNextTreeNodeMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	Node* connect(Node* root) {
		if (!root)
			return root;

		std::queue<Node*> waitPopulated;
		waitPopulated.push(root);
		int counter[2]{1, 0};
		int cur = 0, nextGen = 1;
		Node* curNode = nullptr;
		while(waitPopulated.size() > 0) {
			PopulateAndCollectedChildNodes(waitPopulated, counter[cur], counter[nextGen]);
			counter[cur] = 0;

			std::swap(cur, nextGen);
		}

		return root;
	}

private:
	void PopulateAndCollectedChildNodes(std::queue<Node*> &waitPopulated, int count, int &nextGen)
	{
		Node* curNode = nullptr;
		Node* preNode = nullptr;
		for (int i = 0; i < count; i++) {
			curNode = waitPopulated.front();
			waitPopulated.pop();

			if (preNode) {
				preNode->next = curNode;
			}

			if (curNode->left) {
				waitPopulated.push(curNode->left);
				nextGen = nextGen + 1;
			}
			if (curNode->right) {
				waitPopulated.push(curNode->right);
				nextGen = nextGen + 1;
			}

			preNode = curNode;
			if (i == count - 1) {
				curNode->next = nullptr;
			}
		}
	}
};

class TestConnect
{
public:
	TestConnect()
	{}

	~TestConnect()
	{}

	void Example1()
	{
		// ARRANGE
		Node* root = CreateNextTreeNothingNextWithLeetcodeInputStr("[1,2,3,4,5,6,7]");
		std::string expectedOutput = "[1,#,2,3,#,4,5,6,7,#]";
		std::cout << "===== Test root = " << ToLeetcodeStr(root) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		Node* result = this->mSolution.connect(root);

		// ASSERT
		std::string resultStr = ToLeetcodeAnsStr(result);
		// std::cout << resultStr << ", size = " << resultStr.size() << ", expected size = " << expectedOutput.size() << std::endl;
		AssertClass::GetInstance().Assert(resultStr == expectedOutput);
		ReleaseNextTree(root);
	}

	void Example2()
	{
		// ARRANGE
		Node* root = CreateNextTreeNothingNextWithLeetcodeInputStr("[]");
		std::string expectedOutput = "[]";
		std::cout << "===== Test root = " << ToLeetcodeStr(root) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		Node* result = this->mSolution.connect(root);

		// ASSERT
		std::string resultStr = ToLeetcodeAnsStr(result);
		AssertClass::GetInstance().Assert(resultStr == expectedOutput);
		ReleaseNextTree(root);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestConnect test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}