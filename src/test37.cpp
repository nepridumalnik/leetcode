// https://leetcode.com/problems/min-stack

class MinStack
{
public:
    void push(int val)
    {
        if (m_stack.empty())
        {
            m_stack.push({val, val});
        }
        else
        {
            m_stack.push({val, min(m_stack.top().second, val)});
        }
    }

    void pop()
    {
        if (!m_stack.empty())
        {
            m_stack.pop();
        }
    }

    int top()
    {
        if (m_stack.empty())
        {
            return 0;
        }

        return m_stack.top().first;
    }

    int getMin()
    {
        if (m_stack.empty())
        {
            return 0;
        }

        return m_stack.top().second;
    }

private:
    stack<pair<int, int>> m_stack;
};

int main(int argc, char const *argv[])
{
    MinStack s;
    int resMin = 0;
    int resTop = 0;

    s.push(-2);
    s.push(0);
    s.push(-3);

    resMin = s.getMin();
    resTop = s.top();

    s.pop();

    resTop = s.top();
    resMin = s.getMin();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
