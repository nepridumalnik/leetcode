// https://leetcode.com/problems/unique-number-of-occurrences

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> nums;

    for (size_t i = 0; i < arr.size(); ++i)
    {
        auto it = nums.find(arr[i]);

        if (it != nums.end())
        {
            continue;
        }

        size_t counter = 0;

        for (int num : arr)
        {
            if (num == arr[i])
            {
                ++counter;
            }
        }

        nums.insert({arr[i], counter});
    }

    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        auto res = find_if(it, nums.end(), [it](const std::pair<int, int> &node)
                           { return node.second == it->second && node.first != it->first; });

        if (res != nums.end())
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    bool res0 = false;
    bool res1 = false;
    bool res2 = false;

    {
        vector<int> arr{1, 2, 2, 1, 1, 3};
        res0 = uniqueOccurrences(arr); // true
    }
    {
        vector<int> arr{1, 2};
        res1 = uniqueOccurrences(arr); // false
    }
    {
        vector<int> arr{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
        res2 = uniqueOccurrences(arr); // true
    }

    return 0;
}
