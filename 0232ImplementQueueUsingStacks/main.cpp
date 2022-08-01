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
	}

protected:
    virtual std::string ConductMethod(void** obj, std::string method, std::vector<std::string> param) override
    {
        std::string ret;
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