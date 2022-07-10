#include <iostream>
#include <vector>
#include "AssertClass.hpp"

class LongestConsecutiveSequence
{
public:
	LongestConsecutiveSequence()
	{}

	~LongestConsecutiveSequence()
	{}

	int Solution(std::vector<int> data)
	{
		int longestConsecutiveSeq = 0;
		RadixSort(data);

		int count = 1;
		size_t len = data.size();
		bool begin = false, end = false;
		for(int i = 0; i < len - 1; i++){
			if(data[i + 1] - data[i] == 1){
				count = count + 1;
			}
			else{
				if(count > longestConsecutiveSeq)
					longestConsecutiveSeq = count;
				break;
			}
		}

		return longestConsecutiveSeq + 1;
	}

private:
	const int RANGE = 19;

	void RadixSort(std::vector<int> &data)
	{
		int radix = 1;
		int smallerThanRadix = 0;
		while(smallerThanRadix != data.size()){
			smallerThanRadix = 0;
			std::vector<int> bucket[RANGE];
			for(int i = 0; i < data.size(); i++){
				int index = (data[i] / radix) % 10;
				bucket[index + 9].push_back(data[i]);

				if(bucket[i].size() < radix)
					smallerThanRadix++;
			}
			
			int idx = 0;
			for(int i = 0; i < RANGE; i++){
				if(bucket[i].size() > 0){
					for(auto const &e : bucket[i]){
						data[idx] = e;
						idx = idx + 1;
					}
					bucket[i].clear();
				}
			}

			radix = radix * 10;
		}
	}
};

class TestLongestConsecutiveSequence
{
public:
	TestLongestConsecutiveSequence()
	{}

	~TestLongestConsecutiveSequence()
	{}

	void TestInput_100_4_200_1_2_3_Output_4()
	{
		// mock data
		std::vector<int> input;
		input.push_back(100);
		input.push_back(4);
		input.push_back(200);
		input.push_back(1);
		input.push_back(2);
		input.push_back(3);

		int result = this->mSolution.Solution(input);
		AssertClass::GetInstance().Assert(result == 4);
	}

	void TestInput_0_3_7_2_5_8_4_6_0_1_Output_9()
	{
		std::vector<int> input;
		input.push_back(0);
		input.push_back(3);
		input.push_back(7);
		input.push_back(2);
		input.push_back(5);
		input.push_back(8);
		input.push_back(4);
		input.push_back(6);
		input.push_back(0);
		input.push_back(1);

		int result = this->mSolution.Solution(input);
		AssertClass::GetInstance().Assert(result == 9);
	}

	void TestInput_200_1_2_3_4_100_110_11_12_Output_4()
	{
		std::vector<int> input;
		input.push_back(200);
		input.push_back(1);
		input.push_back(2);
		input.push_back(3);
		input.push_back(4);
		input.push_back(100);
		input.push_back(110);
		input.push_back(11);
		input.push_back(12);

		int result = this->mSolution.Solution(input);
		AssertClass::GetInstance().Assert(result == 4);
	}

private:
	LongestConsecutiveSequence mSolution;

};

int main(int argc, char** argv)
{
	TestLongestConsecutiveSequence test;
	test.TestInput_100_4_200_1_2_3_Output_4();
	test.TestInput_0_3_7_2_5_8_4_6_0_1_Output_9();
	test.TestInput_200_1_2_3_4_100_110_11_12_Output_4();
	getchar();
	return EXIT_SUCCESS;
}