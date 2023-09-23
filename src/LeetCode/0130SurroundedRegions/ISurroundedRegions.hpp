#pragma once

#include <iostream>
#include <vector>

class ISurroundedRegions
{
public:
	ISurroundedRegions() = default;
	virtual ~ISurroundedRegions() {}
	virtual void solve(std::vector<std::vector<char>> &board) = 0;

private:
	ISurroundedRegions(const ISurroundedRegions&) = delete;
	ISurroundedRegions(const ISurroundedRegions&&) = delete;
};