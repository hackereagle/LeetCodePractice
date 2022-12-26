#include <iostream>
#include <vector>
#include <string>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
    Solution()
    {}

    ~Solution()
    {}

    std::vector<double> getCollisionTimes(std::vector<std::vector<int>>& cars) {
        std::vector<double> ans(cars.size(), -1.0);

        size_t len = cars.size();
        std::vector<int> stillInRoadCarsOrder;
        for (int i = len - 1; i >= 0; i--) {
            double curCarPos = static_cast<double>(cars[i][0]);
            double curCarSpeed = static_cast<double>(cars[i][1]);

            while (!stillInRoadCarsOrder.empty()) {
                int idx = stillInRoadCarsOrder.back();
                double carPos = static_cast<double>(cars[idx][0]);
                double carSpeed = static_cast<double>(cars[idx][1]);

                double t = (curCarPos - carPos) / (carSpeed - curCarSpeed);
                if (carSpeed >= curCarSpeed || (t > ans[idx] && ans[idx] > 0)) {
                    stillInRoadCarsOrder.pop_back();
                }
                else {
                    break;
                }
            }

            if (!stillInRoadCarsOrder.empty()) {
                int idx = stillInRoadCarsOrder.back();
                double carPos = static_cast<double>(cars[idx][0]);
                double carSpeed = static_cast<double>(cars[idx][1]);
                ans[i] = (curCarPos - carPos) / (carSpeed - curCarSpeed);
            }

            stillInRoadCarsOrder.push_back(i);
        }
        return ans;
    }

private:
};

class TestGetCollisionTimes
{
public:
	TestGetCollisionTimes()
	{}

	~TestGetCollisionTimes()
	{}

    void Example1()
    {
        std::cout << "Test input cars = [[1,2],[2,1],[4,3],[7,2]] and output [1.00000,-1.00000,3.00000,-1.00000]" << std::endl;;
        std::vector<std::vector<int>> cars({{1,2},{2,1},{4,3},{7,2}});
        std::vector<double> ans({1.00000,-1.00000,3.00000,-1.00000});

        std::vector<double> result = this->mSolution.getCollisionTimes(cars);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, ans));
    }

    void Example2()
    {
        std::cout << "Test input cars = [[3,4],[5,4],[6,3],[9,1]] and output  [2.00000,1.00000,1.50000,-1.00000]" << std::endl;;
        std::vector<std::vector<int>> cars({{3,4},{5,4},{6,3},{9,1}});
        std::vector<double> ans({2.00000,1.00000,1.50000,-1.00000});

        std::vector<double> result = this->mSolution.getCollisionTimes(cars);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, ans));
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestGetCollisionTimes test;
    test.Example1();
    test.Example2();
	getchar();
	return EXIT_SUCCESS;
}