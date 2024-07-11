// https://leetcode.com/problems/guess-number-higher-or-lower

int guessedNum = 0;

int guess(int num)
{
    if (guessedNum < num)
    {
        return -1;
    }
    else if (guessedNum > num)
    {
        return 1;
    }

    return 0;
}

int guessNumber(int n)
{
    static const int higher = 1;

    int proposal = n / 2;
    int step = proposal / 2;
    int result = 0;

    while (result = guess(proposal), result != 0)
    {
        if (result == higher)
        {
            proposal += step;
        }
        else
        {
            proposal -= step;
        }

        step /= 2;
        if (!step)
        {
            step = 1;
        }
    }

    return proposal;
}

int main(int argc, char const *argv[])
{
    guessedNum = 6;
    int result1 = guessNumber(10); // 6
    guessedNum = 1;
    int result2 = guessNumber(1);
    guessedNum = 1;
    int result3 = guessNumber(2);
    guessedNum = 255;
    int result4 = guessNumber(512);

    for (int guess = 0; guess < 100; ++guess)
    {
        for (int max = 0; max < guess + 50; ++max)
        {
            guessedNum = guess;
            int result = guessNumber(max);
            if (result != guess)
            {
                return -1;
            }
        }
    }

    return 0;
}
