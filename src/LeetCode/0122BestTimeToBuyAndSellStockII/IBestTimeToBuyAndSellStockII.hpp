#pragma once

#include <vector>

class IBestTimeToBuyAndSellStockII
{
public:
	IBestTimeToBuyAndSellStockII() {};
	virtual ~IBestTimeToBuyAndSellStockII() {};
	virtual int maxProfit(std::vector<int>& prices) = 0;
};