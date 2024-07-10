// https://leetcode.com/problems/add-two-numbers

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    auto listToNum = [](const ListNode *head) -> long long
    {
        size_t multiplier = 1;
        long long num = 0;

        for (const ListNode *current = head; current; current = current->next)
        {
            num += current->val * multiplier;
            multiplier *= 10;
        }

        return num;
    };

    long long a = listToNum(l1);
    long long b = listToNum(l2);
    long long result = a + b;

    ListNode *node = new ListNode;

    if (result)
    {
        ListNode *current = node;

        while (result)
        {
            current->val = result % 10;
            result /= 10;

            if (result)
            {
                current->next = new ListNode;
                current = current->next;
            }
        }
    }
    else
    {
        node->val = result;
    }

    return node;
}

// TODO: Добавить сложение списков напрямую, а не при помощи чисел
int main(int argc, char const *argv[])
{
    {
        ListNode a{9};
        ListNode b{1, 9, 9, 9, 9, 9, 9, 9, 9, 9};
        unique_ptr<ListNode> result;

        result = unique_ptr<ListNode>(addTwoNumbers(&a, &b));
    }
    {
        ListNode a{2, 4, 3};
        ListNode b{5, 6, 4};
        unique_ptr<ListNode> result;

        result = unique_ptr<ListNode>(addTwoNumbers(&a, &b));
    }

    return 0;
}
