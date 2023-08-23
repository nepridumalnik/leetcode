// https://leetcode.com/problems/valid-anagram

bool isAnagram(string s, string t)
{
    map<char, size_t> mapS;
    map<char, size_t> mapT;

    auto stringToMap = [](map<char, size_t> &m, const string &s) -> void
    {
        for (char c : s)
        {
            auto it = m.find(c);

            if (it == m.end())
            {
                m.insert({c, 1});
            }
            else
            {
                ++it->second;
            }
        }
    };

    stringToMap(mapS, s);
    stringToMap(mapT, t);

    if (mapT.size() != mapS.size())
    {
        return false;
    }

    for (auto itt = mapT.begin(), its = mapS.begin(); itt != mapT.end() && its != mapS.end(); ++itt, ++its)
    {
        if (itt->first != its->first || itt->second != its->second)
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

    // res0 = isAnagram("anagram", "nagaram");
    // res1 = isAnagram("rat", "car");
    res2 = isAnagram("a", "ab");

    return 0;
}
