// https://leetcode.com/problems/add-two-numbers

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode *result = new ListNode;
	ListNode *ptr = result;
	ListNode *current1 = l1;
	ListNode *current2 = l2;

	int remain = 0;

	while (current1 || current2)
	{
		int num = remain;
		if (current1)
		{
			num += current1->val;
		}
		if (current2)
		{
			num += current2->val;
		}

		if (num >= 10)
		{
			num -= 10;
			remain = 1;
		}
		else
		{
			remain = 0;
		}

		ptr->val = num;
		if (current1)
		{
			current1 = current1->next;
		}
		if (current2)
		{
			current2 = current2->next;
		}

		if (current1 || current2)
		{
			ptr->next = new ListNode;
			ptr = ptr->next;
		}
	}

	if (remain)
	{
		ptr->next = new ListNode{remain};
	}

	return result;
}

unique_ptr<ListNode> addNumbers(ListNode *l1, ListNode *l2)
{
	return unique_ptr<ListNode>{addTwoNumbers(l1, l2)};
}

// TODO: Добавить сложение списков напрямую, а не при помощи чисел
int main(int argc, char const *argv[])
{
	{
		ListNode a{9};
		ListNode b{1, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		unique_ptr<ListNode> result;

		result = addNumbers(&a, &b);
	}
	{
		ListNode a{2, 4, 3};
		ListNode b{5, 6, 4};
		unique_ptr<ListNode> result; // 7, 0, 8

		result = addNumbers(&a, &b);
	}
	{
		ListNode a{0};
		ListNode b{0};
		unique_ptr<ListNode> result; // 0

		result = addNumbers(&a, &b);
	}
	{
		ListNode a{9, 9, 9, 9, 9, 9, 9};
		ListNode b{9, 9, 9, 9};
		unique_ptr<ListNode> result; // 8, 9, 9, 9, 0, 0, 0, 1

		result = addNumbers(&a, &b);
	}

	return 0;
}
