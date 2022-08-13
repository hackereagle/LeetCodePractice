#pragma once

#include <string>

// In order to test other method, defined interface
class IFindSmallestUniqueSubstring
{
public:
	~IFindSmallestUniqueSubstring() {}
	virtual int Solution(std::string S, std::string& result) = 0;
};