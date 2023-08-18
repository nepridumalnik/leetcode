// https://leetcode.com/problems/max-consecutive-ones-iii

int longestOnes(vector<int> &nums, int k)
{
    int longest = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        int current = 0;

        for (int j = i, temp = k; j < nums.size(); ++j)
        {
            if (nums[j] == 0)
            {
                --temp;

                if (temp < 0)
                {
                    break;
                }
            }

            ++current;
        }

        if (longest < current)
        {
            longest = current;
        }
    }

    return longest;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;

    {
        vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
        res0 = longestOnes(nums, 2); // 6
    }
    {
        vector<int> nums{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
        res1 = longestOnes(nums, 3); // 10
    }

    return 0;
}
