// https://leetcode.com/problems/car-fleet

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    // <position, speed>
    vector<pair<int, int>> cars;
    // <time to target, position>
    stack<pair<double, int>> stk;

    // O(n)
    for (size_t i = 0; i < position.size(); ++i)
    {
        cars.push_back({position[i], speed[i]});
    }

    // O(n*log(n))
    sort(cars.rbegin(), cars.rend());

    // O(n)
    for (auto car = cars.begin(); car != cars.end(); ++car)
    {
        int pos = car->first;
        int sp = car->second;
        double t = (static_cast<double>(target) - static_cast<double>(pos)) / static_cast<double>(sp);

        if (stk.empty() || stk.top().first < t)
        {
            stk.push({t, pos});
        }
    }

    return stk.size();
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    int res4 = 0;

    {
        vector<int> position{10, 8, 0, 5, 3};
        vector<int> speed{2, 4, 1, 1, 3};
        res0 = carFleet(12, position, speed); // 3
    }
    {
        vector<int> position{3};
        vector<int> speed{3};
        res1 = carFleet(10, position, speed); // 1
    }
    {
        vector<int> position{0, 2, 4};
        vector<int> speed{4, 2, 1};
        res2 = carFleet(100, position, speed); // 1
    }
    {
        vector<int> position{6, 8};
        vector<int> speed{3, 2};
        res3 = carFleet(10, position, speed); // 2
    }
    {
        vector<int> position{10, 8, 0, 5, 3};
        vector<int> speed{2, 4, 1, 1, 3};
        res4 = carFleet(12, position, speed); // 3
    }

    return 0;
}
