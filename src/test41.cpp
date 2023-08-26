// https://leetcode.com/problems/largest-rectangle-in-histogram

int largestRectangleArea(vector<int> &heights)
{
    stack<pair<size_t, int>> stk;
    size_t square = heights[0];

    stk.push({0, square});

    for (size_t i = 1; i < heights.size(); ++i)
    {
        if (heights[i] < stk.top().second)
        {
            size_t pos = 0;

            while (!stk.empty() && heights[i] < stk.top().second)
            {
                pos = stk.top().first;
                size_t newSquare = stk.top().second * (i - stk.top().first);
                square = max(square, newSquare);

                stk.pop();
            }

            stk.push({pos, heights[i]});
        }
        else
        {
            stk.push({i, heights[i]});
        }

        square = max(square, static_cast<size_t>(heights[i]));
    }

    // Считаем все дошедшие до конца
    while (!stk.empty())
    {
        size_t count = heights.size() - stk.top().first;
        square = max(square, static_cast<size_t>(stk.top().second * count));
        stk.pop();
    }

    return square;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;

    {
        vector<int> heights{2, 1, 5, 6, 2, 3};
        res0 = largestRectangleArea(heights); // 10
    }
    {
        vector<int> heights{2, 4};
        res1 = largestRectangleArea(heights); // 4
    }
    {
        vector<int> heights{2, 1, 2};
        res2 = largestRectangleArea(heights); // 3
    }
    {
        vector<int> heights{0};
        res3 = largestRectangleArea(heights); // 0
    }

    return 0;
}
