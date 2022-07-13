#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class MedianOfTwoSortedArray
{
public:
	MedianOfTwoSortedArray()
	{}

	~MedianOfTwoSortedArray()
	{}

	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		double median = 0.0;

		std::vector<int> merge;
		merge.reserve(nums1.size() + nums2.size());

		return median;
	}

private:
};

class TestLMedianOfTwoSortedArray
{
public:
	TestLMedianOfTwoSortedArray()
	{}

	~TestLMedianOfTwoSortedArray()
	{}

	void TestInput_1_3_And_2_Output_2()
	{
		// mock data
		std::vector<int> input1;
		input1.push_back(1);
		input1.push_back(3);
		std::vector<int> input2;
		input1.push_back(2);

		double result = this->mSolution.findMedianSortedArrays(input1, input2);
		AssertClass::GetInstance().Assert(result == 2);
	}

	void TestInput_1_2_And_3_4_Output_2_5()
	{
		// mock data
		std::vector<int> input1;
		input1.push_back(1);
		input1.push_back(2);
		std::vector<int> input2;
		input1.push_back(3);
		input1.push_back(4);

		double result = this->mSolution.findMedianSortedArrays(input1, input2);
		AssertClass::GetInstance().Assert(result == 2.5);
	}


private:
	MedianOfTwoSortedArray mSolution;

};

int main(int argc, char** argv)
{
	TestLMedianOfTwoSortedArray test;
	test.TestInput_1_3_And_2_Output_2();
	test.TestInput_1_2_And_3_4_Output_2_5();
	getchar();
	return EXIT_SUCCESS;
}