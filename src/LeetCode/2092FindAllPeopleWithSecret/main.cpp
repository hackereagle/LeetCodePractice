#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
    }

    std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
        std::vector<int> res;
        
        std::vector<std::vector<GraphNode>> graph(n);
        std::vector<int> time(n, std::numeric_limits<int>::max());
        graph[0].push_back(GraphNode(firstPerson, 0));
        graph[firstPerson].push_back(GraphNode(0, 0));
        for (auto m : meetings) {
            graph[m[0]].push_back(GraphNode(m[1], m[2]));
            //std::cout << m[0] << " -> " << m[1] << std::endl; // debug
            graph[m[1]].push_back(GraphNode(m[0], m[2]));
            //std::cout << m[1] << " -> " << m[0] << std::endl; // debug
        }

        std::priority_queue<GraphNode, std::vector<GraphNode>, cmp> pq;
        for (auto g : graph[0]) {
            pq.push(g);
        }
        
        while (!pq.empty()) {
            GraphNode gn = pq.top();
            pq.pop();
            int curTime = gn.weight;
            //std::cout << "iterate " << gn.node << ", time = " << gn.weight << std::endl; // debug

            for (auto n : graph[gn.node]) {
                int nextTime = n.weight;
                //std::cout << "\t in " << n.node << ", time = " << nextTime << ", cost = " << time[n.node] << std::endl; //debug
                if (nextTime < time[n.node] && nextTime >= curTime) {
                    //std::cout << "\ttime[" << n.node << "] = " << nextTime << std::endl;
                    time[n.node] = nextTime;
                    pq.push(n);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (time[i] != std::numeric_limits<int>::max()) res.push_back(i);
        }
        return res;
    }

private:
    struct graphNode{
        int node = -1;
        int weight = -1;

        graphNode(int n, int w): node(n), weight(w) {}
    };
    typedef struct graphNode GraphNode;

    struct cmp{
        bool operator()(GraphNode r, GraphNode l)
        {
            return r.weight < l.weight;
        }
    };
};

class TestFindAllPeople
{
public:
	TestFindAllPeople()
	{}

	~TestFindAllPeople()
	{}

    void Example1()
    {
        std::cout << "========= Test total 6 person and meetings = [[1,2,5],[2,3,8],[1,5,10]], first person = 1 =========" << std::endl;
        int n = 6;
        std::vector<std::vector<int>> meetings({{1,2,5},{2,3,8},{1,5,10}});
        int firstPerson = 1;

        std::vector<int> result = this->mSolution.findAllPeople(n, meetings, firstPerson);
        std::vector<int> ans({0,1,2,3,5});
        AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, ans));
    }

    void Example2()
    {
        std::cout << "========= Test total 4 person and meetings = [[3,1,3],[1,2,2],[0,3,3]], first person = 3 =========" << std::endl;
        int n = 4;
        std::vector<std::vector<int>> meetings({{3,1,3},{1,2,2},{0,3,3}});
        int firstPerson = 3;

        std::vector<int> result = this->mSolution.findAllPeople(n, meetings, firstPerson);
        std::vector<int> ans({0,1,3});
        AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, ans));
    }

    void Example3()
    {
        std::cout << "========= Test total 5 person and meetings = [[3,4,2],[1,2,1],[2,3,1]], first person = 1 =========" << std::endl;
        int n = 5;
        std::vector<std::vector<int>> meetings({{3,4,2},{1,2,1},{2,3,1}});
        int firstPerson = 1;

        std::vector<int> result = this->mSolution.findAllPeople(n, meetings, firstPerson);
        std::vector<int> ans({0,1,2,3,4});
        AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, ans));
    }

    void Example4()
    {
        std::cout << "========= Test total 11 person and meetings = [[5,1,4],[0,4,18]], first person = 1 =========" << std::endl;
        int n = 11;
        std::vector<std::vector<int>> meetings({{5,1,4},{0,4,18}});
        int firstPerson = 1;

        std::vector<int> result = this->mSolution.findAllPeople(n, meetings, firstPerson);
        std::vector<int> ans({0, 1, 4, 5});
        AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, ans));
    }

    void Example5()
    {
        std::cout << "========= Test total 5 person and meetings = [[1,4,3],[0,4,3]], first person = 3 =========" << std::endl;
        int n = 5;
        std::vector<std::vector<int>> meetings({{1,4,3},{0,4,3}});
        int firstPerson = 3;

        std::vector<int> result = this->mSolution.findAllPeople(n, meetings, firstPerson);
        std::vector<int> ans({0, 1, 3, 4});
        AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, ans));
    }

    void Example6()
    {
        std::cout << "========= Test total 4 person and meetings = [[3,1,3],[1,2,2],[0,3,3]], first person = 3 =========" << std::endl;
        int n = 4;
        std::vector<std::vector<int>> meetings({{3,1,3},{1,2,2},{0,3,3}});
        int firstPerson = 3;

        std::vector<int> result = this->mSolution.findAllPeople(n, meetings, firstPerson);
        std::vector<int> ans({0,1,3});
        AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, ans));
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestFindAllPeople test;
    test.Example1();
    test.Example2();
    test.Example3();
    test.Example4();
    test.Example5();
    test.Example6();
	getchar();
	return EXIT_SUCCESS;
}