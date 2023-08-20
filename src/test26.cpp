// https://leetcode.com/problems/find-pivot-index

int pivotIndex(vector<int> &nums)
{
    int rightSum = 0;
    int leftSum = 0;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        rightSum += nums[i];
    }

    for (size_t i = 0; i < nums.size(); ++i)
    {
        const int current = nums[i];
        rightSum -= current;

        if (leftSum == rightSum)
        {
            return i;
        }

        leftSum += current;
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;

    {
        vector<int> nums{1, 7, 3, 6, 5, 6};
        res0 = pivotIndex(nums); // 3
    }
    {
        vector<int> nums{1, 2, 3};
        res1 = pivotIndex(nums); // -1
    }
    {
        vector<int> nums{2, 1, -1};
        res2 = pivotIndex(nums); // 0
    }
    {
        vector<int> nums{-1, -1, -1, 1, 1, 1};
        res3 = pivotIndex(nums); // -1
    }

    return 0;
}
