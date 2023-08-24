// https://leetcode.com/problems/longest-consecutive-sequence

int longestConsecutive(vector<int> &nums)
{
    const unordered_set<int> s{nums.begin(), nums.end()};
    size_t longest = 0;

    for (const int n : s)
    {
        if (!s.count(n - 1))
        {
            size_t current = 1;
            while (s.count(n + current))
            {
                ++current;
            }

            longest = max(longest, current);
        }
    }

    return longest;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;

    {
        vector<int> nums{100, 4, 200, 1, 3, 2};
        res0 = longestConsecutive(nums); // 4
    }
    {
        vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        res1 = longestConsecutive(nums); // 9
    }
    {
        vector<int> nums{};
        res2 = longestConsecutive(nums); // 0
    }
    {
        vector<int> nums{9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
        res3 = longestConsecutive(nums); // 7
    }

    return 0;
}
