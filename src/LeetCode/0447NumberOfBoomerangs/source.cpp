#include <iostream>
#include <vector>
#include <unordered_map>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
		int nums = 0;

		size_t len = points.size();
		// calculate distance between each points
		std::vector<distPointsMap> table(len);
		for (int i = 0; i < len; i++) {
			distPointsMap map;
			std::vector<int> cur = points[i];
			for (int j = i + 1; j < len; j++) {
				int dist = this->CalculateDistance(cur, points[j]);
				table[i][dist]++;
				table[j][dist]++;
			}

			// calculate number of boomeranges
			for (auto &m : table[i]) {
				if (m.second >= 2) {
					nums = nums + (m.second * (m.second - 1));
				}
			}
		}

		//this->PrintDistPointMapList(table, points); // debug

		return nums;
	}

private:
	typedef std::vector<int> point;
	typedef std::unordered_map<int, int> distPointsMap; // key: distance, value: count

	int CalculateDistance(std::vector<int> p1, std::vector<int> p2)
	{
		double dist = 0;
		dist = std::hypot(p2[0] - p1[0], p2[1] - p1[1]);
		return static_cast<int>(dist * 10000.0);
	}

	void PrintDistPointMapList(std::vector<distPointsMap> &list, std::vector<point>& points)
	{
		int idx = 0; // debug
		for (auto &t : list) {
			std::cout << idx << " point [" << points[idx][0] << ", " << points[idx][1] << "]: " << std::endl;
			for (auto &m : t) {
				std::cout << "\tdistance = " << m.first << ", count = " << m.second;
				std::cout << std::endl;
			}
			idx = idx + 1;
		}
	}
};

class TestNumberOfBoomerangs
{
public:
	TestNumberOfBoomerangs()
	{}

	~TestNumberOfBoomerangs()
	{}

	void Example1()
	{
		std::vector<std::vector<int>> input({{0,0},{1,0},{2,0}});
		std::cout << "===== Test input " << Vector2Str(input) << ", output 2 =====" << std::endl;

		int reslut = this->mSolution.numberOfBoomerangs(input);

		AssertClass::GetInstance().Assert(reslut == 2);
	}

	void Example2()
	{
		std::vector<std::vector<int>> input({{1,1},{2,2},{3,3}});
		std::cout << "===== Test input " << Vector2Str(input) << ", output 2 =====" << std::endl;

		int reslut = this->mSolution.numberOfBoomerangs(input);

		AssertClass::GetInstance().Assert(reslut == 2);
	}

	void Example3()
	{
		std::vector<std::vector<int>> input({{1,1}});
		std::cout << "===== Test input " << Vector2Str(input) << ", output 0 =====" << std::endl;

		int reslut = this->mSolution.numberOfBoomerangs(input);

		AssertClass::GetInstance().Assert(reslut == 0);
	}

	void Example4()
	{
		std::vector<std::vector<int>> input({{-1,0},{0,0},{1,0},{2,0}});
		std::cout << "===== Test input " << Vector2Str(input) << ", output 4 =====" << std::endl;

		int reslut = this->mSolution.numberOfBoomerangs(input);

		AssertClass::GetInstance().Assert(reslut == 4);
	}

	void Example5()
	{
		std::vector<std::vector<int>> input({{0,0},{1,0},{-1,0},{0,1},{0,-1}});
		std::cout << "===== Test input " << Vector2Str(input) << ", output 20 =====" << std::endl;

		int reslut = this->mSolution.numberOfBoomerangs(input);

		AssertClass::GetInstance().Assert(reslut == 20);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestNumberOfBoomerangs test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}