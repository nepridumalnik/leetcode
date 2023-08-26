// https://leetcode.com/problems/car-fleet

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    static const auto getTimeToTarget = [](int target, int position, int speed) -> double
    {
        return (target - position) / speed;
    };

    // <position, speed>
    set<pair<int, int>> cars;
    // <time to target, position>
    stack<pair<double, int>> stk;

    for (size_t i = 0; i < position.size(); ++i)
    {
        cars.insert({position[i], speed[i]});
    }

    for (auto car = cars.rbegin(); car != cars.rend(); ++car)
    {
        double t = getTimeToTarget(target, car->first, car->second);

        if (stk.empty())
        {
            stk.push({t, car->first});
            continue;
        }

        if (stk.top().first < t)
        {
            stk.push({t, car->first});
        }
    }

    return stk.size();
}

int main(int argc, char const *argv[])
{
    int res0 = 0;
    int res1 = 0;
    int res2 = 0;

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

    return 0;
}
