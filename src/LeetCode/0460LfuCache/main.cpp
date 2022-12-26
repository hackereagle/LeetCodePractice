#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "TestStepBase.hpp"

class LFUCache {
public:
    LFUCache(int capacity) {
        this->mCapacity = capacity;
    }
    
    int get(int key) {
        //std::cout << "get key = " << key << std::endl; // debug
        int ret = -1;
        if (this->mTable.find(key) != this->mTable.end()) {
            //std::cout << "\tfind key = " << key << std::endl; // debug
            int freq = this->mTable[key].second;
            ret = this->mTable[key].first;
            this->mFreqTable[freq].erase(std::find(this->mFreqTable[freq].begin(), this->mFreqTable[freq].end(), key)); // erase value in original freq
            freq++;
            this->mTable[key].second = freq;
            this->mFreqTable[freq].push_front(key);
            this->mIter[freq] = this->mFreqTable[freq].begin();

            if (this->mFreqTable[this->mMinFreq].size() == 0) {
                this->mMinFreq = this->mMinFreq + 1;
            }
        }
        //this->PrintTable(this->mTable, true); // debug
        return ret;
    }
    
    void put(int key, int value) {
        //std::cout << "put key = " << key << " with value = " << value << std::endl; // debug
        if (this->mTable.find(key) != this->mTable.end()) {
            int oldVal = this->get(key);
            int freq = this->mTable[key].second;
            this->mTable[key].first = value;
        }
        else {
            if (this->mSize < this->mCapacity) {
                this->mMinFreq = 1;
                this->mTable.insert(std::pair<int, std::pair<int, int>>(key, std::pair<int, int>(value, this->mMinFreq)));
                this->mFreqTable[this->mMinFreq].push_front(key);
                this->mIter[this->mMinFreq] = this->mFreqTable[this->mMinFreq].begin();
                this->mSize = this->mSize + 1;
            }
            else if (this->mCapacity > 0 && this->mSize == this->mCapacity) {
                auto lastEle = this->mFreqTable[this->mMinFreq].end();
                lastEle--;
                int lastKey = *lastEle;
                this->mFreqTable[this->mMinFreq].erase(lastEle);
                this->mIter[this->mMinFreq] = this->mFreqTable[this->mMinFreq].begin();
                this->mTable.erase(lastKey);

                this->mMinFreq = 1;
                this->mTable.insert(std::pair<int, std::pair<int, int>>(key, std::pair<int, int>(value, this->mMinFreq)));
                this->mFreqTable[this->mMinFreq].push_front(key);
                this->mIter[this->mMinFreq] = this->mFreqTable[this->mMinFreq].begin();
            }
        }
        //this->PrintFreqTable(this->mFreqTable, true); // debug
    }

private:
    int mSize = 0;
    int mCapacity = 0;
    int mMinFreq = 0;
    std::unordered_map<int, std::pair<int, int>> mTable; // key -> {value, freq}
    std::unordered_map<int, std::list<int>> mFreqTable; // freq -> list {key}
    std::unordered_map<int, std::list<int>::iterator> mIter; // freq -> list iterator {key}

    void PrintFreqTable(std::unordered_map<int, std::list<int>> ft, bool typesetting = false)
    {
        std::unordered_map<int, std::list<int>>::iterator it = ft.begin();
        for (; it != ft.end(); it++) {
            if (typesetting)
                std::cout << "\t";
            std::cout << "freq = " << it->first << " => [";
            for (auto p = it->second.begin(); p != it->second.end(); p++) {
                if (p == it->second.begin())
                    std::cout << *p;
                else
                    std::cout << ", " << *p;
            }
            std::cout << "]" << std::endl;
        }
    }

    void PrintTable(std::unordered_map<int, std::pair<int, int>> tb, bool typesetting = false)
    {
        std::unordered_map<int, std::pair<int, int>>::iterator it = tb.begin();
        for (; it != tb.end(); it++) {
            if (typesetting)
                std::cout << "\t";
            std::cout << "key = " << it->first << " => {" << it->second.first << ", " << it->second.second << "}" << std::endl;
        }
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class TestLfuCache : TestStepBase
{
public:
	TestLfuCache()
	{}

	~TestLfuCache()
	{}
	
	void Example1()
	{
		std::string steps[] = {"MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"};
		std::vector<std::string> inputStep;
		std::vector<std::vector<std::string>> params;
		std::vector<std::string> answer;

		LFUCache* obj = nullptr;
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
		if("LFUCache" == method){
			std::string cap_str = param.at(0);
			int cap = atoi(cap_str.c_str());
			*obj = (void*)(new LFUCache(cap));
			ret = "null";
		}
		else if("get" == method){
			int key = std::stoi(param.at(0));
			int r = ((LFUCache*)*obj)->get(key);
			ret = std::to_string(r);
		}
		else if("put" == method){
			int key = std::stoi(param.at(0));
			int val = std::stoi(param.at(1));
			((LFUCache*)*obj)->put(key, val);
			ret = "null";
		}

		return ret;
	}

private:

};

int main(int argc, char** argv)
{
	TestLfuCache test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}