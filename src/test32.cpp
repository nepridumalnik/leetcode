// https://leetcode.com/problems/group-anagrams

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> um;
    vector<vector<string>> output;

    for (auto &s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());

        auto it = um.find(key);

        if (it == um.end())
        {
            um.insert({key, {std::move(s)}});
        }
        else
        {
            it->second.push_back(std::move(s));
        }
    }

    for (auto &s : um)
    {
        output.push_back(std::move(s.second));
    }

    return output;
}

int main(int argc, char const *argv[])
{
    vector<vector<string>> res0;
    vector<vector<string>> res1;
    vector<vector<string>> res2;

    {
        vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
        res0 = groupAnagrams(strs); // [["bat"],["nat","tan"],["ate","eat","tea"]]
    }
    {
        vector<string> strs{""};
        res1 = groupAnagrams(strs); // [[""]]
    }
    {
        vector<string> strs{"a"};
        res2 = groupAnagrams(strs); // [["a"]]
    }

    return 0;
}
