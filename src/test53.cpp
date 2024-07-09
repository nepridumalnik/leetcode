// https://leetcode.com/problems/merge-k-sorted-lists

ListNode *mergeKLists(vector<ListNode *> &lists)
{
	return nullptr;
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
	std::vector<ListNode *> v1 = makeVector({{1, 4, 5}, {1, 3, 4}, {2, 6}});

	return 0;
}
