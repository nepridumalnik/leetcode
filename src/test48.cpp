// https://leetcode.com/problems/maximum-depth-of-binary-tree

// int maxDepth(TreeNode *root)
// {
// 	struct Depth
// 	{
// 		TreeNode *node;
// 		size_t depth;
// 	};

// 	if (!root)
// 	{
// 		return 0;
// 	}

// 	std::stack<Depth> st;
// 	size_t maxDepth = 0;

// 	st.push({root, 1});

// 	while (!st.empty())
// 	{
// 		Depth node = st.top();
// 		st.pop();

// 		if (node.node->left)
// 		{
// 			st.push({node.node->left, node.depth + 1});
// 		}
// 		if (node.node->right)
// 		{
// 			st.push({node.node->right, node.depth + 1});
// 		}
// 		if (node.depth > maxDepth)
// 		{
// 			maxDepth = node.depth;
// 		}
// 	}

// 	return maxDepth;
// }

int maxDepth(TreeNode *root)
{
	if (!root)
	{
		return 0;
	}

	int left = maxDepth(root->left);
	int right = maxDepth(root->right);

	return std::max(left, right) + 1;
}

int main(int argc, char const *argv[])
{
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;

	{
		TreeNode *left = new TreeNode{9};
		TreeNode *right = new TreeNode{20, new TreeNode{15}, new TreeNode{7}};
		TreeNode node{3, left, right};

		result1 = maxDepth(&node);
	}
	{
		TreeNode node{1, nullptr, new TreeNode{2}};

		result2 = maxDepth(&node);
	}
	{
		TreeNode node{1, new TreeNode{2}};

		result3 = maxDepth(&node);
	}

	return 0;
}
