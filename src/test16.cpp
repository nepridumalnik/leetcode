// https://leetcode.com/problems/string-compression

static inline void addNum(int &result, const std::pair<const char, size_t> &n)
{
    result <<= 4;
    if (n.first >= 'a' && n.first <= 'z')
    {
        result += (n.first - 'a' + 10);
    }
    else
    {
        result += (n.first - '0');
    }

    if (n.second == 1)
    {
        return;
    }

    size_t sec = n.second;

    while (true)
    {
        result <<= 4;

        if (sec > 10)
        {
            const size_t dozens = (sec / 10 * 10);
            result += (dozens / 10);
            sec -= dozens;
        }
        else
        {
            result += sec;
            return;
        }
    }
}

int compress(vector<char> &chars)
{
    map<char, size_t> nums;

    for (char c : chars)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c -= ('a' - 'A');
        }

        std::map<char, size_t>::iterator it = nums.find(c);

        if (it == nums.end())
        {
            nums.insert({c, 1});
        }
        else
        {
            ++it->second;
        }
    }

    int result = 0;

    for (const std::pair<const char, size_t> &n : nums)
    {
        addNum(result, n);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;

    {
        vector<char> chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
        res0 = compress(chars); // a2b2c3 | 10662595
    }
    {
        vector<char> chars{'a'};
        res1 = compress(chars); // a | 10
    }
    {
        vector<char> chars{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
        res2 = compress(chars); // ab12 | 43794
    }
    {
        vector<char> chars{'1', '2', '2', 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
        res3 = compress(chars); // 122ab12 | 19049234
    }

    return 0;
}
