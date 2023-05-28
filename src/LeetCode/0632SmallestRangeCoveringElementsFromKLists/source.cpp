#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
		std::vector<int> ret({-100000, 100000});

		size_t len = nums.size();
		if (len == 1) {
			ret = std::vector<int>({nums[0][0], nums[0][0]});
		}
		else {
			std::vector<std::pair<int, size_t>> totalElements = ArrangeAllElement(nums);
			//PrintVector(totalElements);
			
			ret = FindMinRangeFromTotalElements(nums, totalElements);
		}

		return ret;
	}

private:
	std::vector<std::pair<int, size_t>> ArrangeAllElement(std::vector<std::vector<int>> &nums)
	{
		std::vector<std::pair<int, size_t>> totalElements;

		size_t totalLen = 0;
		for (auto &l : nums) {
			totalLen = totalLen + l.size();
		}
		totalElements = std::vector<std::pair<int, size_t>>(totalLen, std::pair<int, size_t>(0, 0));
		
		int index = 0;
		for (int listOrder = 0; listOrder < nums.size(); listOrder++) {
			for (int j = 0; j < nums[listOrder].size(); j++) {
				totalElements[index].first = nums[listOrder][j];
				totalElements[index].second = listOrder;
				index = index + 1;
			}
		}

		std::sort(totalElements.begin(), totalElements.end(), 
			[](std::pair<int, size_t> n1, std::pair<int, size_t> n2){
				return n1.first < n2.first;
			});

		return totalElements;
	}

	std::vector<int> FindMinRangeFromTotalElements(std::vector<std::vector<int>>& nums, std::vector<std::pair<int, size_t>> &totalElements)
	{
		std::vector<int> ret({-100000, 100000});

		size_t len = nums.size();
		std::vector<int> eachArrCounter(len, 0);
		int alreadyVisitArr = 0;
		size_t left = 0, right = 0;
		size_t count = 0, listOrder = 0;
		std::vector<int> tmpRange({0, 0});
		while (right < totalElements.size()) {
			listOrder = totalElements[right].second;
			if (eachArrCounter[listOrder] == 0) {
				eachArrCounter[listOrder] = eachArrCounter[listOrder] + 1;
				count = count + 1;
			}
			else {
				eachArrCounter[listOrder] = eachArrCounter[listOrder] + 1;
			}

			if (count == len) {
				// calculate range
				tmpRange = std::vector({totalElements[left].first, totalElements[right].first});
				//std::cout << "count = " << count << ", ret = " << Vec2Str(ret) << ", tmpRange = " << Vec2Str(tmpRange) << std::endl; // debug
				ret = MinRange(tmpRange, ret);
			}

			while (count == len) {
				listOrder = totalElements[left].second;
				eachArrCounter[listOrder] = eachArrCounter[listOrder] - 1;
				if (eachArrCounter[listOrder] == 0) {
					count = count - 1;
				}

				left = left + 1;
				if (count == len) {
					// calculate range
					tmpRange = std::vector({totalElements[left].first, totalElements[right].first});
					//std::cout << "When shrink window: count = " << count << ", ret = " << Vec2Str(ret) << ", tmpRange = " << Vec2Str(tmpRange) << std::endl; // debug
					ret = MinRange(tmpRange, ret);
				}
			}
			right = right + 1;
		}
		return ret;
	}

	std::vector<int> MinRange(std::vector<int> &r1, std::vector<int> &r2)
	{
		std::vector<int> minRange;
		int a = r1[0], b = r1[1], c = r2[0], d = r2[1];
		if (b - a < d - c)
			minRange = r1;
		else if (b - a == d - c && a < c)
			minRange = r1;
		else
			minRange = r2;
		return minRange;
	}

	void PrintVector(std::vector<std::pair<int, size_t>> &vec)
	{
		std::cout << "[";
		for (auto &v : vec) {
			std::cout << "[" << v.first << "," << v.second << "] ";
		}
		std::cout << "]" << std::endl;
	}

	std::string Vec2Str(std::vector<int> &vec)
	{
		std::ostringstream ss;
		ss << "[";
		for (auto &v : vec) {
			ss << v << " ";
		}
		ss << "]";
		return ss.str();
	}
};

class TestSmallestRange
{
public:
	TestSmallestRange()
	{}

	~TestSmallestRange()
	{}

	void Example1()
	{
		std::vector<std::vector<int>> nums({{4,10,15,24,26},{0,9,12,20},{5,18,22,30}});
		std::vector<int> expected({20,24});
		std::cout << "===== Test input " << Vector2Str(nums) << ", output = " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<int> result = this->mSolution.smallestRange(nums);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example2()
	{
		std::vector<std::vector<int>> nums({{1,2,3},{1,2,3},{1,2,3}});
		std::vector<int> expected({1,1});
		std::cout << "===== Test input " << Vector2Str(nums) << ", output = " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<int> result = this->mSolution.smallestRange(nums);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example3()
	{
		std::vector<std::vector<int>> nums({{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}});
		std::vector<int> expected({5,11});
		std::cout << "===== Test input " << Vector2Str(nums) << ", output = " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<int> result = this->mSolution.smallestRange(nums);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestSmallestRange test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}