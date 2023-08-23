// https://leetcode.com/problems/two-sum

vector<int> twoSum(vector<int> &nums, int target)
{
    multimap<int, int> positions;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        positions.insert({nums[i], i});
    }

    for (const auto &num : positions)
    {
        auto range = positions.equal_range(target - num.first);

        for (auto it = range.first; it != range.second; ++it)
        {
            if (it->second != num.second)
            {
                return {num.second, it->second};
            }
        }
    }

    return {};
}

int main(int argc, char const *argv[])
{
    vector<int> res0;
    vector<int> res1;
    vector<int> res2;

    {
        vector<int> nums{2, 7, 11, 15};
        res0 = twoSum(nums, 9); // [0, 1]
    }
    {
        vector<int> nums{3, 2, 4};
        res1 = twoSum(nums, 6); // [1, 2]
    }
    {
        vector<int> nums{3, 3};
        res2 = twoSum(nums, 6); // [0, 1]
    }

    return 0;
}
