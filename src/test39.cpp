// https://leetcode.com/problems/generate-parentheses

void backtracking(vector<string> &ps, string &p, size_t open, size_t close, size_t n)
{
    if (open == close && open == n)
    {
        ps.push_back(p);
        return;
    }

    if (open < n)
    {
        p += '(';
        backtracking(ps, p, open + 1, close, n);

        if (!p.empty())
        {
            p.pop_back();
        }
    }

    if (close < open)
    {
        p += ')';
        backtracking(ps, p, open, close + 1, n);

        if (!p.empty())
        {
            p.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ps;
    string p;
    p.reserve(n * 2);

    backtracking(ps, p, 0, 0, n);

    return ps;
}

int main(int argc, char const *argv[])
{
    vector<string> res0;
    vector<string> res1;

    res0 = generateParenthesis(3); // ["((()))","(()())","(())()","()(())","()()()"]
    res1 = generateParenthesis(1); // ["()"]

    return 0;
}
