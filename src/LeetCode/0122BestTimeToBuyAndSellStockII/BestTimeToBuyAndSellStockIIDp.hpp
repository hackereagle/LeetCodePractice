#pragma once
#include "IBestTimeToBuyAndSellStockII.hpp"

class BestTimeToBuyAndSellStockIIDp : public IBestTimeToBuyAndSellStockII
{
public:
	BestTimeToBuyAndSellStockIIDp() {};
	~BestTimeToBuyAndSellStockIIDp() {};
	int maxProfit(std::vector<int>& prices) override
	{
		int res = 0;

		size_t len = prices.size();
		std::vector<int> dp(len, -1);
		dp[0] = 0;
		int diff = 0;
		for (int i = 1; i < len; i++) {
			diff = prices[i] - prices[i - 1];
			if (diff > 0) {
				dp[i] = dp[i - 1] + diff;
			}
			else {
				dp[i] = dp[i - 1];
			}
		}

		res = dp[len - 1];

		return res;
	}
};