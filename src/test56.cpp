// https://leetcode.com/problems/reverse-linked-list

ListNode *reverseList(ListNode *head)
{
	ListNode *last = nullptr;

	while (head)
	{
		ListNode *next = head->next;
		head->next = last;
		last = head;
		head = next;
	}

	return last;
}

int main(int argc, char const *argv[])
{
	ListNode *node = new ListNode{1, 2, 3, 4, 5};

	node = reverseList(node);

	delete node;

	return 0;
}
