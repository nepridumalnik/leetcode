// https://leetcode.com/problems/valid-parentheses

bool isValid(string s)
{
    stack<char> parentheses;

    static const auto isOpening = [](char c) -> bool
    { return c == '(' || c == '[' || c == '{'; };
    static const auto isClosing = [](char c) -> bool
    { return c == ')' || c == ']' || c == '}'; };
    static const auto isSameType = [](char p, char c) -> bool
    { return (p == '(' && c == ')') || (p == '[' && c == ']') || (p == '{' && c == '}'); };

    for (char c : s)
    {
        if (parentheses.empty())
        {
            parentheses.push(c);
        }
        else
        {
            const char last = parentheses.top();

            if (isOpening(last))
            {
                if (isClosing(c))
                {
                    if (!isSameType(last, c))
                    {
                        return false;
                    }

                    parentheses.pop();
                }
                else if (isOpening(c))
                {
                    parentheses.push(c);
                }
            }
        }
    }

    return parentheses.empty();
}

int main(int argc, char const *argv[])
{
    bool res0 = false;
    bool res1 = false;
    bool res2 = false;

    res0 = isValid("()");     // true
    res1 = isValid("()[]{}"); // true
    res2 = isValid("(]");     // false
    res2 = isValid("{[]}");   // true

    return 0;
}
