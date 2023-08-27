// https://leetcode.com/problems/merge-two-sorted-lists

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1 && !list2)
    {
        return nullptr;
    }
    else if (!list1)
    {
        return list2;
    }
    else if (!list2)
    {
        return list1;
    }

    ListNode root{};
    ListNode *temp = &root;

    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if (!list1)
    {
        temp->next = list2;
    }
    else
    {
        temp->next = list1;
    }

    ListNode *result = root.next;
    root.next = nullptr;

    return result;
}

int main(int argc, char const *argv[])
{
    ListNode *list1 = new ListNode{1, new ListNode{2, new ListNode{4}}};
    ListNode *list2 = new ListNode{1, new ListNode{3, new ListNode{4}}};
    ListNode *list = mergeTwoLists(list1, list2);

    delete list;

    return 0;
}
