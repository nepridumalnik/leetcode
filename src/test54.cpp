// https://leetcode.com/problems/linked-list-cycle

bool hasCycle(ListNode *head)
{
	if (!head)
	{
		return false;
	}

	ListNode *first = head;
	ListNode *second = head->next;

	while (first && second)
	{
		if (first == second)
		{
			return true;
		}

		first = first->next;

		second = second->next;
		if (second)
		{
			second = second->next;
		}
	}

	return false;
}

int main(int argc, char const *argv[])
{
	ListNode *lastNode = new ListNode{4};
	ListNode *secondNode = new ListNode{2, new ListNode{0, lastNode}};
	lastNode->next = secondNode;
	ListNode head{3, secondNode};

	bool result = hasCycle(&head);
	lastNode->next = nullptr;

	return 0;
}
