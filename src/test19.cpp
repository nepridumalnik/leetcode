// https://leetcode.com/problems/container-with-most-water

int maxArea(vector<int> &h) noexcept
{
    int area = 0;
    const size_t size = h.size();
    const int *left = h.data();
    const int *right = h.data() + size - 1;

    while (left < right)
    {
        int current = min(*left, *right) * (right - left);
        area = max(current, area);

        if (*left < *right)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    return area;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res3 = 0;

    {
        vector<int> v{1, 8, 6, 2, 5, 4, 8, 3, 7};
        res0 = maxArea(v); // 49
    }
    {
        vector<int> v{1, 1};
        res1 = maxArea(v); // 1
    }
    {
        vector<int> v{1, 1, 2, 3, 2};
        res3 = maxArea(v); // 4
    }

    return 0;
}
