#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "TestStepBase.hpp"

class MyCircularQueue 
{ 
public: 
    MyCircularQueue(int k) { 
        this->LIMIT = k; 
    } 
     
    bool enQueue(int value) { 
        bool ret = false; 
        if(this->mCount < this->LIMIT){ 
            if(this->isEmpty()) 
                *(this->mData + this->mTail) = value; 
            else{ 
                this->mTail++; 
                if(this->mTail == this->LIMIT) 
                    this->mTail = 0; 
                *(this->mData + this->mTail) = value; 
            } 
            this->mCount++; 
            ret = true; 
        } 
        return ret; 
    } 
     
    bool deQueue() { 
        bool isSuccess = false; 
        if(this->mCount > 0){ 
            this->mCount--; 
             
            this->mFront++; 
            if(this->mFront == this->LIMIT) 
                this->mFront = 0; 
            if(this->mCount == 0){ 
                this->mFront = this->mTail; 
            } 
             
            isSuccess = true; 
            std::cout << "delta = " << this->mTail - this->mFront << ", count = " << this->mCount << std::endl; 
        } 
        return isSuccess; 
    } 
     
    int Front() { 
        int value = -1; 
        if(this->mCount > 0){ 
            value = *(this->mData + this->mFront); 
        } 
        return value; 
    } 
     
    int Rear() { 
        int value = -1; 
        if(this->mCount > 0){ 
            value = *(this->mData + this->mTail); 
        } 
        return value; 
    } 
     
    bool isEmpty() { 
        return mCount == 0; 
    } 
     
    bool isFull() { 
        return this->mCount == this->LIMIT; 
    } 
private: 
    int mData[1000]; 
    int LIMIT = 0; 
    int mFront = 0; 
    int mTail = 0; 
    int mCount = 0; 
}; 

class TestMyCircularQueue : TestStepBase
{
public:
	TestMyCircularQueue()
	{}

	~TestMyCircularQueue()
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

		MyCircularQueue* obj = nullptr;
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
		if("MyCircularQueue" == method){
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