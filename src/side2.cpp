// Своя реализация двусвязного списка

template <typename T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode *prev;

    ListNode() : val{0}, next{nullptr} {};
    ListNode(int x, ListNode *prev = nullptr, ListNode *next = nullptr) : val{x}, prev{prev}, next{next} {};
    ~ListNode() { delete next; }
};

template <typename T>
class List
{
public:
    List() : head{nullptr}, back{nullptr} {}

    ~List()
    {
        delete head;
    }

    void push_front(T val)
    {
        ListNode<T> *node = head;
        ListNode<T> *newHead = new ListNode<T>{val, nullptr, head};
        head->prev = newHead;
        head = newHead;

        if (!back)
        {
            back = head;
        }
    }

    void push_back(T val)
    {
        if (back)
        {
            ListNode<T> *node = back;
            ListNode<T> *newBack = new ListNode<T>{val, back};
            back->next = newBack;
            back = newBack;
        }
        else
        {
            head = new ListNode<T>{val};
            back = head;
        }
    }

private:
    ListNode<T> *head;
    ListNode<T> *back;
};

int main(int argc, char const *argv[])
{
    List<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);

    return 0;
}
