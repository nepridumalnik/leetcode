// https://leetcode.com/problems/maximum-average-subarray-i

double findMaxAverage(vector<int> &nums, int k)
{
    if (nums.size() < k)
    {
        return 0;
    }

    int result = 0;
    int current = 0;

    for (size_t i = 0; i < k; ++i)
    {
        result += nums[i];
    }

    current = result;

    for (size_t i = k; i < nums.size(); ++i)
    {
        current -= nums[i - k];
        current += nums[i];

        if (result < current)
        {
            result = current;
        }
    }

    return static_cast<double>(result) / k;
}

int main(int argc, char const *argv[])
{
    double res0 = 0;
    double res1 = 0;

    {
        vector<int> nums{1, 12, -5, -6, 50, 3};
        res0 = findMaxAverage(nums, 4); // 12.75
    }
    {
        vector<int> nums{5};
        res1 = findMaxAverage(nums, 1); // 5
    }

    return 0;
}
