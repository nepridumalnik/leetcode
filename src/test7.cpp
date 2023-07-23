// https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75

string mergeAlternately(string word1, string word2)
{
    const size_t minSize = std::min(word1.size(), word2.size());
    const size_t totalSize = word1.size() + word2.size();
    string result;
    result.reserve(totalSize);

    for (size_t i = 0; i < minSize; ++i)
    {
        result += word1[i];
        result += word2[i];
    }

    if (result.size() < totalSize)
    {
        if (minSize == word1.size())
        {
            result.append(word2.data() + minSize);
        }
        else
        {
            result.append(word1.data() + minSize);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    // string res0 = mergeAlternately("abc", "pqr"); // apbqcr
    // string res1 = mergeAlternately("ab", "cpqr"); // apbqcr
    // string res2 = mergeAlternately("abcd", "pq"); // apbqcd
    string res3 = mergeAlternately("ab", "pqrs"); // apbqrs

    return 0;
}
