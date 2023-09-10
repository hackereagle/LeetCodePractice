#pragma once

#include <iostream>
#include <vector>

class IGameOfLife
{
public:
	virtual ~IGameOfLife() {}
	virtual void gameOfLife(std::vector<std::vector<int>> &board) = 0;
};