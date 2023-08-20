// https://www.youtube.com/watch?v=R4UHOLZ-bEk

void GetHighestSum(TreeNode *node, int &highest, int sum = 0)
{
    if (!node)
    {
        return;
    }

    sum += node->val;

    if (!node->left && !node->right)
    {
        if (sum > highest)
        {
            highest = sum;
        }
    }

    GetHighestSum(node->left, highest, sum);
    GetHighestSum(node->right, highest, sum);
}

int GetHighestSumStack(TreeNode *root)
{
    int highest = 0;

    stack<pair<TreeNode *, int>> nodes;
    nodes.push({root, 0});

    while (!nodes.empty())
    {
        TreeNode *node = nodes.top().first;
        int sum = nodes.top().second + node->val;
        nodes.pop();

        if (!node->left && !node->right)
        {
            if (sum > highest)
            {
                highest = sum;
            }
        }

        if (node->left)
        {
            nodes.push({node->left, sum});
        }
        if (node->right)
        {
            nodes.push({node->right, sum});
        }
    }

    return highest;
}

int main(int argc, char const *argv[])
{
    TreeNode node{1, new TreeNode{4, new TreeNode{2}, new TreeNode{3, new TreeNode{2}}}, new TreeNode{7, new TreeNode{5}, new TreeNode{4}}};

    int highest = 0;
    GetHighestSum(&node, highest);
    int highestWithStack = GetHighestSumStack(&node);

    if (highest != highestWithStack)
    {
        return -1;
    }

    return 0;
}
