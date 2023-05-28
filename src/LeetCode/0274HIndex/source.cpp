#include <iostream>
#include <string>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	#define LEN (1001)
	int hIndex(std::vector<int>& citations) {
		int hIdx = 0;

		memset(_cdf, 0, sizeof(int) * LEN);
		StatisticCitationAndFindMaxMin(citations, this->_cdf);
		Accumulate2CdfArray(this->_cdf);
		hIdx = FindHindex(this->_cdf);

		return hIdx;
	}

private:
	int _cdf[LEN];

	void StatisticCitationAndFindMaxMin(std::vector<int> &citations, int* statisticRes)
	{
		int index = 0;
		size_t len = citations.size();
		for (int i = 0; i < len; i++) {
			index = citations[i];
			statisticRes[index] = statisticRes[index] + 1;
		}
	}

	void Accumulate2CdfArray(int* cdf)
	{
		for (int i = 999; i >= 0; i--) {
			cdf[i] = cdf[i] + cdf[i + 1];
		}
	}

	int FindHindex(int* cdf)
	{
		int hIndex = 0;
		for (int i = 0; i < LEN; i++) {
			if (cdf[i] >= i) {
				//std::cout << i << "-th cdf = " << cdf[i] << std::endl; //
				hIndex = std::max(hIndex, i);
			}
		}
		return hIndex;
	}
};

class TestHIndex
{
public:
	TestHIndex()
	{}

	~TestHIndex()
	{}

	void Example1()
	{
		std::vector citations({3,0,6,1,5});
		int expected = 3;
		std::cout << "===== Test citations = " << Vector2Str(citations) << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.hIndex(citations);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		std::vector citations({1,3,1});
		int expected = 1;
		std::cout << "===== Test citations = " << Vector2Str(citations) << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.hIndex(citations);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		std::vector citations({0,0,0});
		int expected = 0;
		std::cout << "===== Test citations = " << Vector2Str(citations) << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.hIndex(citations);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		std::vector citations({10,10,10});
		int expected = 3;
		std::cout << "===== Test citations = " << Vector2Str(citations) << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.hIndex(citations);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example5()
	{
		std::vector citations({1,6,1,6,1,6});
		int expected = 3;
		std::cout << "===== Test citations = " << Vector2Str(citations) << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.hIndex(citations);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example6()
	{
		std::vector citations({1,1});
		int expected = 1;
		std::cout << "===== Test citations = " << Vector2Str(citations) << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.hIndex(citations);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example7()
	{
		std::vector citations({11,15});
		int expected = 2;
		std::cout << "===== Test citations = " << Vector2Str(citations) << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.hIndex(citations);

		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestHIndex test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	getchar();
	return EXIT_SUCCESS;
}