// https://leetcode.com/problems/reverse-linked-list-ii

// TODO: пререшать
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left >= right || !head)
    {
        return head;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    for (int i = 1; i < left; ++i)
    {
        prev = prev->next;
    }

    ListNode *current = prev->next;
    ListNode *next = current->next;

    for (int i = 0; i < right - left; ++i)
    {
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = current->next;
    }

    return dummy.next;
}

int main(int argc, char const *argv[])
{
    ListNode *node1 = new ListNode{1, 2, 3, 4, 5};
    ListNode *node2 = new ListNode{5};

    node1 = reverseBetween(node1, 2, 4);
    node2 = reverseBetween(node2, 1, 1);

    delete node1;
    delete node2;

    return 0;
}
