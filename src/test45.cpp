// https://leetcode.com/problems/3sum

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> result;

    for (size_t i = 0; i < nums.size() - 2; ++i)
    {
        for (size_t j = i + 1; j < nums.size() - 1; ++j)
        {
            int a = nums[i];
            int b = nums[j];
            int search = -(a + b);

            auto it = lower_bound(nums.begin() + j + 1, nums.end(), search);

            if (it != nums.end() && a + b + *it == 0)
            {
                result.insert({a, b, search});
            }
        }
    }

    return {make_move_iterator(result.begin()), make_move_iterator(result.end())};
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> res0;
    vector<vector<int>> res1;
    vector<vector<int>> res2;
    vector<vector<int>> res3;
    vector<vector<int>> res4;

    {
        vector<int> nums{-1, 0, 1, 2, -1, -4};
        res0 = threeSum(nums); // [[-1,-1,2],[-1,0,1]]
    }
    {
        vector<int> nums{0, 1, 1};
        res1 = threeSum(nums); // []
    }
    {
        vector<int> nums{0, 0, 0};
        res2 = threeSum(nums); // [[0,0,0]]
    }
    {
        vector<int> nums{1, -1, -1, 0};
        res3 = threeSum(nums); // [[-1,0,1]]
    }
    {
        vector<int> nums{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
        res4 = threeSum(nums); // [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
    }

    return 0;
}
