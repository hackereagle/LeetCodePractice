#include <iostream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<int> diffWaysToCompute(std::string expression) {
        if (_dp.find(expression) != _dp.end()) 
            return _dp[expression];

        std::vector<int> res;
        size_t len = expression.size();
        bool isExpressionNumeric = true;
        for (int i = 0; i < len; i++) {
            if (!IsDigit(expression[i])) {
                isExpressionNumeric = false;
                std::vector<int> left = diffWaysToCompute(expression.substr(0, i));
                std::vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                CalculatePossibleResult(left, right, expression[i], res);
            }
        }

        if (isExpressionNumeric) 
            res.push_back(std::stoi(expression));
        
        _dp.insert(std::pair<std::string, std::vector<int>>(expression, res));
        
        return res;
    }
private:
    std::unordered_map<std::string, std::vector<int>> _dp;
    bool IsDigit(char c)
    {
        return c >= '0' && c <= '9';
    }

    void CalculatePossibleResult(const std::vector<int> &left, const std::vector<int> &right, char opt, std::vector<int> &res)
    {
        int tmp = 0;
        for (auto &l : left) {
            for (auto &r : right) {
                tmp = Compute(l, opt, r);
                res.push_back(tmp);
            }
        }
    }

    int Compute(int num1, char opt, int num2)
    {
        int res = 0;
        if ('+' == opt)
            res = num1 + num2;
        else if ('-' == opt) {
            res = num1 - num2;
        } 
        else if ('*' == opt) {
            res = num1 * num2;
        }

        return res;
    }
};

class TestDiffWaysToCompute
{
public:
	TestDiffWaysToCompute()
	{}

	~TestDiffWaysToCompute()
	{}

	void Example1()
	{
		// ARRANGE
		std::string expression = "2-1-1";
		std::vector<int> expectedOutput({0, 2});
		std::cout << "===== Test expression = " << expression << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<int> result = this->mSolution.diffWaysToCompute(expression);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, expectedOutput));
	}

	void Example2()
	{
		// ARRANGE
		std::string expression = "2*3-4*5";
		std::vector<int> expectedOutput({-34, -14, -10, -10, 10});
		std::cout << "===== Test expression = " << expression << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<int> result = this->mSolution.diffWaysToCompute(expression);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, expectedOutput));
	}

	void Example3()
	{
		// ARRANGE
		std::string expression = "0+10+3*5";
		std::vector<int> expectedOutput({65,25,65,65,25});
		std::cout << "===== Test expression = " << expression << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<int> result = this->mSolution.diffWaysToCompute(expression);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, expectedOutput));
	}

	void Example4()
	{
		// ARRANGE
		std::string expression = "1-1-1";
		std::vector<int> expectedOutput({-1,1});
		std::cout << "===== Test expression = " << expression << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<int> result = this->mSolution.diffWaysToCompute(expression);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, expectedOutput));
	}

	void Example5()
	{
		// ARRANGE
		std::string expression = "10*99-89-88*97+98-99";
		std::vector<int> expectedOutput({78860,78860,158436,78048,78048,-7636,-7636,-7832,-7634,-7634,-16358,-16160,-7547,-7547,95932,95932,192756,94944,94944,892,892,696,894,894,696,894,894,894,9436,9436,9240,9438,9438,9436,9634,9436,9436,17962,18160,17962,9349,9349,1163,1163,2241,1152,1152,-8437,-8437,-8633,-8435,-8435,-17159,-16961,-8348,-8348,-75661,-75661,-152199,-74880,-74880,-75661,-75661,-74779,-75670,-75670,-152199,-153090,-74880,-74880,-85261,-85261,-84379,-85270,-85270,-86339,-87230,-85250,-85250,-171599,-172490,-170510,-84380,-84380,95059,95059,191001,94080,94080,95059,95059,95941,95050,95050,191001,190110,94080,94080,19,19,901,10,10,-1059,-1950,30,30,-1059,-1950,30,30,30,85459,85459,86341,85450,85450,84381,83490,85470,85470,86341,85450,87430,85450,85450,171601,170710,172690,170710,84580,84580});
		std::cout << "===== Test expression = " << expression << "; output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		std::vector<int> result = this->mSolution.diffWaysToCompute(expression);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorSimilar(result, expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestDiffWaysToCompute test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}