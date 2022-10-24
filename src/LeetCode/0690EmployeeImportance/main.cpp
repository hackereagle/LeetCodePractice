#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    std::vector<int> subordinates;

    Employee(int _id, int _imp, std::vector<int> _subord)
    {
        this->id = _id;
        this->importance = _imp;
        subordinates = std::vector<int>(_subord);
    }

    // Employee(int _id, int _imp, int _subord[])
    // {
    //     this->id = _id;
    //     this->importance = _imp;
    //     subordinates = std::vector<int>(_subord);
    // }
};

class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
    }

    int getImportance(std::vector<Employee*> employees, int id) {
        int importance = 0;

        // convert vector<Employee*> to unordered_map, and key of unordered_map is employee's ID and value is employee's data
        for(auto e : employees){
            mEmployeesTable.insert(std::pair<int, Employee*>(e->id, e));
        }

        // calculate
        importance = CalculateImportance(id);

        return importance;
    }
    
private:
    std::unordered_map<int, Employee*> mEmployeesTable;
    
    int CalculateImportance(int id)
    {
        int sum = 0;
        
        // query employee via id
        Employee* target = mEmployeesTable[id];

        // calculate selected employee's all subordinate's importances and employee's importance sum.
        sum = target->importance;
        int len = target->subordinates.size();
        for(int i = 0; i < len; i++){
            sum = sum + CalculateImportance(target->subordinates[i]);
        }
        
        return sum;
    }
};

class TestGetImportance
{
public:
	TestGetImportance()
	{}

	~TestGetImportance()
	{}

    void Example1()
    {
        std::cout << "Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1; Output: 11" << std::endl;
        std::vector<Employee*> employees;
        employees.push_back(new Employee(1,5,{2,3}));
        employees.push_back(new Employee(2,3,{}));
        employees.push_back(new Employee(3,3,{}));
        int id = 1;

        int result = this->mSolution.getImportance(employees, id);
        AssertClass::GetInstance().Assert(result == 11);
        ReleaseEmployee(employees);
    }

    void Example2()
    {
        std::cout << "Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5; Output: -3" << std::endl;
        std::vector<Employee*> employees;
        employees.push_back(new Employee(1,2,{5}));
        employees.push_back(new Employee(5,-3,{}));
        int id = 5;

        int result = this->mSolution.getImportance(employees, id);
        AssertClass::GetInstance().Assert(result == -3);
        ReleaseEmployee(employees);
    }


private:
	Solution mSolution;

    void ReleaseEmployee(std::vector<Employee*> &emps)
    {
        for(auto e : emps){
            if(e){
                delete e;
                e = nullptr;
            }
        }
    }
};

int main(int argc, char** argv)
{
	TestGetImportance test;
    test.Example1();
    test.Example2();
	getchar();
	return EXIT_SUCCESS;
}