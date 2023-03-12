#include "Roman2IntegerSolution.hpp"
// problem in https://leetcode.com/problems/roman-to-integer/

Roman2IntegerSolution::Roman2IntegerSolution()
{
	InitializeRomanNumMapTable();
}

void Roman2IntegerSolution::InitializeRomanNumMapTable()
{
	this->mRomanNumMapTable['I'] = 1;
	this->mRomanNumMapTable['V'] = 5;
	this->mRomanNumMapTable['X'] = 10;
	this->mRomanNumMapTable['L'] = 50;
	this->mRomanNumMapTable['C'] = 100;
	this->mRomanNumMapTable['D'] = 500;
	this->mRomanNumMapTable['M'] = 1000;
}

int Roman2IntegerSolution::romanToInt(std::string s)
{
	int result = 0;

	size_t len = s.size();
	for(int i = 0; i < len; i++){
		int current = this->mRomanNumMapTable[s[i]];
		int next = 0;
		if(i + 1 < len){
			next = this->mRomanNumMapTable[s[i + 1]];
		}

		if(next > current){
			result = result + (next - current);
			i++;
		}
		else{
			result = result + current;
		}
	}

	return result;
}