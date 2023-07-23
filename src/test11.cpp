// https://leetcode.com/problems/can-place-flowers

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    size_t counter = 0;
    size_t zeros = 1;

    for (size_t i = 0; i < flowerbed.size(); ++i)
    {
        if (flowerbed[i] == 0)
        {
            ++zeros;
            if (zeros == 3)
            {
                zeros = 1;
                ++counter;
            }
        }
        else
        {
            zeros = 0;
        }
    }

    if (zeros == 2)
    {
        ++counter;
    }

    return n <= counter;
}

int main(int argc, char const *argv[])
{
    bool res0 = false;
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    bool res4 = false;
    bool res5 = false;

    {
        vector<int> flowers{1, 0, 0, 0, 1};
        res0 = canPlaceFlowers(flowers, 1); // true
    }
    {
        vector<int> flowers{1, 0, 0, 0, 1};
        res1 = canPlaceFlowers(flowers, 2); // false
    }
    {
        vector<int> flowers{1, 0, 0, 0, 0, 0, 1};
        res2 = canPlaceFlowers(flowers, 2); // true
    }
    {
        vector<int> flowers{0, 0, 1, 0, 1};
        res3 = canPlaceFlowers(flowers, 1); // true
    }
    {
        vector<int> flowers{1, 0, 1, 0, 0};
        res4 = canPlaceFlowers(flowers, 1); // true
    }
    {
        vector<int> flowers{0, 0, 1, 0, 0};
        res5 = canPlaceFlowers(flowers, 1); // true
    }

    return 0;
}
