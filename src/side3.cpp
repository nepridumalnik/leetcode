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

int main(int argc, char const *argv[])
{
    TreeNode node{1, new TreeNode{4, new TreeNode{2}, new TreeNode{3, new TreeNode{2}}}, new TreeNode{7, new TreeNode{5}, new TreeNode{4}}};

    int highest = 0;
    GetHighestSum(&node, highest);

    return 0;
}
