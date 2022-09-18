#include <iostream>
#include <vector>
#include <queue>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if(!IsDecreasingOrder(nums1, m)){ 
            ReverseVector(nums1, m); 
        } 
        if(!IsDecreasingOrder(nums2, n)){  
            ReverseVector(nums2, n);  
        } 
        if(m > 0 && n > 0){ 
            std::queue<int> _nums1; 
            std::vector<int>::iterator it1 = nums1.begin(); 
            for(int i = 0; i < m; i++){ 
                _nums1.push(*(it1 + i)); 
            } 
     
            std::vector<int>::iterator it2 = nums2.begin(); 
            int len = m + n; 
            for(int i = 0, j = 0; i < len; i++){ 
                if(_nums1.empty()){ 
                    *(it1 + i) = *(it2 + j); 
                    j++; 
                } 
                else{ 
                    if(j < n && _nums1.front() > *(it2 + j)){ 
                        *(it1 + i) = *(it2 + j); 
                        j++; 
                    } 
                    else{ 
                        *(it1 + i) = _nums1.front(); 
                        _nums1.pop(); 
                    } 
                } 
            } 
        } 
        else if(m == 0){ 
            std::vector<int>::iterator it1 = nums1.begin();      
            std::vector<int>::iterator it2 = nums2.begin(); 
            int len = n;  
            for(int i = 0; i < len; i++){ 
                *(it1 + i) = *(it2 + i);   
            } 
        } 
         
    } 
private: 
    bool IsDecreasingOrder(std::vector<int> nums, int len) 
    { 
        bool ret = true; 
        if(len > 1){ 
            if(nums[1] == nums[0]){ 
                 for(int i = 0; i < len - 1; i++){
                    if(nums[i + 1] < nums[i]){
                        ret = false;
                        break;
                    }
                }
            } 
            else if(nums[1] > nums[0]){ 
                ret = true; 
            } 
            else{ 
                ret = false; 
            } 
        } 
        return ret; 
    } 
    void ReverseVector(std::vector<int> &vec, int len) 
    { 
        std::vector<int>::iterator it = vec.begin(); 
        int size = len >> 1; 
        bool isLenEven = !(len & 0x01); 
        for(int i = 0, j = len - 1; i < size; i++, j--){ 
            if(isLenEven){ 
                Swap(*(it + i), *(it + j)); 
            } 
            else{ 
                Swap(*(it + i), *(it + j)); 
            } 
        } 
    } 
    void Swap(int &r, int &l) 
    { 
        r = r ^ l; 
        l = r ^ l; 
        r = r ^ l; 
    } 
};

class TestMergeSortedArray
{
public:
	TestMergeSortedArray()
	{}

	~TestMergeSortedArray()
	{}

    void TestInput_1_2_3_And_2_5_6_Output_1_2_2_3_5_6()
    {
        std::cout << "===== Test input [1,2,3,0,0,0] and [2,5,6], output [1,2,2,3,5,6] =====" << std::endl;
        int arr[] = {1, 2, 3, 0, 0, 0};
        std::vector<int> input1 = ConvertArrayToVector(arr, sizeof(arr) / sizeof(int));
        int arr2[] = {2, 5, 6};
        std::vector<int> input2 = ConvertArrayToVector(arr2, sizeof(arr2) / sizeof(int));
        int arr3[] = {1, 2, 2, 3, 5, 6};
        std::vector<int> ans = ConvertArrayToVector(arr3, sizeof(arr3) / sizeof(int));

        this->mSolution.merge(input1, 3, input2, 3);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(input1, ans));
    }

    void TestInput_1_And_Empty_Output_1_()
    {
        std::cout << "===== Test input [1] and [], output [1] =====" << std::endl;
        int arr[] = {1};
        std::vector<int> input1 = ConvertArrayToVector(arr, sizeof(arr) / sizeof(int));
        int arr2[] = {};
        std::vector<int> input2 = ConvertArrayToVector(arr2, sizeof(arr2) / sizeof(int));
        int arr3[] = {1};
        std::vector<int> ans = ConvertArrayToVector(arr3, sizeof(arr3) / sizeof(int));

        this->mSolution.merge(input1, 1, input2, 0);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(input1, ans));
    }

    void TestInput_Empty_And_1_Output_1()
    {
        std::cout << "===== Test input [] and [1], output [1] =====" << std::endl;
        int arr[] = {0};
        std::vector<int> input1 = ConvertArrayToVector(arr, sizeof(arr) / sizeof(int));
        int arr2[] = {1};
        std::vector<int> input2 = ConvertArrayToVector(arr2, sizeof(arr2) / sizeof(int));
        int arr3[] = {1};
        std::vector<int> ans = ConvertArrayToVector(arr3, sizeof(arr3) / sizeof(int));

        this->mSolution.merge(input1, 0, input2, 1);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(input1, ans));
    }

    void TestInput_2_And_1_Output_1_2()
    {
        std::cout << "===== Test input [2] and [1], output [1,2] =====" << std::endl;
        int arr[] = {2, 0};
        std::vector<int> input1 = ConvertArrayToVector(arr, sizeof(arr) / sizeof(int));
        int arr2[] = {1};
        std::vector<int> input2 = ConvertArrayToVector(arr2, sizeof(arr2) / sizeof(int));
        int arr3[] = {1, 2};
        std::vector<int> ans = ConvertArrayToVector(arr3, sizeof(arr3) / sizeof(int));

        this->mSolution.merge(input1, 1, input2, 1);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(input1, ans));
    }

    void TestInput_0_0_3_And_n1_1_1_1_2_3_Output_n1_0_0_1_1_1_2_3_3()
    {
        std::cout << "===== Test input [0, 0, 3] and [-1, 1, 1, 1, 2, 3], output [-1, 0, 0, 1, 1, 1, 2, 3, 3] =====" << std::endl;
        int arr[] = {0, 0, 3, 0, 0, 0, 0, 0, 0};
        std::vector<int> input1 = ConvertArrayToVector(arr, sizeof(arr) / sizeof(int));
        int arr2[] = {-1, 1, 1, 1, 2, 3};
        std::vector<int> input2 = ConvertArrayToVector(arr2, sizeof(arr2) / sizeof(int));
        int arr3[] = {-1, 0, 0, 1, 1, 1, 2, 3, 3};
        std::vector<int> ans = ConvertArrayToVector(arr3, sizeof(arr3) / sizeof(int));

        this->mSolution.merge(input1, 3, input2, 6);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(input1, ans));
    }

private:
    Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMergeSortedArray test;
    test.TestInput_1_2_3_And_2_5_6_Output_1_2_2_3_5_6();
    test.TestInput_1_And_Empty_Output_1_();
    test.TestInput_Empty_And_1_Output_1();
    test.TestInput_2_And_1_Output_1_2();
    test.TestInput_0_0_3_And_n1_1_1_1_2_3_Output_n1_0_0_1_1_1_2_3_3();
    getchar();
	return EXIT_SUCCESS;
}