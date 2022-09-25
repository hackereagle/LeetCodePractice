#include <iostream>
#include <vector>
#include <algorithm>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> ret; 
        std::sort(intervals.begin(), intervals.end()); 
        int len = intervals.size(); 
        std::vector<std::vector<int>>::iterator it = intervals.begin(); 
        for(int i = 0, j = 0; i < len; i++){ 
            if(i == 0){ 
                ret.push_back(*(it + i)); 
            } 
            else{ 
                std::vector<std::vector<int>>::iterator retIt = ret.begin(); 
                if(IsOverlap(*(retIt + j), *(it + i))){ 
                    UpdateInterval(*(retIt + j), *(it + i)); 
                } 
                else{  
                    ret.push_back(*(it + i));  
                    j++; 
                } 
            } 
        } 
        return ret; 
    } 
private: 
    enum class Pos : int 
    { 
        MIN = 0, 
        MAX = 1, 
    }; 
    bool IsOverlap(std::vector<int> l, std::vector<int> r) 
    { 
        bool isOverlap = false; 
        if(l[(int)Pos::MAX] >= r[(int)Pos::MIN] && l[(int)Pos::MAX] <= r[(int)Pos::MAX]) 
            isOverlap = true; 
        else if(r[(int)Pos::MAX] >= l[(int)Pos::MIN] && r[(int)Pos::MAX] <= l[(int)Pos::MAX]) 
            isOverlap = true; 
        else 
            isOverlap = false; 
        return isOverlap; 
    } 
    void UpdateInterval(std::vector<int> &l, std::vector<int> &r) 
    { 
        if(l[(int)Pos::MIN] > r[(int)Pos::MIN]){  
            l[(int)Pos::MIN] = r[(int)Pos::MIN]; 
        } 
        if(l[(int)Pos::MAX] < r[(int)Pos::MAX]){  
            l[(int)Pos::MAX] = r[(int)Pos::MAX];  
        }  
    }
};

class TestMerge
{
public:
	TestMerge()
	{}

	~TestMerge()
	{}

	void TestInput_1_3_2_6_8_10_15_18_Output_1_6_8_10_15_18()
	{
		std::cout << "===== Test input [[1, 3], [2, 6], [8, 10], [15, 18]] output [[1, 6], [8, 10], [15, 18]] =====" << std::endl;
		std::vector<std::vector<int>> input;
		input.push_back({1, 3});
		input.push_back({2, 6});
		input.push_back({8, 10});
		input.push_back({15, 18});
		std::vector<std::vector<int>> ans;
		ans.push_back(std::vector({1, 6}));
		ans.push_back(std::vector({8, 10}));
		ans.push_back(std::vector({15, 18}));

		std::vector<std::vector<int>> reslut = this->mSolution.merge(input);

		//AssertClass::GetInstance().Assert();
		PrintVector(reslut);
	}

	void TestInput_1_4_4_5_Output_1_5()
	{
		std::cout << "===== Test input [[1, 4], [4, 5]] output [[1, 5]] =====" << std::endl;
		std::vector<std::vector<int>> input;
		input.push_back({1, 4});
		input.push_back({4, 5});
		std::vector<std::vector<int>> ans;
		ans.push_back(std::vector({1, 5}));

		std::vector<std::vector<int>> reslut = this->mSolution.merge(input);

		//AssertClass::GetInstance().Assert();
		PrintVector(reslut);
	}

	void TestInput_1_4_0_4_Output_0_4()
	{
		std::cout << "===== Test input [[1, 4], [0, 4]] output [[0, 4]] =====" << std::endl;
		std::vector<std::vector<int>> input;
		input.push_back({1, 4});
		input.push_back({0, 4});
		std::vector<std::vector<int>> ans;
		ans.push_back(std::vector({0, 4}));

		std::vector<std::vector<int>> reslut = this->mSolution.merge(input);

		//AssertClass::GetInstance().Assert();
		PrintVector(reslut);
	}

	void TestInput_1_4_0_5_Output_0_5()
	{
		std::cout << "===== Test input [[1, 4], [0, 5]] output [[0, 5]] =====" << std::endl;
		std::vector<std::vector<int>> input;
		input.push_back({1, 4});
		input.push_back({0, 5});
		std::vector<std::vector<int>> ans;
		ans.push_back(std::vector({0, 5}));

		std::vector<std::vector<int>> reslut = this->mSolution.merge(input);

		//AssertClass::GetInstance().Assert();
		PrintVector(reslut);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMerge test;
	test.TestInput_1_3_2_6_8_10_15_18_Output_1_6_8_10_15_18();
	test.TestInput_1_4_0_4_Output_0_4();
	test.TestInput_1_4_0_5_Output_0_5();
	test.TestInput_1_4_4_5_Output_1_5();
	getchar();
	return EXIT_SUCCESS;
}