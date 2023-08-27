// https://leetcode.com/problems/trapping-rain-water

int trap(vector<int> &height)
{
    vector<int> maxLeft;
    maxLeft.resize(height.size());
    maxLeft.front() = height.front();
    maxLeft.back() = height.back();

    int maxHeight = maxLeft.front();

    for (size_t i = 1; i < (height.size() - 1); ++i)
    {
        maxLeft[i] = max(maxHeight, height[i - 1]);
        maxHeight = max(maxHeight, height[i]);
    }

    vector<int> maxRight;
    maxRight.resize(height.size());
    maxRight.front() = height.front();
    maxRight.back() = height.back();

    maxHeight = maxRight.back();

    for (size_t i = 1; i < height.size(); ++i)
    {
        maxRight[height.size() - i - 1] = max(maxHeight, height[height.size() - i]);
        maxHeight = max(maxHeight, height[height.size() - i - 1]);
    }

    int square = 0;

    for (size_t i = 0; i < height.size(); ++i)
    {
        int currentMin = min(maxLeft[i], maxRight[i]);
        int currentSquare = currentMin - height[i];

        if (currentSquare > 0)
        {
            square += currentSquare;
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
