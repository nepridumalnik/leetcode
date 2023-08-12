// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

int maxVowels(string s, int k)
{
    static const auto isVowel = [](char c) -> bool
    {
        static const string vowels = "aeoiu";
        return vowels.find(c) != string::npos;
    };

    size_t count = 0;
    size_t current = 0;
    bool firstIsVowel = isVowel(s[0]);

    for (size_t i = 0; i < k; ++i)
    {
        if (isVowel(s[i]))
        {
            ++count;
        }
    }

    current = count;

    for (size_t i = k; i < s.size(); ++i)
    {
        if (isVowel(s[i - k]))
        {
            --current;
        }

        if (isVowel(s[i]))
        {
            ++current;
        }

        if (current > count)
        {
            count = current;
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;

    res0 = maxVowels("abciiidef", 3); // 3
    res1 = maxVowels("aeiou", 2);     // 2
    res2 = maxVowels("leetcode", 3);  // 2

    return 0;
}
