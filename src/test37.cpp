// https://leetcode.com/problems/min-stack

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        m_stack.push(val);

        if (m_minStack.empty() || m_minStack.top().first > val)
        {
            m_minStack.push({val, 1});
        }
        else if (m_minStack.top().first == val)
        {
            ++m_minStack.top().second;
        }
    }

    void pop()
    {
        if (!m_minStack.empty())
        {
            if (m_minStack.top().first == m_stack.top())
            {
                if (m_minStack.top().second == 1)
                {
                    m_minStack.pop();
                }
                else
                {
                    --m_minStack.top().second;
                }
            }
        }

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

        return m_stack.top();
    }

    int getMin()
    {
        if (m_minStack.empty())
        {
            return 0;
        }

        return m_minStack.top().first;
    }

private:
    stack<int> m_stack;
    stack<pair<int, size_t>> m_minStack;
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
