#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "LeetcodeGraphMiscs.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}

    std::vector<std::string> findAllRecipes(std::vector<std::string>& recipes, std::vector<std::vector<std::string>>& ingredients, std::vector<std::string>& supplies) {
        std::vector<std::string> ret; 
        int len = recipes.size(); 
        for(int i = 0; i < len; i++){ 
            this->mRecipes.insert(std::pair<std::string, std::vector<std::string>>(recipes[i], ingredients[i])); 
        } 
        for(int i = 0; i < supplies.size(); i++){ 
            this->mCookable.insert(std::pair<std::string, bool>(supplies[i], true)); 
        } 
         
        for(auto r : recipes){ 
            if(this->CanCook(r)){ 
                ret.push_back(r); 
            } 
        } 
        return ret; 
    }

private: 
    std::unordered_map<std::string, bool> mVisisted; 
    std::unordered_map<std::string, std::vector<std::string>> mRecipes; 
    std::unordered_map<std::string, bool> mCookable;

    bool CanCook(std::string node) 
    { 
        if(this->mVisisted.find(node) != this->mVisisted.end()) 
            if(this->mVisisted[node]) 
                return this->mCookable[node]; 
        else 
            this->mVisisted.insert(std::pair<std::string, bool>(node, false));

        this->mVisisted[node] = true; 
        if(this->mCookable.find(node) != this->mCookable.end()){ 
            return this->mCookable[node]; 
        }

        if(this->mRecipes.find(node) != this->mRecipes.end()){ 
            bool cookable = true; 
            for(auto r : this->mRecipes[node]){ 
                cookable = cookable && CanCook(r);  
            } 
            this->mCookable.insert(std::pair<std::string, bool>(node, cookable)); 
        } 
        else{ 
            this->mCookable.insert(std::pair<std::string, bool>(node, false)); 
        } 
        return this->mCookable[node];
    }
};

class TestFindAllRecipes
{
public:
	TestFindAllRecipes()
	{}

	~TestFindAllRecipes()
	{}


private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestFindAllRecipes test;
	getchar();
	return EXIT_SUCCESS;
}