// https://leetcode.com/problems/reverse-words-in-a-string

string reverseWords(string s)
{
    stringstream ss{s};
    string result;
    string tmp;
    result.reserve(s.size());

    while (ss >> tmp)
    {
        result = tmp + ' ' + result;
    }

    result.pop_back();

    return result;
}

int main(int argc, char const *argv[])
{
    string res0 = reverseWords("the sky is blue");  // "blue is sky the"
    string res1 = reverseWords("  hello world  ");  // "world hello"
    string res2 = reverseWords("a good   example"); // "example good a"
    string res3 = reverseWords("q");                // "q"
    string res4 = reverseWords("q a");              // "a q"
    string res5 = reverseWords("EPY2giL");          // "EPY2giL"

    return 0;
}
