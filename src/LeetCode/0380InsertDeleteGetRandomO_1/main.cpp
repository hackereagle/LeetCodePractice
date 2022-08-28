#include <iostream>
#include <unordered_map>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "TestStepBase.hpp"

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) { 
        bool isSuccess = false; 
        auto ele = this->mTable.find(val); 
        if(ele == this->mTable.end()){ 
            this->mTable[val] = val; 
            count = count + 1; 
            isSuccess = true; 
        } 
        else{ 
            isSuccess = false; 
        } 
        return isSuccess; 
    } 
     
    bool remove(int val) { 
        bool isSuccess = false; 
        auto ele = this->mTable.find(val); 
        if(ele != this->mTable.end()){ 
            this->mTable.erase(ele); 
            count = count - 1; 
            isSuccess = true; 
        } 
        else{ 
            isSuccess = false; 
        } 
        return isSuccess; 
    } 
     
    int getRandom() { 
        int ret = 0; 
        std::unordered_map<int, int>::iterator it = this->mTable.begin(); 
        if(count == 1){ 
            ret = it->second; 
        } 
        else if(count > 1){ 
            //srand(time(NULL)); 
            int index = rand() % count; 
            while(index){ 
                it++; 
                index = index - 1; 
            } 
            ret = it->second; 
        } 
        return ret; 
    } 
private: 
    std::unordered_map<int, int> mTable; 
    int count = 0;
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class TestRandomizedSet : TestStepBase
{
public:
	TestRandomizedSet()
	{}

	~TestRandomizedSet()
	{}

    void Example1()
    {
        std::cout << "========= Test input [1, 2, 3] =========" << std::endl;
		std::string steps[] = {"RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"};
		std::vector<std::string> inputStep = ConvertArrayToVector<std::string>(steps, sizeof(steps) / sizeof(std::string));
		PrintVector<std::string>(inputStep);
		std::vector<std::vector<std::string>> params;
		params.push_back({});
		params.push_back({"1"});
		params.push_back({"2"});
		params.push_back({""});
		params.push_back({});
		params.push_back({"1"});
		params.push_back({"2"});
		params.push_back({});
		std::string expected[] = {"null", "true", "false", "true", "2", "true", "false", "2"};
		std::vector<std::string> answer = ConvertArrayToVector<std::string>(expected, sizeof(expected) / sizeof(std::string));

		RandomizedSet* obj = nullptr;
		std::vector<std::string> result = this->ExecuteScript((void**)&obj, inputStep, params);
		PrintVector<std::string>(result);

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
		if("RandomizedSet" == method){
			*obj = (void*)(new RandomizedSet());
			ret = "null";
		}
		else if("insert" == method){
            int val = atoi(param[0].c_str());
			int r = ((RandomizedSet*)*obj)->insert(val);
			ret = r ? "true": "false";
		}
		else if("remove" == method){
            int val = atoi(param[0].c_str());
			int r = ((RandomizedSet*)*obj)->remove(val);
			ret = r ? "true": "false";
		}
		else if("getRandom" == method){
			int r = ((RandomizedSet*)*obj)->getRandom();
			ret = std::to_string(r);
		}

		return ret;
	}


private:

};

int main(int argc, char** argv)
{
    //std::vector<int> a, b;
    //a.push_back(1);
    //a.push_back(2);
    //b.push_back(1);
    //b.push_back(2);
    //std::unordered_map<std::vector<int>, int> m;
	TestRandomizedSet test;
    test.Example1();
	getchar();
	return EXIT_SUCCESS;
}