// https://leetcode.com/problems/top-k-frequent-elements

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, size_t> frequencies;

    for (int n : nums)
    {
        auto it = frequencies.find(n);

        if (it == frequencies.end())
        {
            frequencies.insert({n, 1});
        }
        else
        {
            ++it->second;
        }
    }

    multimap<size_t, int> revert;

    for (const auto &f : frequencies)
    {
        revert.insert({f.second, f.first});
    }

    vector<int> output;
    size_t counter = 0;

    output.reserve(k);

    for (auto it = revert.rbegin(); it != revert.rend() && counter < k; ++it, ++counter)
    {
        output.push_back(it->second);
    }

    return output;
}

int main(int argc, char const *argv[])
{
    vector<int> res0;
    vector<int> res1;

    {
        vector<int> nums{1, 1, 1, 2, 2, 3};
        res0 = topKFrequent(nums, 2); // [1,2]
    }
    {
        vector<int> nums{1};
        res1 = topKFrequent(nums, 2); // [1]
    }

    return 0;
}
