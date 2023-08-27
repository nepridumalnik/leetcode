// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

vector<int> twoSum(vector<int> &numbers, int target)
{
    for (size_t i = 0; i < (numbers.size() - 1); ++i)
    {
        int n = numbers[i];
        int search = target - n;
        int start = i + 1;

        // O(log(n))
        auto pos = lower_bound(numbers.begin() + start, numbers.end(), search);

        if (pos == numbers.end())
        {
            continue;
        }

        int n2 = numbers[pos - numbers.begin()];

        if (n + n2 != target)
        {
            continue;
        }

        return {int(i + 1), int(pos - numbers.begin() + 1)};
    }

    return {};
}

int main(int argc, char const *argv[])
{
    vector<int> res0;
    vector<int> res1;
    vector<int> res2;

    {
        vector<int> numbers{2, 7, 11, 15};
        res0 = twoSum(numbers, 9); //[1,2]
    }
    {
        vector<int> numbers{2, 3, 4};
        res1 = twoSum(numbers, 6); //[1,3]
    }
    {
        vector<int> numbers{-1, 0};
        res2 = twoSum(numbers, -1); //[1,2]
    }

    return 0;
}
