#include <iostream>
#include <vector>
#include <string.h>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "TestStepBase.hpp"

  class Iterator {
 	struct Data
    {
        int len = 0;
        int index = 0;
        int *vals = nullptr;

        Data() = default;

        Data(const Data& _d)
        {
            len = _d.len;
            index = 0;
            vals = new int[len];
            memset((void*)vals, 0, sizeof(int) * len);
            for(int i = 0; i < len; i++){
                *(vals + i) = *(_d.vals + i);
            }
        }

        void Release()
        {
            if(vals){
                delete [] vals;
                vals = nullptr;
                len = 0;
                index = 0;
            }
        }
    };

 	Data* data = nullptr;

  public:
 	Iterator(const std::vector<int>& nums)
    {
        data = new Data;
        data->len = nums.size();
        if(data->len > 0){
            data->vals = new int[data->len];
            memset((void*)data->vals, 0, sizeof(int) * data->len);
            std::vector<int>::const_iterator it = nums.begin();
            for(int i = 0; i < data->len; i++){
                *(data->vals + i) = *(it + i);
            }
        }
    }

    Iterator(const Iterator& iter)
    {
        data = iter.data;
        data = new Data(*iter.data);
    }

    ~Iterator()
    {
        if(data){
            data->Release();
            delete data;
        }
    }
 
    // Returns the next element in the iteration.
 	int next()
    {
        int ret = -1;
        if(data->index < data->len){
            ret = *(data->vals + data->index);
            data->index = data->index + 1;
        }
        return ret;
    }
 
 	// Returns true if the iteration has more elements.
 	bool hasNext() const
    {
        return data->index < data->len;
    }
 };

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    UpdatePointer();
	}
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return this->mNext;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int _next = this->mNext;
        UpdatePointer();
        return _next;
	}

	bool hasNext() const {
	    return !(this->mNext < 1);
	}

private:
    int mNext = 0;

    void UpdatePointer()
    {
        if(Iterator::hasNext()){
            this->mNext = Iterator::next();
        }
        else{
            this->mNext = 0;
        }
    }
};



class TestPeekingIterator : TestStepBase
{
public:
	TestPeekingIterator()
	{}

	~TestPeekingIterator()
	{}
	
	void Example1()
	{
        std::string steps[] = {"PeekingIterator", "next", "peek", "next", "next", "hasNext"};
		std::vector<std::string> inputStep = ConvertArrayToVector<std::string>(steps, sizeof(steps) / sizeof(std::string));
		PrintVector<std::string>(inputStep);
		std::vector<std::vector<std::string>> params;
		params.push_back({"[1, 2, 3]"});
		params.push_back({});
		params.push_back({});
		params.push_back({});
		params.push_back({});
		params.push_back({});
		std::string expected[] = {"null", "1", "2", "2", "3", "false"};
		std::vector<std::string> answer = ConvertArrayToVector<std::string>(expected, sizeof(expected) / sizeof(std::string));

        PeekingIterator* obj = nullptr;
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
        if("PeekingIterator" == method){
            std::vector<int> input = ConvertStringToVector(param[0]);
            std::cout << "input = ";
            PrintVector(input);
            *obj = (void*)(new PeekingIterator(input));
            ret = "null";
        }
        else if("peek" == method){
            int r = ((PeekingIterator*)*obj)->peek();
            ret = std::to_string(r);
        }
        else if("next" == method){
            int r = ((PeekingIterator*)*obj)->next();
            ret = std::to_string(r);
        }
        else if("hasNext" == method){
            bool r = ((PeekingIterator*)*obj)->hasNext();
            ret = r ? "true" : "false";
        }
        return ret;
    }


private:

};

int main(int argc, char** argv)
{
	TestPeekingIterator test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}