#pragma once

#include <iostream>
#include <string>
#include <vector>

class IWordBreak
{
public:
	virtual ~IWordBreak() {}
	virtual bool wordBreak(std::string s, std::vector<std::string>& wordDict) = 0;
};
