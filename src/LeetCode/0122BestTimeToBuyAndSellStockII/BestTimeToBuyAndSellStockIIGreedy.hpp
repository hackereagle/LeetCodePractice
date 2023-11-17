#pragma once

#include "IBestTimeToBuyAndSellStockII.hpp"

class BestTimeToBuyAndSellStockIIGreedy : public IBestTimeToBuyAndSellStockII
{
public:
	BestTimeToBuyAndSellStockIIGreedy() {};
	~BestTimeToBuyAndSellStockIIGreedy() {};
	int maxProfit(std::vector<int>& prices) override
	{
		int res = 0;
		size_t len = prices.size();
		for (int i = 1; i < len; i++) {
			res = res + std::max(prices[i] - prices[i - 1], 0);
		}
		return res;
	}
};