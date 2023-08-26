// https://leetcode.com/problems/daily-temperatures

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> mem;
    vector<int> answers;
    answers.resize(temperatures.size());

    for (size_t i = 0; i < temperatures.size() - 1; ++i)
    {
        if (temperatures[i] < temperatures[i + 1])
        {
            answers[i] = 1;
        }
        else
        {
            mem.push(i);
        }

        if (!mem.empty() && temperatures[mem.top()] < temperatures[i + 1])
        {
            while (!mem.empty() && temperatures[mem.top()] < temperatures[i + 1])
            {
                answers[mem.top()] = i - mem.top() + 1;
                mem.pop();
            }
        }
    }

    return answers;
}

int main(int argc, char const *argv[])
{
    vector<int> res0;
    vector<int> res1;
    vector<int> res2;

    {
        vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
        res0 = dailyTemperatures(temperatures); // [1,1,4,2,1,1,0,0]
    }
    {
        vector<int> temperatures{30, 40, 50, 60};
        res1 = dailyTemperatures(temperatures); // [1,1,1,0]
    }
    {
        vector<int> temperatures{30, 60, 90};
        res2 = dailyTemperatures(temperatures); // [1,1,0]
    }

    return 0;
}
