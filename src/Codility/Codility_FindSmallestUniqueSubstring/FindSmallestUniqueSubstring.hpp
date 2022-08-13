#pragma once

#include <string>
#include "IFindSmallestUniqueSubstring.hpp"

class FindSmallestUniqueSubstring : public IFindSmallestUniqueSubstring
{
public:
	FindSmallestUniqueSubstring();
	~FindSmallestUniqueSubstring();
	int Solution(std::string S, std::string& result);

private:
};

class FindSmallestUniqueSubstring_OptimalByEraseNotUnique : public IFindSmallestUniqueSubstring
{
public:
	FindSmallestUniqueSubstring_OptimalByEraseNotUnique();
	~FindSmallestUniqueSubstring_OptimalByEraseNotUnique();
	int Solution(std::string S, std::string& result) override;

private:
};