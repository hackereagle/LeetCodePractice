#include <iostream>
#include <vector>
#include <stack>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "TestStepBase.hpp"

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) { 
        while(!this->mMainData.empty()){ 
            this->mTemp.push(this->mMainData.top()); 
            this->mMainData.pop(); 
        } 
        this->mMainData.push(x); 
         
        while(!this->mTemp.empty()){ 
            this->mMainData.push(this->mTemp.top()); 
            this->mTemp.pop(); 
        } 
    } 
     
    int pop() { 
        int ret = -1; 
        if(!this->mMainData.empty()){ 
            ret = this->mMainData.top(); 
            this->mMainData.pop(); 
        }             
        return ret; 
    } 
     
    int peek() { 
        int ret = -1; 
        if(!this->mMainData.empty()) 
            ret = this->mMainData.top(); 
        return ret; 
    } 
     
    bool empty() { 
        return this->mMainData.empty(); 
    } 
private: 
    std::stack<int> mMainData; 
    std::stack<int> mTemp;
};



class TestMyQueue : TestStepBase
{
public:
	TestMyQueue()
	{}

	~TestMyQueue()
	{}
	
	void Example1()
	{
        std::string steps[] = {"MyQueue", "push", "push", "peek", "pop", "empty"};
		std::vector<std::string> inputStep = ConvertArrayToVector<std::string>(steps, sizeof(steps) / sizeof(std::string));
		PrintVector<std::string>(inputStep);
		std::vector<std::vector<std::string>> params;
		params.push_back({});
		params.push_back({"1"});
		params.push_back({"2"});
		params.push_back({});
		params.push_back({});
		params.push_back({});
		std::string expected[] = {"null", "null", "null", "1", "1", "false"};
		std::vector<std::string> answer = ConvertArrayToVector<std::string>(expected, sizeof(expected) / sizeof(std::string));

        MyQueue* obj = nullptr;
        std::vector<std::string> result = this->ExecuteScript((void**)&obj, inputStep, params);
        PrintVector<std::string>(result);
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, answer));
        if(obj){
            delete obj;
            obj = nullptr;
        }
	}

protected:
    virtual std::string ConductMethod(void** obj, std::string method, std::vector<std::string> param) override
    {
        std::string ret;
        if("MyQueue" == method){
            *obj = (void*)(new MyQueue());
            ret = "null";
        }
        else if("push" == method){
            int x = atoi(param[0].c_str());
            ((MyQueue*)*obj)->push(x);
            ret = "null";
        }
        else if("pop" == method){
            int r = ((MyQueue*)*obj)->pop();
            ret = std::to_string(r);
        }
        else if("peek" == method){
            int r = ((MyQueue*)*obj)->peek();
            ret = std::to_string(r);
        }
        else if("empty" == method){
            bool r = ((MyQueue*)*obj)->empty();
            ret = r ? "true" : "false";
        }
        return ret;
    }


private:

};

int main(int argc, char** argv)
{
	TestMyQueue test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}