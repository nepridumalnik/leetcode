// https://leetcode.com/problems/merge-k-sorted-lists

ListNode *mergeKLists(vector<ListNode *> &lists)
{
	struct CompareNodes
	{
		bool operator()(const ListNode *a, const ListNode *b) const
		{
			return a->val < b->val;
		}
	};

	multiset<ListNode *, CompareNodes> nodeSet;

	for (ListNode *e : lists)
	{
		for (ListNode *node = e; node; node = node->next)
		{
			nodeSet.insert(node);
		}
	}

	if (nodeSet.empty())
	{
		return nullptr;
	}

	std::multiset<ListNode *, CompareNodes>::iterator it = nodeSet.begin();
	ListNode *prev = *it;

	++it;

	for (; it != nodeSet.end(); ++it)
	{
		prev->next = *it;
		prev = prev->next;
	}

	prev->next = nullptr;
	ListNode *node = *nodeSet.begin();

	return node;
}

vector<ListNode *> makeVector(const vector<vector<int>> &v)
{
	vector<ListNode *> lists;

	for (size_t i = 0; i < v.size(); ++i)
	{
		ListNode *head = new ListNode(v[i][0]);
		lists.push_back(head);

		for (size_t j = 1; j < v[i].size(); ++j)
		{
			ListNode *node = new ListNode(v[i][j]);
			head->next = node;
			head = head->next;
		}
	}

	return lists;
}

int main(int argc, char const *argv[])
{
	std::vector<ListNode *> v0;
	mergeKLists(v0);

	std::vector<ListNode *> v1 = makeVector({{1, 4, 5}, {1, 3, 4}, {2, 6}});
	ListNode *node = mergeKLists(v1);
	delete node;

	return 0;
}
