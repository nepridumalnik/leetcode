// https://leetcode.com/problems/contains-duplicate

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> s;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        auto it = s.find(nums[i]);

        if (it != s.end())
        {
            return true;
        }
        else
        {
            s.insert(nums[i]);
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    bool res0 = false;
    bool res1 = false;
    bool res2 = false;

    {
        vector<int> nums{1, 2, 3, 1};
        res0 = containsDuplicate(nums); // true
    }
    {
        vector<int> nums{1, 2, 3, 4};
        res1 = containsDuplicate(nums); // false
    }
    {
        vector<int> nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        res2 = containsDuplicate(nums); // true
    }

    return 0;
}
