// https://leetcode.com/problems/single-number

int singleNumber(vector<int> &nums)
{
	int result = 0;

	for (auto num : nums)
	{
		result ^= num;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int result1 = singleNumber(vector<int>{2, 2, 1});		// 1
	int result2 = singleNumber(vector<int>{4, 1, 2, 1, 2}); // 4
	int result3 = singleNumber(vector<int>{1});				// 1

	return 0;
}
