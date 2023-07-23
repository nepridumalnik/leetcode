// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    vector<bool> result;
    result.resize(candies.size());
    size_t greatestCandies = 0;

    for (size_t i = 0; i < candies.size(); ++i)
    {
        if (candies[i] > greatestCandies)
        {
            greatestCandies = candies[i];
        }
    }

    for (size_t i = 0; i < result.size(); ++i)
    {
        result[i] = (candies[i] + extraCandies) >= greatestCandies;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<bool> res0; // true, true, true, false, true
    vector<bool> res1; // true, false, false, false, false
    vector<bool> res2; // true, false, true

    {
        vector<int> candies{2, 3, 5, 1, 3};
        res0 = kidsWithCandies(candies, 3);
    }
    {
        vector<int> candies{4, 2, 1, 1, 2};
        res1 = kidsWithCandies(candies, 1);
    }
    {
        vector<int> candies{12, 1, 12};
        res2 = kidsWithCandies(candies, 10);
    }

    return 0;
}
