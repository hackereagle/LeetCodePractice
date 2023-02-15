#pragma once

#include <string>
#include "LeetCodeGraphMiscs.hpp"

class TestLeetcodeGraphMiscClass
{
public:
	TestLeetcodeGraphMiscClass()
	{}

	~TestLeetcodeGraphMiscClass()
	{}

	void TestGenerateAdjList()
	{
		std::string adj = "[[2,4],[1,3],[2,4],[1,3]]";

		Node* graph = CreateAdjList(adj);
		PrintAdjList(graph);
	}
};