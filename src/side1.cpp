// Переворот односвязного списка

struct ListNode
{
    int val;

    ListNode *next;

    ListNode() : val{0}, next{nullptr} {};
    ListNode(int x, ListNode *node = nullptr) : val{x}, next{node} {};
    ~ListNode() { delete next; }
};

ListNode *RevertList(ListNode *head)
{
    // Запоминаем начало списка
    ListNode *current = head;
    // Запоминаем предыдущий узел
    ListNode *prev = nullptr;

    // Пока current не равен nullptr
    while (current)
    {
        // Берём следующий узел
        ListNode *next = current->next;
        // Присваиваем следующему узлу адрес предыдущего
        current->next = prev;
        // Смещаем указатель на следующий узел на текущий
        prev = current;
        // Смещаем указатель на текущий узел на запомненный следующий
        current = next;
    }

    return prev;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode{0, new ListNode{1, new ListNode{2, new ListNode{3}}}};
    head = RevertList(head);
    delete head;

    return 0;
}
