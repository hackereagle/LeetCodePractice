#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
		std::vector<std::vector<int>> ret;

		int target = graph.size() - 1;

		std::vector<int> pathRecord;
		pathRecord.push_back(0);
		Travel(graph, 0, target, pathRecord, ret);

		return ret;
	}

private:
	void Travel(std::vector<std::vector<int>> &graph, int cur, int &target, std::vector<int> &pathRecord, std::vector<std::vector<int>> &result)
	{
		//std::cout << cur << std::endl;
		if (cur == target)
			result.push_back(pathRecord);

		size_t len = graph[cur].size();
		
		for (int i = 0; i < len; i++) {
			pathRecord.push_back(graph[cur][i]);
			Travel(graph, graph[cur][i], target, pathRecord, result);
			pathRecord.pop_back();
		}
		
	} 
};

class TestAllPathsSourceTarget
{
public:
	TestAllPathsSourceTarget()
	{}

	~TestAllPathsSourceTarget()
	{}

	void Example1()
	{
		std::vector<std::vector<int>> graph({{1,2},{3},{3},{}});
		std::vector<std::vector<int>> expected({{0,1,3},{0,2,3}});
		std::cout << "===== Test graph = " << Vector2Str(graph) << "\", output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.allPathsSourceTarget(graph);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example2()
	{
		std::vector<std::vector<int>> graph({{4,3,1},{3,2,4},{3},{4},{}});
		std::vector<std::vector<int>> expected({{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}});
		std::cout << "===== Test graph = " << Vector2Str(graph) << "\", output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.allPathsSourceTarget(graph);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example3()
	{
		std::vector<std::vector<int>> graph({{4,3,1},{3,2,4},{},{4},{}} );
		std::vector<std::vector<int>> expected({{0,4},{0,3,4},{0,1,3,4},{0,1,4}});
		std::cout << "===== Test graph = " << Vector2Str(graph) << "\", output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.allPathsSourceTarget(graph);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example4()
	{
		std::vector<std::vector<int>> graph({{2},{},{1}});
		std::vector<std::vector<int>> expected({{0,2}});
		std::cout << "===== Test graph = " << Vector2Str(graph) << "\", output " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.allPathsSourceTarget(graph);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestAllPathsSourceTarget test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}