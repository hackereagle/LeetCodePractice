#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

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

    void Example1()
    {
        std::cout << "\nInput: recipes = [bread], ingredients = [[yeast,flour]], supplies = [yeast,flour,corn] ;Output: [bread]" <<std::endl;
        std::vector<std::string> recipes({"bread"});
        std::vector<std::vector<std::string>> ingredients({{"yeast","flour"}});
        std::vector<std::string> supplies({"yeast","flour","corn"});
        std::vector<std::string> ans({"bread"});

        std::vector<std::string> result = this->mSolution.findAllRecipes(recipes, ingredients, supplies);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, ans));
    }

    void Example2()
    {
        std::cout << "\nInput: recipes = [bread,sandwich], ingredients = [[yeast,flour],[bread,meat]], supplies = [yeast,flour,meat] ;Output: [bread,sandwich]" <<std::endl;
        std::vector<std::string> recipes({"bread","sandwich"});
        std::vector<std::vector<std::string>> ingredients({{"yeast","flour"},{"bread","meat"}});
        std::vector<std::string> supplies({"yeast","flour","meat"});
        std::vector<std::string> ans({"bread","sandwich"});

        std::vector<std::string> result = this->mSolution.findAllRecipes(recipes, ingredients, supplies);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, ans));
    }

    void Example3()
    {
        std::cout << "\nInput: recipes = [bread,sandwich,burger], ingredients = [[yeast,flour],[bread,meat],[sandwich,meat,bread]], supplies = [yeast,flour,meat] ;Output: [bread,sandwich]" <<std::endl;
        std::vector<std::string> recipes({"bread","sandwich","burger"});
        std::vector<std::vector<std::string>> ingredients({{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}});
        std::vector<std::string> supplies({"yeast","flour","meat"});
        std::vector<std::string> ans({"bread","sandwich","burger"});

        std::vector<std::string> result = this->mSolution.findAllRecipes(recipes, ingredients, supplies);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, ans));
    }

    void Example4()
    {
        std::cout << "\nInput: recipes = [ju,fzjnm,x,e,zpmcz,h,q], ingredients = [{d},{hveml,f,cpivl},{cpivl,zpmcz,h,e,fzjnm,ju},{cpivl,hveml,zpmcz,ju,h},{h,fzjnm,e,q,x},{d,hveml,cpivl,q,zpmcz,ju,e,x},{f,hveml,cpivl}], supplies = [f,hveml,cpivl,d] ;Output: [ju,fzjnm,x,e,zpmcz,h,q]" << std::endl;
        std::vector<std::string> recipes({"ju","fzjnm","x","e","zpmcz","h","q"});
        std::vector<std::vector<std::string>> ingredients({{"d"},{"hveml","f","cpivl"},{"cpivl","zpmcz","h","e","fzjnm","ju"},{"cpivl","hveml","zpmcz","ju","h"},{"h","fzjnm","e","q","x"},{"d","hveml","cpivl","q","zpmcz","ju","e","x"},{"f","hveml","cpivl"}});
        std::vector<std::string> supplies({"f","hveml","cpivl","d"});
        std::vector<std::string> ans({"ju","fzjnm","q"});


        std::vector<std::string> result = this->mSolution.findAllRecipes(recipes, ingredients, supplies);

        AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, ans));
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestFindAllRecipes test;
    test.Example1();
    test.Example2();
    test.Example3();
    test.Example4();
	getchar();
	return EXIT_SUCCESS;
}