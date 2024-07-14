// https://leetcode.com/problems/swap-nodes-in-pairs

ListNode *swapPairs(ListNode *head)
{
	if (!head)
	{
		return nullptr;
	}

	ListNode node;
	node.next = head;
	ListNode *ptr = &node;

	while (ptr && ptr->next && ptr->next->next)
	{
		ListNode *a = ptr->next;
		ListNode *b = ptr->next->next;
		ListNode *next = b->next;

		ptr->next = b;
		b->next = a;
		a->next = next;

		ptr = a;
	}

	head = node.next;
	node.next = nullptr;

	return head;
}

void runTest(initializer_list<int> il)
{
	std::unique_ptr<ListNode> list = make_unique<ListNode>(il);
	list = std::unique_ptr<ListNode>{swapPairs(list.get())};
	list.release();
}

int main(int argc, char const *argv[])
{
	runTest({1, 2, 3, 4});
	runTest({1});
	runTest({});

	return 0;
}
