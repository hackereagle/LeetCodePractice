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

		std::vector<int> sortedArr = this->MergeTwoSortedArray(nums1, nums2);
		PrintVector<int>(sortedArr); // debug

		int totalLen = sortedArr.size();
		if(totalLen > 0){
			std::vector<int>::iterator it = sortedArr.begin();
			int index = 0;
			if(totalLen & 1 > 0){
				index = totalLen >> 1;
				std::cout << index << std::endl;
				median = static_cast<double>(*(it + index));
			}
			else{
				index = totalLen >> 1; 
				std::cout << index << std::endl;
				median = (static_cast<double>(*(it + index - 1)) + static_cast<double>(*(it + index))) / 2.0;
			}
		}

		return median;
	}

private:
	std::vector<int> MergeTwoSortedArray(std::vector<int> &nums1, std::vector<int> &nums2)
	{
		std::vector<int> sortedArr;
        int len1 = nums1.size(), len2 = nums2.size();
		std::cout << "len1 = " << len1 << ", len2 = " << len2 << std::endl;
		if(len1 > 0 & len2 > 0){
			sortedArr.resize(len1 + len2);
			std::vector<int>::iterator b1 = nums1.begin(), b2 = nums2.begin(), e1 = nums1.end(), e2 = nums2.end();
			for(std::vector<int>::iterator  it = sortedArr.begin(), ite = sortedArr.end(); it != ite; it++){
				if(b1 < e1 & b2 < e2){
					if(*b1 < *b2){
						*it = *b1;
						b1++;
					}
					else{
						*it = *b2;
						b2++;
					}
				}
				else if(b1 < e1){
					*it = *b1;
					b1++;
				}
				else if(b2 < e2){ 
					*it = *b2;
					b2++;
				}
				else{
					std::cout << "Unexpected ERROR" << std::endl;
				}
			}
		}
		else if(len1 > 0){
			sortedArr.resize(len1);
			for(std::vector<int>::iterator  it = sortedArr.begin(), ite = sortedArr.end(), b1 = nums1.begin(); it != ite; it++, b1++){
				*it = *b1;
			}
		}
		else if(len2 > 0){
			sortedArr.resize(len2);
			for(std::vector<int>::iterator  it = sortedArr.begin(), ite = sortedArr.end(), b2 = nums2.begin(); it != ite; it++, b2++){
				*it = *b2;
			}
		}

		return sortedArr;
	}
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
		input2.push_back(2);

		double result = this->mSolution.findMedianSortedArrays(input1, input2);
		AssertClass::GetInstance().Assert(result == 2.0, "result = %lf", result);
	}

	void TestInput_1_2_And_3_4_Output_2_5()
	{
		// mock data
		std::vector<int> input1;
		input1.push_back(1);
		input1.push_back(2);
		std::vector<int> input2;
		input2.push_back(3);
		input2.push_back(4);

		double result = this->mSolution.findMedianSortedArrays(input1, input2);
		AssertClass::GetInstance().Assert(result == 2.5, "result = %lf", result);
	}

	void TestInput_Empty_And_1_Output_1()
	{
		// mock data
		std::vector<int> input1;
		std::vector<int> input2;
		input2.push_back(1);

		double result = this->mSolution.findMedianSortedArrays(input1, input2);
		AssertClass::GetInstance().Assert(result == 1.0, "result = %lf", result);
	}

	void TestInput_Empty_And_1_2_3_4_5_Output_3()
	{
		// mock data
		std::vector<int> input1;
		std::vector<int> input2;
		input2.push_back(1);
		input2.push_back(2);
		input2.push_back(3);
		input2.push_back(4);
		input2.push_back(5);

		double result = this->mSolution.findMedianSortedArrays(input1, input2);
		AssertClass::GetInstance().Assert(result == 3.0, "result = %lf", result);
	}


private:
	MedianOfTwoSortedArray mSolution;

};

int main(int argc, char** argv)
{
	TestLMedianOfTwoSortedArray test;
	test.TestInput_1_3_And_2_Output_2();
	test.TestInput_1_2_And_3_4_Output_2_5();
	test.TestInput_Empty_And_1_Output_1();
	test.TestInput_Empty_And_1_2_3_4_5_Output_3();
	getchar();
	return EXIT_SUCCESS;
}