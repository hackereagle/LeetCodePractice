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
		std::vector<std::string> inputStep({"Solution", "shuffle", "reset", "shuffle"});
		PrintVector<std::string>(inputStep);
		std::vector<std::vector<std::string>> params({{"[1, 2, 3]"}, {}, {}, {}});
		std::vector<std::string> answer({"null", "[3, 1, 2]", "[1, 2, 3]", "[1, 3, 2]"});

		Solution* obj = nullptr;
		std::vector<std::string> result = this->ExecuteScript((void**)&obj, inputStep, params);
		PrintVector<std::string>(result);

		// TODO: need simillar checking feature
		//AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, answer));
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
			std::vector<int> input = ConvertStringToVector(k_str);
			*obj = (void*)(new Solution(input));
			ret = "null";
		}
		else if("reset" == method){
			std::vector<int> r = ((Solution*)*obj)->reset();
			ret = Vector2Str(r);
		}
		else if("shuffle" == method){
			std::vector<int> r = ((Solution*)*obj)->shuffle();
			ret = Vector2Str(r);
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