// https://stepik.org/lesson/13228/step/7?unit=3414

int fibonache(int num)
{
    if (num <= 1)
    {
        return num;
    }

    int result = 0;
    int prev = 0;
    int last = 1;

    for (int i = 0; i < (num - 1); ++i)
    {
        result = last + prev;
        prev = last;
        last = result;
    }

    return result;
}

int fibonache2(int num)
{
    if (num <= 1)
    {
        return num;
    }

    int result = 0;
    int prev = 0;
    int last = 1;

    for (int i = 0; i < (num - 1); ++i)
    {
        result = last + prev;
        prev = last % 10;
        last = result % 10;
    }

    return result % 10;
}

int main(int argc, char const *argv[])
{
    int res = fibonache2(841645); // 5
    int res0 = fibonache(0);      // 0
    int res1 = fibonache(1);      // 1
    int res2 = fibonache(2);      // 1
    int res3 = fibonache(3);      // 2
    int res4 = fibonache(4);      // 3
    int res5 = fibonache(5);      // 5
    int res6 = fibonache(6);      // 8

    return 0;
}
