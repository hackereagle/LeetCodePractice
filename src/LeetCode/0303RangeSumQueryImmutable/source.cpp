#include <iostream>
#include <string>
#include <vector>
#include "TestStepBase.hpp"
#include "VectorMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class NumArray
{
public:
	NumArray(std::vector<int>& nums) {
		_nums = nums;
		int len = nums.size();
		_integralArr = std::vector<int>(len, 0);
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				_integralArr[i] = nums[i];
			}
			else {
				_integralArr[i] = _integralArr[i - 1] + nums[i];
			}
		}
		//PrintVector(_integralArr);
	}
	
	int sumRange(int left, int right) {
		return _integralArr[right] - _integralArr[left] + _nums[left];
	}

private:
	std::vector<int> _nums;
	std::vector<int> _integralArr;

	void PrintVector(std::vector<int> &vec)
	{
		std::cout << "[";
		for (auto v : vec)
			std::cout << v << " ";
		std::cout << "]" << std::endl;
	}
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

class TestNumArray : public TestStepBase
{
public:
	TestNumArray()
	{}

	~TestNumArray()
	{}

	void Example1()
	{
		std::vector<std::string> inputStep({"NumArray", "sumRange", "sumRange", "sumRange"});
		PrintVector<std::string>(inputStep);
		std::vector<std::string> params({"[[-2, 0, 3, -5, 2, -1]]", "[0, 2]", "[2, 5]", "[0, 5]"});
		std::vector<std::string> answer({"null", "1", "-1", "-3"});

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
	std::string ConductMethod(void** obj, std::string method, std::vector<std::string> param) override
	{
		std::string ret = "null";
		if ("NumArray" == method)
		{
			std::string vecStr = param[0].substr(1, param[0].size() - 1);
			std::vector<int> nums = ConvertStringToVector(vecStr);
			*obj = new NumArray(nums);
		}
		else if ("sumRange" == method)
		{
			// int left = std::stoi(param[0]);
			// int right = std::stoi(param[1]);
			std::vector<int> input = ConvertStringToVector(param[0]);
			int left = input[0];
			int right = input[1];
			NumArray* numArray = (NumArray*)*obj;
			ret = std::to_string(numArray->sumRange(left, right));
		}
		return ret;
	}

};

int main(int argc, char** argv)
{
	TestNumArray test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}