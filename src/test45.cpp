// https://leetcode.com/problems/3sum

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        for (size_t j = i + 1; j < nums.size(); ++j)
        {
            for (size_t k = j + 1; k < nums.size(); ++k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> triplet{nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    const auto compareTriplets = [&triplet](const vector<int> &other)
                    {
                        return triplet[0] == other[0] && triplet[1] == other[1] && triplet[2] == other[2];
                    };

                    auto it = find_if(result.begin(), result.end(), compareTriplets);
                    if (it == result.end())
                    {
                        result.push_back(std::move(triplet));
                    }
                }
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> res0;
    vector<vector<int>> res1;
    vector<vector<int>> res2;
    vector<vector<int>> res3;

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

    return 0;
}
