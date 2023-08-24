// https://leetcode.com/problems/reverse-linked-list

ListNode *reverseList(ListNode *head)
{
    ListNode *current = head;
    ListNode *prev = nullptr;

    while (current)
    {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main(int argc, char const *argv[])
{
    ListNode *res0 = new ListNode{0, new ListNode{1, new ListNode{2, new ListNode{3, new ListNode{4, new ListNode{5}}}}}};
    ListNode *res1 = new ListNode{1, new ListNode{2}};

    res0 = reverseList(res0);
    res1 = reverseList(res1);

    delete res0;
    delete res1;

    return 0;
}
