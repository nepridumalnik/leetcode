void revertString(char *str, size_t len)
{
    for (size_t i = 0; i < len / 2; ++i)
    {
        swap(str[i], str[len - 1 - i]);
    }
}

int main(int argc, char const *argv[])
{
    char str[] = "revert me";

    revertString(str, sizeof(str) - 1);

    return 0;
}
