#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}

    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) { 
        bool _canFinish = true; 
         
        // create table 
        std::map<int, std::vector<int>> _prerequisites; // key = class, value = prerequisite class 
        for (auto const& p : prerequisites){ 
            if (_prerequisites.find(p[0]) == _prerequisites.end()) { 
                std::vector req({p[1]}); 
                _prerequisites.insert(std::pair<int, std::vector<int>>(p[0], req)); 
            }  
            else { 
                _prerequisites[p[0]].push_back(p[1]); 
            } 
        }

        // iterator each  
        bool* visisted = new bool[numCourses]; 
        memset((void*)visisted, 0, sizeof(bool) * numCourses);  
        std::map<int, bool> canChoose; 
        for (int i = 0; i < numCourses; i++) {  
            if (!this->CanChooseClass(i, visisted, canChoose, _prerequisites)) { 
                _canFinish = false; 
                break; 
            } 
        } 
         
        delete [] visisted; 
     
        return _canFinish; 
    }

private: 
    bool CanChooseClass(int _class, bool *visisted, std::map<int, bool> &canChoose, std::map<int, std::vector<int>> &prereq) 
    { 
        if (visisted[_class]) { 
            return canChoose[_class]; 
        } 
        else { 
            visisted[_class] = true; 
            canChoose.insert(std::pair<int, bool>(_class, false)); 
        }

        if (prereq.find(_class) == prereq.end()) { 
            canChoose[_class] = true; 
            return canChoose[_class]; 
        } 
        else { 
            bool _canChoose = true; 
            for (const auto& pre : prereq[_class]){ 
                _canChoose = _canChoose && this->CanChooseClass(pre, visisted, canChoose, prereq); 
            } 
            canChoose[_class] = _canChoose; 
            return canChoose[_class]; 
        } 
    } 
};

class TestCanFinish
{
public:
	TestCanFinish()
	{}

	~TestCanFinish()
	{}

    void Example1()
    {
        std::cout << "\nInput: recipes = [bread], ingredients = [[yeast,flour]], supplies = [yeast,flour,corn] ;Output: [bread]" <<std::endl;
        int numCourses = 10;
        std::vector<std::vector<int>> prerequisites({{1, 0}});

        bool result = this->mSolution.canFinish(numCourses, prerequisites);

        AssertClass::GetInstance().Assert(result);
    }


private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestCanFinish test;
    test.Example1();
	getchar();
	return EXIT_SUCCESS;
}