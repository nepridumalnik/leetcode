// https://leetcode.com/problems/reverse-vowels-of-a-string

static inline bool isVowel(char c)
{
    static const string vowels = "aeiouAEIOU";
    return vowels.find(c) != string::npos;
}

string reverseVowels(string s)
{
    char *leftSubstr = &s[0];
    char *rightSubstr = &s[s.size() - 1];

    while (leftSubstr < rightSubstr)
    {
        while (leftSubstr < rightSubstr && !isVowel(*leftSubstr))
        {
            ++leftSubstr;
        }
        while (leftSubstr < rightSubstr && !isVowel(*rightSubstr))
        {
            --rightSubstr;
        }

        swap(*leftSubstr, *rightSubstr);
        ++leftSubstr;
        --rightSubstr;
    }

    return s;
}

int main(int argc, char const *argv[])
{
    string res0 = reverseVowels("hello");                                         // "holle"
    string res1 = reverseVowels("leetcode");                                      // "leotcede"
    string res2 = reverseVowels("ai");                                            // "ia"
    string res3 = reverseVowels("Marge, let's \"went.\" I await news telegram."); // "Marge, let's \"went.\" i awaIt news telegram."
    string res4 = reverseVowels(" apG0i4maAs::sA0m4i0Gp0");                       // " ipG0A4mAas::si0m4a0Gp0"

    return 0;
}
