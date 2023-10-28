#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "TestStepBase.hpp"

class NumArray {
public:
	NumArray(std::vector<int>& nums) {
		_nums = nums;
		_len = _nums.size();
		for (int i = 0; i < _len; i++) {
			_sum = _sum + _nums[i];
		}
		
	}
	
	void update(int index, int val) {
		int diff = val - _nums[index];
		_sum = _sum + diff;
		_nums[index] = val;
	}
	
	int sumRange(int left, int right) {
		int ret = _sum;
		for (int i = 0; i < left; i++)
			ret = ret - _nums[i];
		for (int i = right + 1; i < _len; i++)
			ret = ret - _nums[i];
		
		return ret;
	}
private:
	std::vector<int> _nums;
	int _len = 0;
	int _sum = 0;
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class TestShuffleArray : TestStepBase
{
public:
	TestShuffleArray()
	{}

	~TestShuffleArray()
	{}
	
	void Example1()
	{
		std::vector<std::string> inputStep({"NumArray", "sumRange", "update", "sumRange"});
		PrintVector<std::string>(inputStep);
		std::vector<std::string> params({"[[1, 3, 5]]", "[0, 2]", "[1, 2]", "[0, 2]"});
		std::vector<std::string> answer({"null", "9", "null", "8"});

		NumArray* obj = nullptr;
		std::vector<std::string> result = this->ExecuteScript((void**)&obj, inputStep, params);
		PrintVector<std::string>(result);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, answer));
		if(obj)
		{
			delete obj;
			obj = nullptr;
		}
	}

protected:
	virtual std::string ConductMethod(void** obj, std::string method, std::vector<std::string> param) override
	{
		std::string ret;
		if("NumArray" == method){
			std::string str = param.at(0);
			std::string vecStr = str.substr(1, str.size() - 1);
			std::vector<int> input = ConvertStringToVector(vecStr);
			*obj = (void*)(new NumArray(input));
			ret = "null";
		}
		else if("sumRange" == method){
			std::string str = param.at(0);
			std::vector<int> input = ConvertStringToVector(str);
			int r = ((NumArray*)*obj)->sumRange(input[0], input[1]);
			ret = std::to_string(r);
		}
		else if("update" == method){
			std::string str = param.at(0);
			std::vector<int> input = ConvertStringToVector(str);
			((NumArray*)*obj)->update(input[0], input[1]);
			ret = "null";
		}

		return ret;
	}

private:

};

int main(int argc, char** argv)
{
	TestShuffleArray test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}