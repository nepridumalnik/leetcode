// https://www.youtube.com/watch?v=R4UHOLZ-bEk

void GetHighestSum(TreeNode *node, int &sum, int &highest)
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

    GetHighestSum(node->left, sum, highest);
    GetHighestSum(node->right, sum, highest);

    sum -= node->val;
}

int main(int argc, char const *argv[])
{
    TreeNode node{1, new TreeNode{4, new TreeNode{2}, new TreeNode{3, new TreeNode{2}}}, new TreeNode{7, new TreeNode{5}, new TreeNode{4}}};

    int sum = 0;
    int highest = sum;

    GetHighestSum(&node, sum, highest);

    return 0;
}
