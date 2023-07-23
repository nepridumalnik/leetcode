// https://leetcode.com/problems/asteroid-collision/
#include <vector>
#include <cmath>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> res;

    for (int i = 0; i < asteroids.size(); ++i)
    {
        int a = asteroids[i];

        if (a > 0)
        {
            res.push_back(a);
        }
        else if (res.empty() || res.back() < 0)
        {
            res.push_back(a);
        }
        else if (res.back() <= -a)
        {
            if (res.back() < -a)
            {
                --i;
            }

            res.pop_back();
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> vec0; // {-2, -2, -2}
    vector<int> vec1; // {5, 10}
    vector<int> vec2; // {}
    vector<int> vec3; // {10}
    vector<int> vec4; // {-2, -1, 1, 2}
    vector<int> vec5; // {-2, -2, -2}
    vector<int> vec6; // {10}

    {
        vector<int> vec{-2, -2, 1, -2};
        vec0 = asteroidCollision(vec);
    }
    {
        vector<int> vec{5, 10, -5};
        vec1 = asteroidCollision(vec);
    }
    {
        vector<int> vec{8, -8};
        vec2 = asteroidCollision(vec);
    }
    {
        vector<int> vec{10, 2, -5};
        vec3 = asteroidCollision(vec);
    }
    {
        vector<int> vec{-2, -1, 1, 2};
        vec4 = asteroidCollision(vec);
    }
    {
        vector<int> vec{1, -2, -2, -2};
        vec5 = asteroidCollision(vec);
    }
    {
        vector<int> vec{10, 2, -5};
        vec6 = asteroidCollision(vec);
    }

    return 0;
}
