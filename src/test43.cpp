// https://leetcode.com/problems/valid-palindrome

bool isPalindrome(string s)
{
    static const auto notALetterOrNumber = [](char c) -> bool
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    };

    for (int left = 0, right = (s.size() - 1); left < right; ++left, --right)
    {
        while (!notALetterOrNumber(s[left]) && left < right)
        {
            ++left;
        }
        while (!notALetterOrNumber(s[right]) && right > left)
        {
            --right;
        }

        char lc = tolower(s[left]);
        char rc = tolower(s[right]);

        if (lc != rc)
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
    bool res3 = false;
    bool res4 = false;

    res0 = isPalindrome("A man, a plan, a canal: Panama"); // true
    res1 = isPalindrome("race a car");                     // false
    res2 = isPalindrome(" ");                              // true
    res3 = isPalindrome("a.");                             // true
    res4 = isPalindrome("ab@a");                           // true

    return 0;
}
