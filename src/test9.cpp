// https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75

bool containsOnlyDivisors(const string &str, const string &divisor)
{
    if (divisor.size() > str.size())
    {
        return false;
    }

    for (size_t i = 0, j = 0; i < str.size();)
    {
        for (size_t j = i + divisor.size(), offset = 0; i < j; ++i, ++offset)
        {
            if (str[i] != divisor[offset])
            {
                return false;
            }
        }
    }

    return true;
}

// Лучшее решение использовало std::gcd, что считаю неспортивным поведением
string gcdOfStrings(string str1, string str2)
{
    const size_t minLen = std::min(str1.size(), str2.size());
    string divisor;
    string result;

    for (size_t i = 0; i < minLen; ++i)
    {
        if (str1[i] != str2[i])
        {
            break;
        }

        divisor += str1[i];

        if (containsOnlyDivisors(str1, divisor) && containsOnlyDivisors(str2, divisor))
        {
            result = divisor;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    // string res0 = gcdOfStrings("ABCABC", "ABC");    // "ABC"
    // string res1 = gcdOfStrings("ABABAB", "ABAB");   // "AB"
    // string res2 = gcdOfStrings("LEET", "CODE");     // ""
    string res3 = gcdOfStrings("ABABABAB", "ABAB"); // "ABAB"

    return 0;
}
