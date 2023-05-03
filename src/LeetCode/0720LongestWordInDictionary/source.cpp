#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::string longestWord(std::vector<std::string>& words) {
		std::string ret = "";

		TrieNode* root = CreateTree(words);
		//PrintTreie(root); // debug
		//std::cout << "=====================" << std::endl;
		std::string tmp;
		DfsFindLongestWord(root, tmp, ret);
		ReleaseTrie(root);

		return ret;
	}

private:
	typedef struct _trieNode
	{
		char Alpha = ' ';
		int Count = 0;
		bool IsEnd = false;
		std::map<char, _trieNode*> Nodes;

		_trieNode(char alpha, int count = 0): Alpha(alpha), Count(count) {}

		static _trieNode* FindNodeFromRoot(_trieNode* root, char alpha)
		{
			_trieNode* node = nullptr;
			
			if (root->Nodes.find(alpha) != root->Nodes.end()) {
				node = root->Nodes[alpha];
			}
			return node;
		}
	} TrieNode;


	TrieNode* CreateTree(std::vector<std::string> &words)
	{
		TrieNode* root = new TrieNode(' ', 0);
		TrieNode* cur = nullptr;
		for (auto &w : words) {
			TrieNode* cur = root;
			TrieNode* next = nullptr;

			size_t len = w.size();
			for (int i = 0; i < len; i++) {
				next = TrieNode::FindNodeFromRoot(cur, w[i]);
				if (!next) {
					next = new TrieNode(w[i], 0);
					cur->Nodes[w[i]] = next;
				}

				next->Count = next->Count + 1;
				cur = next;
			}
			cur->IsEnd = true;
		}
		return root;
	}

	void DfsFindLongestWord(TrieNode* parNode, std::string& tmpStr, std::string& longestWord)
	{
		//std::cout << parNode->Alpha << ", " << parNode->Count << std::endl; // debug

		if (parNode->Nodes.size() == 0) {
			//std::cout << "\t* There are no nodes" << std::endl;
			if (tmpStr.size() > longestWord.size())
					longestWord = tmpStr;
			return;
		}

		for (auto n : parNode->Nodes) {
			//std::cout << "=== " << n.second->Alpha << ", " << n.second->Count << ", tmpStr = " << tmpStr << ", longestWord = " << longestWord << std::endl; // debug
			if (parNode->Count - n.second->Count > 0 && parNode->IsEnd) {
				//std::cout << "\tcurrent node\'s count at less than parent node 1" << std::endl; // debug
				tmpStr.push_back(n.second->Alpha);
				DfsFindLongestWord(n.second, tmpStr, longestWord);
				if (tmpStr.size() > longestWord.size() && n.second->IsEnd)
					longestWord = tmpStr;
				tmpStr.pop_back();
			}
			else if (parNode->Count == 0) {
				//std::cout << "\tparrent node\'s count is zero" << std::endl; // debug
				tmpStr.clear();
				tmpStr.push_back(n.second->Alpha);
				DfsFindLongestWord(n.second, tmpStr, longestWord);
				if (tmpStr.size() > longestWord.size() && n.second->IsEnd)
					longestWord = tmpStr;
				tmpStr.pop_back();
			}
		}
		//std::cout << "\tend" << ", tmpStr = " << tmpStr << " ===" << std::endl; // debug
	}

	void ReleaseTrie(TrieNode* &root)
	{
		if (root) {
			for (auto t : root->Nodes) {
				ReleaseTrie(t.second);
				delete t.second;
			}
		}
	}

	void PrintTreie(TrieNode* &root)
	{
		if (root) {
			for (auto t : root->Nodes) {
				PrintTreie(t.second);
				std::cout << "[" << t.second->Alpha << ", " << t.second->Count << "] ";
			}
			std::cout << std::endl;
		}
	}
};

class TestLongestWord
{
public:
	TestLongestWord()
	{}

	~TestLongestWord()
	{}

	void Example1()
	{
		std::vector<std::string> words({"w","wo","wor","worl","world"});
		std::string expected = "world";
		std::cout << "===== Test input words = " << Vector2Str(words) << ", output \"" << expected << "\" =====" << std::endl;

		std::string result = this->mSolution.longestWord(words);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		std::vector<std::string> words({"a","banana","app","appl","ap","apply","apple"});
		std::string expected = "apple";
		std::cout << "===== Test input words = " << Vector2Str(words) << ", output \"" << expected << "\" =====" << std::endl;

		std::string result = this->mSolution.longestWord(words);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		std::vector<std::string> words({"b","bo","boy","book","a","banana","app","appl","ap","apply","apple"});
		std::string expected = "apple";
		std::cout << "===== Test input words = " << Vector2Str(words) << ", output \"" << expected << "\" =====" << std::endl;

		std::string result = this->mSolution.longestWord(words);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		std::vector<std::string> words({"a","an","book","cat","boy"});
		std::string expected = "an";
		std::cout << "===== Test input words = " << Vector2Str(words) << ", output \"" << expected << "\" =====" << std::endl;

		std::string result = this->mSolution.longestWord(words);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example5()
	{
		std::vector<std::string> words({"tea","apple","g","book"});
		std::string expected = "g";
		std::cout << "===== Test input words = " << Vector2Str(words) << ", output \"" << expected << "\" =====" << std::endl;

		std::string result = this->mSolution.longestWord(words);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example6()
	{
		std::vector<std::string> words({"b","bo","boy","book"});
		std::string expected = "boy";
		std::cout << "===== Test input words = " << Vector2Str(words) << ", output \"" << expected << "\" =====" << std::endl;

		std::string result = this->mSolution.longestWord(words);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example7()
	{
		std::vector<std::string> words({"sg","qgca","s","qzu","qzub","qzubvs","hlyc","hl","qg","qzubv","qgc","qgcab","qz","sgs","sgsnyn","hly","hlycf","sgsn"});
		std::string expected = "sgsn";
		std::cout << "===== Test input words = " << Vector2Str(words) << ", output \"" << expected << "\" =====" << std::endl;

		std::string result = this->mSolution.longestWord(words);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example8()
	{
		std::vector<std::string> words({"rac","rs","ra","on","r","otif","o","onpdu","rsf","rs","ot","oti","racy","onpd"});
		std::string expected = "otif";
		std::cout << "===== Test input words = " << Vector2Str(words) << ", output \"" << expected << "\" =====" << std::endl;

		std::string result = this->mSolution.longestWord(words);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example9()
	{
		std::vector<std::string> words({"ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"});
		std::string expected = "e";
		std::cout << "===== Test input words = " << Vector2Str(words) << ", output \"" << expected << "\" =====" << std::endl;

		std::string result = this->mSolution.longestWord(words);

		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestLongestWord test;
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