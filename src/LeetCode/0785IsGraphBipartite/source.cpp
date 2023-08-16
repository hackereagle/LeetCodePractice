#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	bool isBipartite(std::vector<std::vector<int>>& graph) {
        bool isTwoPart = true;

        std::vector<Set> setNote(graph.size(), Set::None);
        std::vector<bool> visisted(graph.size(), false);
        std::queue<int> q;
        FindFirstNonSingleNode(graph, q, setNote, visisted, 0);
        int cur = -1;
        while (!IsAchieveTerminateCondition(q, visisted, cur)) {
            cur = q.front();
            q.pop();
            //std::cout << cur << std::endl;

            for (int i = 0; i < graph[cur].size(); i++) {
                if (!IsTheOtherSet(setNote[cur], graph[cur][i], setNote)) {
                    //std::cout << "\tIn cur = " << cur << ", its set = " << (int)setNote[cur] << ", vertics = " << graph[cur][i] << ", its set = " << (int)setNote[graph[cur][i]] << std::endl;
                    isTwoPart = false;
                    break;
                }

                if (!visisted[graph[cur][i]]) {
                    q.push(graph[cur][i]);
                    visisted[graph[cur][i]] = true;
                }
                    
            }

            if (!isTwoPart)
                break;
        }


        return isTwoPart;
    }

private:
    enum class Set : int
    {
        None,
        SET1,
        SET2,
    };

    bool IsTheOtherSet(Set curSet, int candidate, std::vector<Set> &setNote)
    {
        bool isTheOtherSet = false;
        if (setNote[candidate] == Set::None) {
            if (curSet == Set::SET1)
                setNote[candidate] = Set::SET2;
            else
                setNote[candidate] = Set::SET1;

            isTheOtherSet = true;
        }
        else {
            if (setNote[candidate] == curSet)
                isTheOtherSet = false;
            else
                isTheOtherSet = true;
        }
        return isTheOtherSet;
    }

    void FindFirstNonSingleNode(std::vector<std::vector<int>> &graph, std::queue<int> &q, std::vector<Set> &setNote, std::vector<bool> &visisted, int start)
    {
        int idx = start;
        while (idx < graph.size()) {
            if (graph[idx].size() == 0) {
                setNote[idx] = Set::SET1;
                visisted[idx] = true;
                idx = idx + 1;
            }
            else
                break;
        }
        
        if (idx < graph.size()) {
            q.push(idx);
            setNote[idx] = Set::SET1;
            visisted[idx] = true;
        }
        //std::cout << "In FindFirstNonSingleNode, final idx = " << idx << std::endl;
    }

    bool IsAchieveTerminateCondition(std::queue<int> &q, std::vector<bool> &visisted, int start)
    {
        //std::cout << "start = " << start << std::endl;
        bool isAchieveTerminateCondition = true;
        if (q.size() > 0)
            isAchieveTerminateCondition = false;
        else if (start > -1){
            for (int i = start; i < visisted.size(); i++) {
                if (!visisted[i]) {
                    visisted[i] = true;
                    q.push(i);
                    isAchieveTerminateCondition = false;
                    break;
                }
            }
        }
        
        return isAchieveTerminateCondition;
    }
};

class TestIsBipartite
{
public:
	TestIsBipartite()
	{}

	~TestIsBipartite()
	{}

	void Example1()
	{
		std::vector<std::vector<int>> graph({{1,2,3},{0,2},{0,1,3},{0,2}});
		bool expectedOutput = false;
		std::cout << "===== Test input = " << Vector2Str(graph) << ", expect output " << Bool2Str(expectedOutput) << " =====" << std::endl;

		bool result = this->mSolution.isBipartite(graph);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		std::vector<std::vector<int>> graph({{1,3},{0,2},{1,3},{0,2}});
		bool expectedOutput = true;
		std::cout << "===== Test input = " << Vector2Str(graph) << ", expect output " << Bool2Str(expectedOutput) << " =====" << std::endl;

		bool result = this->mSolution.isBipartite(graph);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		std::vector<std::vector<int>> graph({{}});
		bool expectedOutput = true;
		std::cout << "===== Test input = " << Vector2Str(graph) << ", expect output " << Bool2Str(expectedOutput) << " =====" << std::endl;

		bool result = this->mSolution.isBipartite(graph);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		std::vector<std::vector<int>> graph({{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}});
		bool expectedOutput = false;
		std::cout << "===== Test input = " << Vector2Str(graph) << ", expect output " << Bool2Str(expectedOutput) << " =====" << std::endl;

		bool result = this->mSolution.isBipartite(graph);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		std::vector<std::vector<int>> graph({{4},{},{4},{4},{0,2,3}});
		bool expectedOutput = true;
		std::cout << "===== Test input = " << Vector2Str(graph) << ", expect output " << Bool2Str(expectedOutput) << " =====" << std::endl;

		bool result = this->mSolution.isBipartite(graph);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example6()
	{
		std::vector<std::vector<int>> graph({{2,4},{2,3,4},{0,1},{1},{0,1},{7},{9},{5},{},{6},{12,14},{},{10},{},{10},{19},{18},{},{16},{15},{23},{23},{},{20,21},{},{},{27},{26},{},{},{34},{33,34},{},{31},{30,31},{38,39},{37,38,39},{36},{35,36},{35,36},{43},{},{},{40},{},{49},{47,48,49},{46,48,49},{46,47,49},{45,46,47,48}});
		bool expectedOutput = false;
		std::cout << "===== Test input = " << Vector2Str(graph) << ", expect output " << Bool2Str(expectedOutput) << " =====" << std::endl;

		bool result = this->mSolution.isBipartite(graph);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;

	std::string Bool2Str(bool b)
	{
		return b ? "true" : "false";
	}
};

int main(int argc, char** argv)
{
	TestIsBipartite test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	getchar();
	return EXIT_SUCCESS;
}