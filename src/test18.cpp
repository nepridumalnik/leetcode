// https://leetcode.com/problems/is-subsequence

bool isSubsequence(string s, string t)
{
    if (s.size() > t.size())
    {
        return false;
    }

    if (s.empty())
    {
        return true;
    }

    for (size_t i = 0, counter = 0, lastPos = 0; i < s.size() && lastPos < t.size(); ++i)
    {
        for (;; ++lastPos)
        {
            if (s[i] == t[lastPos])
            {
                ++counter;
                ++lastPos;
                break;
            }

            if (lastPos == t.size() - 1)
            {
                return false;
            }
        }

        if (counter == s.size())
        {
            return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    bool res0 = isSubsequence("abc", "ahbgdc"); // true
    bool res1 = isSubsequence("axc", "ahbgdc"); // false
    bool res2 = isSubsequence("abc", "");       // false
    bool res3 = isSubsequence("s", "b");        // false
    bool res4 = isSubsequence("", "ahbgdc");    // true
    bool res5 = isSubsequence("acb", "ahbgdc"); // false

    return 0;
}
