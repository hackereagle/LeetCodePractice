#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings) {
		std::vector<std::vector<int>> skyline;

		std::priority_queue<ContourPoint, std::vector<ContourPoint>, struct cmp> pointQueue = CreateEachPosition(buildings);

		std::multiset<int> heightsSet{0};
		ContourPoint cur;
		int goingOnHeight = 0, curHightest = 0;
		while (!pointQueue.empty()) {
			cur = pointQueue.top();
			pointQueue.pop();

			if (cur.Height < 0) {
				heightsSet.insert(-cur.Height);
			}
			else {
				heightsSet.erase(heightsSet.find(cur.Height));
			}

			curHightest = *heightsSet.rbegin();
			// std::cout << cur.Position << ", " << cur.Height << ", " << curHightest << std::endl;
			if (goingOnHeight != curHightest) {
				goingOnHeight = curHightest;
				skyline.push_back(std::vector<int>({cur.Position, goingOnHeight}));
			}
		}

		return skyline;
	}
private:
	struct ContourPoint
	{
		int Position = 0;
		int Height = 0;
		ContourPoint() = default;
		ContourPoint(int pos, int h) : Position(pos), Height(h) {}

		std::string ToString()
		{
			std::string str;
			str = "[" + std::to_string(this->Position) + ", " + std::to_string(this->Height) + "]";
			return str; 
		}
	};

	struct cmp
	{
		bool operator() (ContourPoint &l, ContourPoint &r) 
		{ 
			if (l.Position == r.Position && l.Height > r.Height )
				return true;
			else if (l.Position > r.Position)
				return true;
			else
				return false;
		}
	};
	
	std::priority_queue<ContourPoint, std::vector<ContourPoint>, struct cmp> CreateEachPosition(std::vector<std::vector<int>> &buildings)
	{
		std::priority_queue<ContourPoint, std::vector<ContourPoint>, struct cmp> res;
		for (auto &b : buildings) {
			res.push(ContourPoint(b[0], -b[2]));
			res.push(ContourPoint(b[1], b[2]));
		}

		return res;
	}
};

class TestGetSkyline
{
public:
	TestGetSkyline()
	{}

	~TestGetSkyline()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}});
		std::vector<std::vector<int>> expectedOutput({{2,10},{3,15},{7,12},{12,0},{15,10},{20,8},{24,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{0,2,3},{2,5,3}});
		std::vector<std::vector<int>> expectedOutput({{0,3},{5,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example3()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{0,2147483647,2147483647}});
		std::vector<std::vector<int>> expectedOutput({{0,2147483647},{2147483647,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example4()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{1,2,1},{1,2,2},{1,2,3}});
		std::vector<std::vector<int>> expectedOutput({{1,3},{2,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example5()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{0,3,3},{1,5,3},{2,4,3},{3,7,3}});
		std::vector<std::vector<int>> expectedOutput( {{0,3},{7,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example6()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{1,20,1},{1,21,2},{1,22,3}});
		std::vector<std::vector<int>> expectedOutput({{1,3},{22,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example7()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{2,14,4},{4,8,8},{6,16,4}});
		std::vector<std::vector<int>> expectedOutput({{2,4},{4,8},{8,4},{16,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example8()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}} );
		std::vector<std::vector<int>> expectedOutput({{2,10},{3,15},{7,12},{12,0},{15,10},{20,8},{24,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example9()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{1,25,20},{2,9,10},{5,12,12},{15,20,10},{19,24,8}});
		std::vector<std::vector<int>> expectedOutput( {{1,20},{25,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example10()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{2,9,10},{3,23,20},{5,12,12},{15,20,10},{19,24,8}} );
		std::vector<std::vector<int>> expectedOutput({{2,10},{3,20},{23,8},{24,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

	void Example11()
	{
		// ARRANGE
		std::vector<std::vector<int>> buildings({{1,20,1}});
		std::vector<std::vector<int>> expectedOutput({{1,1},{20,0}});
		std::cout << "===== Test buildings = " << Vector2Str(buildings) << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		std::vector<std::vector<int>> result = this->mSolution.getSkyline(buildings);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestGetSkyline test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	test.Example8();
	test.Example9();
	test.Example10();
	test.Example11();
	getchar();
	return EXIT_SUCCESS;
}