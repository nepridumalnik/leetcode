// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

// TODO: изучить жадный массив
int maxProfit(vector<int> &prices)
{
	int start = prices[0];
	int max = 0;

	for (size_t i = 1; i < prices.size(); ++i)
	{
		if (start < prices[i])
		{
			max += prices[i] - start;
		}

		start = prices[i];
	}

	return max;
}

int main(int argc, char const *argv[])
{
	int result = maxProfit(vector<int>{7, 1, 5, 3, 6, 4});

	return 0;
}
