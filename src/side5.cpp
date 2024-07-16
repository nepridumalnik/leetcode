#include <iostream>

template <typename T>
class A
{
public:
    A(T &&t) : t_{std::forward<T>(t)}
    {
    }

    A(const T &t) : t_{t}
    {
    }

    const T &getValue() const
    {
        return t_;
    }

private:
    T t_;
};

ostream &operator<<(ostream &o, const vector<int> &v)
{
    for (int n : v)
    {
        o << n << ' ';
    }

    return o;
}

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 4, 5};
    A<vector<int>> a{v};
    A<vector<int>> b{vector<int>{1, 2, 3}};

    b = a;

    std::cout << a.getValue() << std::endl;

    return 0;
}
