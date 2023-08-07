// https://leetcode.com/problems/max-number-of-k-sum-pairs

inline int sum_pos(vector<int> &nums, int start, int k, int size)
{
    for (int i = start + 1; i < size; ++i)
    {
        int a = nums[start];
        int b = nums[i];

        if ((a + b) == k)
        {
            return i;
        }
    }

    return -1;
}

int maxOperations(vector<int> &nums, int k) noexcept
{
    sort(nums.begin(), nums.end());

    int counter = 0;
    const int *left = nums.data();
    const int *right = left + nums.size() - 1;

    while (left < right)
    {
        int current = *left + *right;

        if (current == k)
        {
            ++left;
            --right;
            ++counter;
        }
        else if (current < k)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    return counter;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;

    {
        vector<int> nums{1, 2, 3, 4};
        res0 = maxOperations(nums, 5); // 2
    }
    {
        vector<int> nums{3, 1, 3, 4, 3};
        res1 = maxOperations(nums, 6); // 1
    }
    {
        vector<int> nums{4, 4, 1, 3, 1, 3, 2, 2, 5, 5, 1, 5, 2, 1, 2, 3, 5, 4};
        res2 = maxOperations(nums, 2); // 2
    }

    return 0;
}
