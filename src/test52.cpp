// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

int maxProfit(vector<int> &prices)
{
	int maxProfit = 0;
	int minimumPrice = prices[0];

	for (size_t i = 0; i < prices.size(); ++i)
	{
		maxProfit = max(maxProfit, prices[i] - minimumPrice);
		minimumPrice = min(minimumPrice, prices[i]);
	}

	return maxProfit;
}

int main(int argc, char const *argv[])
{
	int result1 = 5;
	vector<int> prices1 = {7, 1, 5, 3, 6, 4};
	int result2 = 0;
	vector<int> prices2 = {7, 6, 4, 3, 1};

	result1 = maxProfit(prices1);
	result2 = maxProfit(prices2);

	return 0;
}
