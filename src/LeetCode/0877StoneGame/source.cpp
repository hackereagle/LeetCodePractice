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
	
	bool stoneGame(std::vector<int>& piles) {
		bool isAliceWin = true;

		size_t len = piles.size();
		this->mDp = std::vector<std::vector<pii>>(len, std::vector<pii>(len, pii(-1, -1)));
		int sum = 0;		
		for (int i = 0; i < len; i++) {
			this->mDp[i][i] = pii(piles[i], 0);
		}

		pii result = CalculateOptimalDecision(piles, 0, len - 1);
		//PrintTable(this->mDp); // debug

		if (result.second > result.first)
			isAliceWin = false;

		//std::cout << "Bob count = " << result.second << ", Alice count = " << result.first << std::endl; // debug
		return isAliceWin;
	}

private:
	typedef std::pair<int, int> pii;
	std::vector<std::vector<pii>> mDp;

	pii CalculateOptimalDecision(std::vector<int> &piles, int left, int right)
	{
		//std::cout << left << ", " << right << std::endl; // debug
		if (this->mDp[left][right].first != -1 && this->mDp[left][right].second != -1) return this->mDp[left][right];

		this->mDp[left][right].first = 
			std::max(piles[right] + CalculateOptimalDecision(piles, left, right - 1).second, 
					 piles[left] + CalculateOptimalDecision(piles, left + 1, right).second);  // Alex
		this->mDp[left][right].second = 
			std::min(CalculateOptimalDecision(piles, left, right - 1).first, 
					 CalculateOptimalDecision(piles, left + 1, right).first); // Bob

		return this->mDp[left][right];  
	}

	void PrintTable(std::vector<std::vector<pii>> &table)
	{
		for (auto &r : table) {
			std::cout << "[";
			for (auto &c : r) {
				std::cout << "(" << c.first << "," << c.second << ") ";
			}
			std::cout << "]" << std::endl;
		}
	}
};

#define CONVERT_BOOL_2_STR(x) ((x) ? "true" : "false")

class TestStoneGame
{
public:
	TestStoneGame()
	{}

	~TestStoneGame()
	{}

	void Example1()
	{
		std::vector<int> piles({5,3,4,5});
		bool isAliceWin = true;
		std::cout << "===== Input piles = \"" << Vector2Str(piles) << "\", is Alice win game = " << CONVERT_BOOL_2_STR(isAliceWin) << " =====" << std::endl;

		bool reslut = this->mSolution.stoneGame(piles);

		AssertClass::GetInstance().Assert(reslut == isAliceWin);
	}

	void Example2()
	{
		std::vector<int> piles({3,7,2,3});
		bool isAliceWin = true;
		std::cout << "===== Input piles = \"" << Vector2Str(piles) << "\", is Alice win game = " << CONVERT_BOOL_2_STR(isAliceWin) << " =====" << std::endl;

		bool reslut = this->mSolution.stoneGame(piles);

		AssertClass::GetInstance().Assert(reslut == isAliceWin);
	}

	void Example3()
	{
		std::vector<int> piles({1,4,10,2});
		bool isAliceWin = true;
		std::cout << "===== Input piles = \"" << Vector2Str(piles) << "\", is Alice win game = " << CONVERT_BOOL_2_STR(isAliceWin) << " =====" << std::endl;

		bool reslut = this->mSolution.stoneGame(piles);

		AssertClass::GetInstance().Assert(reslut == isAliceWin);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestStoneGame test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}