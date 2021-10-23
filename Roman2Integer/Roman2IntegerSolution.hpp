#ifndef _ROMAN_TO_INTEGER_SOLUTION_H_
#define _ROMAN_TO_INTEGER_SOLUTION_H_

#include <string>
#include <map>

class Roman2IntegerSolution
{
public:
	Roman2IntegerSolution();
    int romanToInt(std::string s);

private:
	std::map<char, int> mRomanNumMapTable;

	void InitializeRomanNumMapTable();
};
#endif //_ROMAN_TO_INTEGER_SOLUTION_H_