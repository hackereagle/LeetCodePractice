#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "TestStepBase.hpp"

class Solution {
public:
    Solution(std::vector<int>& nums) {
        this->mOrgData = nums;
        this->mRetData = nums;
        this->mLen = this->mOrgData.size();
        srand(time(NULL));
    }
    
    std::vector<int> reset() {
        this->mRetData = this->mOrgData;
        return this->mRetData;
    }
    
    std::vector<int> shuffle() {
        if(this->mLen > 1){
            //this->mRetData = this->mOrgData;
            size_t size = this->mLen;
            for(int i = this->mLen - 1; i >= 0; i--){
                int j = rand() % size;
                std::swap(this->mRetData[i], this->mRetData[j]);
                //this->Swap(this->mRetData[i], this->mRetData[j]); // cannot using this method, because rand() maybe calculate same index!!!!
                size--;
            }
        }
        
        //this->PrintVector(this->mRetData);  
        return this->mRetData;
    }

private:
    std::vector<int> mOrgData;
    std::vector<int> mRetData;
    size_t mLen;

    void PrintVector(std::vector<int> &vec)
    {
        std::cout << "[";
        for(auto v : vec){
            std::cout << v << " ";
        }
        std::cout << "]" << std::endl;;
    }

    // cannot using this method, because rand() maybe calculate same index!!!!
    void Swap(int &l, int &r)
    {
        l = l ^ r;
        r = l ^ r;
        l = l ^ r;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
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
		std::string steps[] = {"MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"};
		std::vector<std::string> inputStep = ConvertArrayToVector<std::string>(steps, sizeof(steps) / sizeof(std::string));
		PrintVector<std::string>(inputStep);
		std::vector<std::vector<std::string>> params;
		params.push_back({"3"});
		params.push_back({"1"});
		params.push_back({"2"});
		params.push_back({"3"});
		params.push_back({"4"});
		params.push_back({});
		params.push_back({});
		params.push_back({});
		params.push_back({"4"});
		params.push_back({});
		std::string expected[] = {"null", "true", "true", "true", "false", "3", "true", "true", "true", "4"};
		std::vector<std::string> answer = ConvertArrayToVector<std::string>(expected, sizeof(expected) / sizeof(std::string));

		Solution* obj = nullptr;
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
		if("Solution" == method){
			std::string k_str = param.at(0);
			int k = atoi(k_str.c_str());
			*obj = (void*)(new MyCircularQueue(k));
			ret = "null";
		}
		else if("Front" == method){
			int r = ((MyCircularQueue*)*obj)->Front();
			ret = std::to_string(r);
		}
		else if("Rear" == method){
			int r = ((MyCircularQueue*)*obj)->Rear();
			ret = std::to_string(r);
		}
		else if("enQueue" == method){
			int value = atoi(param[0].c_str());
			bool r = ((MyCircularQueue*)*obj)->enQueue(value);
			ret = r ? "true" : "false";
		}
		else if("deQueue" == method){
			bool r = ((MyCircularQueue*)*obj)->deQueue();
			ret = r ? "true" : "false";
		}
		else if("isEmpty" == method){
			bool r = ((MyCircularQueue*)*obj)->isEmpty();
			ret = r ? "true" : "false";
		}
		else if("isFull" == method){
			bool r = ((MyCircularQueue*)*obj)->isFull();
			ret = r ? "true" : "false";
		}

		return ret;
	}

private:

};

int main(int argc, char** argv)
{
	TestMyCircularQueue test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}