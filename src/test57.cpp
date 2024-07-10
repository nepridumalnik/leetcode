// https://leetcode.com/problems/binary-search

int search(vector<int> &nums, int target)
{
	std::vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);

	if (it != nums.end() && *it == target)
	{
		ptrdiff_t index = it - nums.begin();
		return static_cast<int>(index);
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	vector<int> v1{-1, 0, 3, 5, 9, 12};
	vector<int> v2{-1, 0, 3, 5, 9, 12};

	int result1 = search(v1, 9); // 4
	int result2 = search(v1, 2); // -1

	return 0;
}
