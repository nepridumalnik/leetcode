// https://leetcode.com/problems/find-the-highest-altitude

int largestAltitude(vector<int> &gain)
{
    int hAlt = 0;
    int curAlt = 0;
    int i = 0;

    while (true)
    {
        if (hAlt < curAlt)
        {
            hAlt = curAlt;
        }

        if (!(i < gain.size()))
        {
            break;
        }

        curAlt += gain[i];

        ++i;
    }

    return hAlt;
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;

    {
        vector<int> gain{-5, 1, 5, 0, -7};
        res0 = largestAltitude(gain); // 1
    }
    {
        vector<int> gain{0, -4, -7, -9, -10, -6, -3, -1};
        res1 = largestAltitude(gain); // 0
    }
    {
        vector<int> gain{44, 32, -9, 52, 23, -50, 50, 33, -84, 47, -14, 84, 36, -62, 37, 81, -36, -85, -39, 67, -63, 64, -47, 95, 91, -40, 65, 67, 92, -28, 97, 100, 81};
        res2 = largestAltitude(gain); // 781
    }

    return 0;
}
