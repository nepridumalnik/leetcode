// https://leetcode.com/problems/increasing-triplet-subsequence

bool increasingTriplet(vector<int> &nums)
{
    const size_t n = nums.size();

    int first = INT_MAX;
    int second = INT_MAX;

    for (size_t i = 0; i < n; ++i)
    {
        const int currentNum = nums[i];

        if (first >= currentNum)
        {
            first = currentNum;
        }
        else if (second >= currentNum && currentNum > first)
        {
            second = currentNum;
        }
        else if (currentNum > second)
        {
            return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    bool res0 = false;
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    bool res4 = false;
    bool res5 = false;

    {
        vector<int> nums{1, 2, 3, 4, 5};
        res0 = increasingTriplet(nums); // true
    }
    {
        vector<int> nums{5, 4, 3, 2, 1};
        res1 = increasingTriplet(nums); // false
    }
    {
        vector<int> nums{2, 1, 5, 0, 4, 6};
        res2 = increasingTriplet(nums); // true
    }
    {
        vector<int> nums{1, 2, 1, 3};
        res3 = increasingTriplet(nums); // true
    }
    {
        vector<int> nums{2, 4, -2, -3};
        res4 = increasingTriplet(nums); // false
    }
    {
        vector<int> nums{1, 5, 0, 4, 1, 3};
        res5 = increasingTriplet(nums); // true
    }

    return 0;
}
