// https://leetcode.com/problems/min-stack

struct Node
{
    Node(int value = 0, Node *previous = nullptr)
        : val{value}, prev{previous}
    {
    }

    int val;
    Node *prev;
};

class MinStack
{
public:
    MinStack()
        : m_head{nullptr}, m_tail{nullptr}
    {
    }

    void push(int val)
    {
        m_tail = new Node{val, m_tail};

        if (m_minValue.empty() || m_minValue.back() >= val)
        {
            m_minValue.push_back(val);
        }

        if (!m_head)
        {
            m_head = m_tail;
        }
    }

    void pop()
    {
        if (!m_tail)
        {
            return;
        }

        Node *prev = m_tail->prev;
        Node *last = m_tail;

        if (!prev)
        {
            m_head = nullptr;
            m_tail = nullptr;

            while (!m_minValue.empty())
            {
                m_minValue.pop_back();
            }
        }
        else
        {
            m_tail = prev;
        }

        if (!m_minValue.empty() && m_minValue.back() == last->val)
        {
            m_minValue.pop_back();
        }

        delete last;
    }

    int top()
    {
        if (m_tail)
        {
            return m_tail->val;
        }

        return 0;
    }

    int getMin()
    {
        if (!m_minValue.empty())
        {
            return m_minValue.back();
        }

        return 0;
    }

private:
    Node *m_head;
    Node *m_tail;

    list<int> m_minValue;
};

int main(int argc, char const *argv[])
{
    MinStack s;
    int resMin = 0;
    int resTop = 0;

    // s.push(1);
    // s.push(2);
    // s.push(0);
    // s.push(3);

    s.push(-2);
    s.push(0);
    s.push(-3);

    resMin = s.getMin();
    resTop = s.top();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
