#include <iostream>
#include <sstream>
#include <string>
#include "StringMiscs.hpp"
#include "AssertClass.hpp"

// Definition for a Node.
class Node {
public:
    int val = -100000;
    Node* next = nullptr;
    Node* random = nullptr;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }

	Node() = default;
};

bool CopyTwoListSuccess(Node* left, Node* right)
{
	bool isSuccess = true;

	Node* headL = left;
	Node* headR = right;
	
	while (headL && headR) {
		if (headL == headR) {
			isSuccess = false;
			break;
		}

		if (headL->val != headR->val) {
			isSuccess = false;
			break;
		}

		if (headL->random && headR->random) {
			if (headL->random == headR->random	|| headL->random->val != headR->random->val) {
				isSuccess = false;
				break;
			}
		}
		else if ((!headL->random && headR->random) || (headL->random && !headR->random)) {
			isSuccess = false;
			break;
		}

		headL = headL->next;
		headR = headR->next;
	}

	return isSuccess;
}

Node* CreateList(std::string str)
{
	Node* head = nullptr;

	std::string list = str.substr(1, str.size() - 2);
	std::vector<std::string> nodesStr = SplitString(list, "],[");

	size_t len = nodesStr.size();
	std::vector<Node*> nodes(len, nullptr);
	for (int i = 0; i < len; i++) {
		nodes[i] = new Node();
	}

	std::vector<std::string> nodeInfo;
	std::string tmp;
	size_t index = 0;
	for (int i = 0; i < len; i++) {
		if (i == 0)
			tmp = nodesStr[i].substr(1);
		else if (i == len - 1)
			tmp = nodesStr[i].substr(0, nodesStr[i].size() - 1);
		else
			tmp = nodesStr[i];
		nodeInfo = SplitString(tmp, ",");

		nodes[i]->val = std::stoi(nodeInfo[0]);
		if (nodeInfo[1] == "null")
			nodes[i]->random = nullptr;
		else {
			index = std::stoi(nodeInfo[1]);
			nodes[i]->random = nodes[index];
		}

		if (i == len - 1)
			nodes[i]->next = nullptr;
		else
			nodes[i]->next = nodes[i + 1];
	}

	head = nodes[0];

	return head;
}

void ReleaseList(Node** head)
{
	Node* _head = *head;
	Node* tmp = nullptr;
	while (_head) {
		tmp = _head->next;

		delete _head;
		_head = nullptr;

		_head = tmp;
	}
}

std::string List2Str(Node* head)
{
	std::ostringstream ss;

	std::unordered_map<Node*, size_t> nodeIndex;
	int idx = 0;
	Node* ptr = head;
	while (ptr) {
		nodeIndex[ptr] = idx;
		ptr = ptr->next;
		idx = idx + 1;
	}

	ss << "[";
	while (head) {
		ss << "[";
		ss << head->val;
		ss << ",";
		if (head->random)
			ss << nodeIndex[head->random];
		else
			ss << "null";
		ss << "]";
		head = head->next;
	}
	ss << "]";
	return ss.str();
}

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	Node* copyRandomList(Node* head) {
        Node* dup = nullptr;

        if (!head)
            return dup;

        std::unordered_map<Node*, size_t> nodeIndex;
        int idx = 0;
        Node* ptr = head;
        while (ptr) {
            nodeIndex[ptr] = idx;
            ptr = ptr->next;
            idx = idx + 1;
        }

        std::vector<Node*> dupNodes(idx, nullptr);
        ptr = head;
        idx = 0;
        while (ptr) {
            dupNodes[idx] = new Node(ptr->val);

            if (idx == 0)
                dup = dupNodes[idx];
            else
                dupNodes[idx - 1]->next = dupNodes[idx];

            ptr = ptr->next;
            idx = idx + 1;
        }

        ptr = head;
        while (ptr) {
            if (ptr->random)
                dup->random = dupNodes[nodeIndex[ptr->random]];
            else
                dup->random = nullptr;

            dup = dup->next;
            ptr = ptr->next;
        }
        dup = dupNodes[0];

        return dup;
    }
};

class TestCopyRandomList
{
public:
	TestCopyRandomList()
	{}

	~TestCopyRandomList()
	{}

	void Example1()
	{
		Node* head = CreateList("[[1,1],[2,1]]");
		std::string str = List2Str(head);
		std::cout << "===== Test head = \"" << str << "\", output " << str << " =====" << std::endl;

		Node* result = this->mSolution.copyRandomList(head);

		AssertClass::GetInstance().Assert(CopyTwoListSuccess(head, result));
	}
	
	void Example2()
	{
		Node* head = CreateList("[[3,null],[3,0],[3,null]]");
		std::string str = List2Str(head);
		std::cout << "===== Test head = \"" << str << "\", output " << str << " =====" << std::endl;

		Node* result = this->mSolution.copyRandomList(head);

		AssertClass::GetInstance().Assert(CopyTwoListSuccess(head, result));
	}

	void Example3()
	{
		Node* head = CreateList("[[3,null],[10000,null],[-10000,null]]");
		std::string str = List2Str(head);
		std::cout << "===== Test head = \"" << str << "\", output " << str << " =====" << std::endl;

		Node* result = this->mSolution.copyRandomList(head);

		AssertClass::GetInstance().Assert(CopyTwoListSuccess(head, result));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestCopyRandomList test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}