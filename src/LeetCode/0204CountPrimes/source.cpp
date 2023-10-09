#include <iostream>
#include <string>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int countPrimes(int n)
	{
		int count = 0;
		
		std::vector<bool> isPrime(n, true);
		for (int i = 2; i < n; i++) {
			if (isPrime[i]) {
				count = count + 1;
				FillTrueForAllNumTimes(i, isPrime);
			}
		}
		//PrintVector(isPrime);
		return count;
	}
private:
	void FillTrueForAllNumTimes(int num, std::vector<bool> &isPrime)
	{
		size_t len = isPrime.size();
		for (int i = num + num; i < len; i = i + num) {
			isPrime[i] = false;
		}
	}
	void PrintVector(std::vector<bool> &vec)
	{
		std::cout << "[";
		for (auto v : vec) 
			std::cout << v << " ";
		std::cout << "]" << std::endl;
	}
};

class TestCountPrimes
{
public:
	TestCountPrimes()
	{}

	~TestCountPrimes()
	{}

	void Example1()
	{
		// ARRANGE
		int n = 10;
		int expectedOutput = 4;
		std::cout << "===== Test n = " << n << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.countPrimes(n);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		int n = 0;
		int expectedOutput = 0;
		std::cout << "===== Test n = " << n << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.countPrimes(n);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		int n = 1;
		int expectedOutput = 0;
		std::cout << "===== Test n = " << n << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.countPrimes(n);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		int n = 2;
		int expectedOutput = 0;
		std::cout << "===== Test n = " << n << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.countPrimes(n);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		int n = 7;
		int expectedOutput = 3;
		std::cout << "===== Test n = " << n << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.countPrimes(n);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example6()
	{
		// ARRANGE
		int n = 5000000;
		int expectedOutput = 348513;
		std::cout << "===== Test n = " << n << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.countPrimes(n);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestCountPrimes test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	getchar();
	return EXIT_SUCCESS;
}