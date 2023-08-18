// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

int longestSubarray(vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int k = 1;

    while (j < nums.size())
    {
        if (nums[j] == 0)
        {
            --k;
        }

        if (k < 0)
        {
            if (nums[i] == 0)
            {
                ++k;
            }

            ++i;
        }

        ++j;
    }

    return j - i - 1;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;

    {
        vector<int> nums{1, 1, 0, 1};
        res0 = longestSubarray(nums); // 3
    }
    {
        vector<int> nums{0, 1, 1, 1, 0, 1, 1, 0, 1};
        res1 = longestSubarray(nums); // 5
    }
    {
        vector<int> nums{1, 1, 1};
        res2 = longestSubarray(nums); // 2
    }

    return 0;
}
