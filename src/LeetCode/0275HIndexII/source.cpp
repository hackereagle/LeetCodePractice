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
	
	int hIndex(std::vector<int>& citations) {
		int hIdx = 0;

        int len = citations.size();
        int start = 0, end = len - 1, avg = 0;
        while (start <= end) {
            avg = (start + end) / 2;
            if (citations[avg] < len - avg)
                start = avg + 1;
            else
                end = avg - 1;
        }
        hIdx = len - start;
        
        return hIdx;
	}

private:
};

class TestHIndexII
{
public:
	TestHIndexII()
	{}

	~TestHIndexII()
	{}

	void Example1()
	{
		std::vector citations({0,1,3,5,6});
		int expected = 3;
		std::cout << "===== Test citations = " << Vector2Str(citations) << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.hIndex(citations);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		std::vector citations({1,2,1000});
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
	TestHIndexII test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}