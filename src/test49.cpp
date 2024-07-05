// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

int removeDuplicates(vector<int> &nums)
{
	if (nums.empty())
	{
		return 0;
	}

	int index = 1;
	int counter = 1;

	for (size_t i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == nums[i - 1])
		{
			if (counter < 2)
			{
				nums[index++] = nums[i];
			}
			++counter;
		}
		else
		{
			nums[index++] = nums[i];
			counter = 1;
		}
	}

	return index;
}

int main(int argc, char const *argv[])
{
	int result1 = 0; // 5
	std::vector<int> nums1 = {1, 1, 1, 2, 2, 3};
	int result2 = 0; // 7
	std::vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
	int result3 = 0; // 2
	std::vector<int> nums3 = {0, 0};
	int result4 = 0; // 1
	std::vector<int> nums4 = {0};
	int result5 = 0; // 0
	std::vector<int> nums5;
	int result6 = 0; // 2
	std::vector<int> nums6 = {1, 1, 1, 1, 1, 1};

	result1 = removeDuplicates(nums1);
	result2 = removeDuplicates(nums2);
	result3 = removeDuplicates(nums3);
	result4 = removeDuplicates(nums4);
	result5 = removeDuplicates(nums5);
	result6 = removeDuplicates(nums6);

	return 0;
}
