// https://leetcode.com/problems/find-the-difference-of-two-arrays

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> result;
    set<int> nums;

    for (int num : nums1)
    {
        auto res = find_if(nums2.begin(), nums2.end(), [num](int e)
                           { return e == num; });

        if (res == nums2.end())
        {
            nums.insert(num);
        }
    }

    result.push_back({nums.begin(), nums.end()});
    nums.clear();

    for (int num : nums2)
    {
        auto res = find_if(nums1.begin(), nums1.end(), [num](int e)
                           { return e == num; });

        if (res == nums1.end())
        {
            nums.insert(num);
        }
    }

    result.push_back({nums.begin(), nums.end()});

    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> res0;
    vector<vector<int>> res1;

    {
        vector<int> nums1{1, 2, 3};
        vector<int> nums2{2, 4, 6};
        res0 = findDifference(nums1, nums2); // [[1,3],[4,6]]
    }
    {
        vector<int> nums1{1, 2, 3, 3};
        vector<int> nums2{1, 1, 2, 2};
        res1 = findDifference(nums1, nums2); // [[3],[]]
    }

    return 0;
}
