// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

int majorityElement(vector<int> &nums)
{
	std::map<int, int> numsCounter;
	const size_t encounters = nums.size() / 2;

	for (size_t i = 0; i < nums.size(); ++i)
	{
		numsCounter[nums[i]]++;
	}

	for (auto it = numsCounter.rbegin(); it != numsCounter.rend(); ++it)
	{
		if (it->second > encounters)
		{
			return it->first;
		}
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	int result1 = 0; // 3
	vector<int> nums1 = {3, 2, 3};
	int result2 = 0; // 2
	vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};

	result1 = majorityElement(nums1);
	result2 = majorityElement(nums2);

	return 0;
}
