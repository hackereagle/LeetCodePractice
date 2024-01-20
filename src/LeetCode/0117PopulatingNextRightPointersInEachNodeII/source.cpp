#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
		if (root == nullptr)
			return nullptr;

		std::queue<Node*> q;
		q.push(root);
		int count = 1;
		while (q.size() > 0) {
			LinkNextAndPushChildNode2Queue(q, count);
		}

		return root;
	}

private:
	void LinkNextAndPushChildNode2Queue(std::queue<Node*> &q, int &count)
	{
		Node* node = nullptr;
		int len = count;
		count = 0;
		for (int i = 0; i < len; i++) {
			node = q.front();
			q.pop();

			if (i < len - 1) {
				node->next = q.front();
			}


			if (node->left) {
				q.push(node->left);
				count = count + 1;
			}

			if (node->right) {
				q.push(node->right);
				count = count + 1;
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
		Node* root = CreateNextTreeNothingNextWithLeetcodeInputStr("[1,2,3,4,5,null,7]");
		std::string expectedOutput = "[1,#,2,3,#,4,5,7,#]";
		std::cout << "===== Test root = " << ToLeetcodeStr(root) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		Node* result = this->mSolution.connect(root);

		// ASSERT
		std::string resultStr = ToLeetcodeAnsStr(result);
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