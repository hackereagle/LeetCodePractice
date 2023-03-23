#include <iostream>
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
	
	int maximumGap(std::vector<int>& nums) {
		if (nums.size() < 2) 
			return 0;
		else if (nums.size() == 2) 
			return nums[1] - nums[0];

		int ret = 0;
		
		RadixSort(nums);
		//PrintVector(nums); // debug

		size_t len = nums.size();
		for (int i = 0; i < len - 1; i++) {
			int diff = nums[i + 1] - nums[i];
			//std::cout << i << ", diff = " << diff << std::endl;
		
			if (diff > ret) {
				ret = diff;
			}
		}
		return ret;
	}

private:
	const int ZERO_INDEX = 9;

	void RadixSort(std::vector<int> &nums)
	{
		size_t len = nums.size();

		std::vector<int> bucket[19];
		long int radix = 1;
		int smallerThanRadix = 0;
		while (smallerThanRadix != len) {
			smallerThanRadix = 0;
			for (auto n : nums) {
				int idx = (static_cast<int>(static_cast<long int>(n) / radix) % 10) + ZERO_INDEX;
				bucket[idx].push_back(n);

				if (n < radix)
					smallerThanRadix++;
			}

			int index = 0;
			for (int i = 0; i < 19; i++) {
				for (auto b : bucket[i]) {
					nums[index] = b;
					index = index + 1;
				}
				bucket[i].clear();
			}
			radix = radix * static_cast<long int>(10);
		}
	}

	void PrintVector(std::vector<int> &nums) {
		std::cout << "[";
		for (auto n : nums) 
			std::cout << " " << n;
		std::cout << "]" << std::endl;
	}
};

class TestMaximumGap
{
public:
	TestMaximumGap()
	{}

	~TestMaximumGap()
	{}

	void Example1()
	{
		std::vector<int> input({3,6,9,1});
		int expected = 3;
		std::cout << "===== Test input " << Vector2Str(input) << ", output " << expected << " =====" << std::endl;

		int result = this->mSolution.maximumGap(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		std::vector<int> input({10});
		int expected = 0;
		std::cout << "===== Test input " << Vector2Str(input) << ", output " << expected << " =====" << std::endl;

		int result = this->mSolution.maximumGap(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		std::vector<int> input({1,10000000});
		int expected = 9999999;
		std::cout << "===== Test input " << Vector2Str(input) << ", output " << expected << " =====" << std::endl;

		int result = this->mSolution.maximumGap(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		std::vector<int> input({1,3,100});
		int expected = 97;
		std::cout << "===== Test input " << Vector2Str(input) << ", output " << expected << " =====" << std::endl;

		int result = this->mSolution.maximumGap(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example5()
	{
		std::vector<int> input({494767408,862126209,213511142,768240025,631263193,839199222,990848796,214568815,540853864,760724418,980162605,976743981,168965760,680875496,256709197,970953816,948680062,347254784,732201399,786249847,782805044,40906641,674241381,784330934,175502610,731105392,424650824,549764101,986090032,710542549,249208107,448419816,527708664,158499246,223421723,114552457,466978424,821491411,19614107,115389497,902211438,2644108,744489871,897895073,372311214,551142753,933294894,426217662,217504874,983488406,516890023,426853110,971124103});
		int expected = 90545587;
		std::cout << "===== Test input " << Vector2Str(input) << ", output " << expected << " =====" << std::endl;

		int result = this->mSolution.maximumGap(input);

		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMaximumGap test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}