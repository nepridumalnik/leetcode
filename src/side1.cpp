// Переворот односвязного списка

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
    ListNode *head = new ListNode{0, 1, 2, 3};
    head = RevertList(head);
    delete head;

    return 0;
}
