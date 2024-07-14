// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

int findMin(vector<int> &nums)
{
	if (nums.size() == 1)
	{
		return nums[0];
	}

	int first = nums[0];
	int last = nums.back();

	if (first < last)
	{
		return first;
	}

	int left = 0;
	int right = nums.size() - 1;
	int mid = -1;

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

	return nums[mid + 1];
}

int main(int argc, char const *argv[])
{
	vector<int> nums1{3, 4, 5, 1, 2};
	vector<int> nums2{4, 5, 6, 7, 0, 1, 2};
	vector<int> nums3{11, 13, 15, 17};

	int result1 = findMin(nums1);
	int result2 = findMin(nums2);
	int result3 = findMin(nums3);

	return 0;
}
