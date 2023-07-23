#include <vector>

// https://leetcode.com/problems/two-sum/
std::vector<int> TwoSum(std::vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = (i + 1); j < nums.size(); ++j)
        {
            if ((nums[i] + nums[j]) == target)
            {
                return {i, j};
            }
        }
    }

    return {};
}

int main(int argc, char const *argv[])
{
    {
        auto vec = std::vector<int>{2, 7, 11, 15};
        auto res = TwoSum(vec, 9);
    }
    {
        auto vec = std::vector<int>{3, 2, 4};
        auto res2 = TwoSum(vec, 6);
    }
    {
        auto vec = std::vector<int>{3, 3};
        auto res3 = TwoSum(vec, 6);
    }

    return 0;
}
