// https://leetcode.com/problems/symmetric-tree/

bool isSymmetric(TreeNode *left, TreeNode *right)
{
    if (!left && !right)
    {
        return true;
    }

    if (!left || !right)
    {
        return false;
    }

    if (left->val != right->val)
    {
        return false;
    }

    if (!isSymmetric(left->left, right->right))
    {
        return false;
    }

    return isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    return isSymmetric(root->left, root->right);
}

int main(int argc, char const *argv[])
{
    bool res0 = false;

    {
        TreeNode node{1, new TreeNode{2, new TreeNode{3}, new TreeNode{4}}, new TreeNode{2, new TreeNode{4}, new TreeNode{3}}};
        res0 = isSymmetric(&node);
    }

    return 0;
}
