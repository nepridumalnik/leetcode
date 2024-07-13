// https://leetcode.com/problems/search-in-rotated-sorted-array

int binarySearch(vector<int> &nums, int left, int right, int target)
{
	while (left <= right)
	{
		if (left == right)
		{
			if (nums[left] == target)
			{
				return left;
			}
			return -1;
		}

		int mid = left + (right - left) / 2;
		int e = nums[mid];

		if (e == target)
		{
			return mid;
		}
		else if (e < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}

int searchRotated(vector<int> &nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid = -1;
	int first = nums[0];
	int last = nums.back();

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		int e = nums[mid];
		int rn = mid + 1 < nums.size() ? nums[mid + 1] : 0;
		int ln = mid - 1 >= 0 ? nums[mid - 1] : 0;

		if (ln && ln > e)
		{
			--mid;
			break;
		}
		else if (rn && rn < e)
		{
			break;
		}
		else if (e < first)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (left > right)
	{
		return -1;
	}

	if (target > nums.back())
	{
		return binarySearch(nums, 0, mid, target);
	}

	return binarySearch(nums, mid + 1, nums.size() - 1, target);
}

int search(vector<int> &nums, int target)
{
	// Ротирован
	if (nums.back() < *nums.begin())
	{
		return searchRotated(nums, target);
	}

	// Не ротирован
	return binarySearch(nums, 0, nums.size() - 1, target);
}

int main(int argc, char const *argv[])
{
	int target0 = 4;
	vector<int> nums0{0, 1, 2, 3, 4, 5, 6, 7};
	int target1 = 0;
	vector<int> nums1{4, 5, 6, 7, 0, 1, 2};
	int target2 = 3;
	vector<int> &nums2 = nums1;
	int target3 = 0;
	vector<int> nums3{1};
	int target4 = 0;
	vector<int> nums4{1, 3, 0};
	int target5 = 0;
	vector<int> nums5{3, 1};
	int target6 = 3;
	vector<int> nums6{3, 1};
	int target7 = 1;
	vector<int> nums7{4, 5, 1, 2, 3};

	int result0 = search(nums0, target0); // 4
	int result1 = search(nums1, target1); // 4
	int result2 = search(nums2, target2); // -1
	int result3 = search(nums3, target3); // -1
	int result4 = search(nums4, target4); // 2
	int result5 = search(nums5, target5); // -1
	int result6 = search(nums6, target6); // 0
	int result7 = search(nums7, target7); // 2

	return 0;
}
