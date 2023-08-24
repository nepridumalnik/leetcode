// Своя реализация двусвязного списка

template <typename T>
struct CustomListNode
{
    T val;
    CustomListNode *next;
    CustomListNode *prev;

    CustomListNode() : val{0}, next{nullptr} {};
    CustomListNode(int x, CustomListNode *prev = nullptr, CustomListNode *next = nullptr) : val{x}, prev{prev}, next{next} {};
    ~CustomListNode() { delete next; }
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
        CustomListNode<T> *node = head;
        CustomListNode<T> *newHead = new CustomListNode<T>{val, nullptr, head};
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
            CustomListNode<T> *node = back;
            CustomListNode<T> *newBack = new CustomListNode<T>{val, back};
            back->next = newBack;
            back = newBack;
        }
        else
        {
            head = new CustomListNode<T>{val};
            back = head;
        }
    }

private:
    CustomListNode<T> *head;
    CustomListNode<T> *back;
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
