// https://leetcode.com/problems/longest-consecutive-sequence

int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    set<int> s{nums.begin(), nums.end()};
    size_t count = 0;
    int lastOne = 0;
    auto it = s.begin();

    do
    {
        lastOne = *it;
        ++it;
        ++count;
    } while (it != s.end() && *it == (lastOne + 1));

    return count;
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
