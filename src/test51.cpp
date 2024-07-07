// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

void rotate(vector<int> &nums, int k)
{
	int newK = 0;

	if (k == nums.size())
	{
		return;
	}
	else if (k > nums.size())
	{
		int result = k / nums.size();
		newK = k - (result * nums.size());
	}
	else
	{
		newK = k;
	}

	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + newK);
	reverse(nums.begin() + newK, nums.end());
}

int main(int argc, char const *argv[])
{
	vector<int> nums1{1, 2, 3, 4, 5, 6, 7};
	rotate(nums1, 3); // 5,6,7,1,2,3,4
	vector<int> nums2{-1, -100, 3, 99};
	rotate(nums2, 2); // 3,99,-1,-100

	return 0;
}
