// https://leetcode.com/problems/trapping-rain-water

int trap(vector<int> &height)
{
    int square = 0;
    int *left = height.data();
    int *right = height.data() + height.size() - 1;
    int maxLeft = *left;
    int maxRight = *right;

    while (left < right)
    {
        if (*left <= *right)
        {
            ++left;
            maxLeft = max(*left, maxLeft);
            square += maxLeft - *left;
        }
        else
        {
            --right;
            maxRight = max(*right, maxRight);
            square += maxRight - *right;
        }
    }

    return square;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;

    {
        vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        res0 = trap(height); // 6
    }
    {
        vector<int> height{4, 2, 0, 3, 2, 5};
        res1 = trap(height); // 9
    }

    return 0;
}
