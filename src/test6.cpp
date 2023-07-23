// https://leetcode.com/problems/symmetric-tree

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

bool loopIsSimmetric(TreeNode *root)
{
    vector<TreeNode *> nodesQueue;
    nodesQueue.reserve(15);
    nodesQueue.push_back(root->left);
    nodesQueue.push_back(root->right);

    while (!nodesQueue.empty())
    {
        auto node1 = nodesQueue.back();
        nodesQueue.pop_back();
        auto node2 = nodesQueue.back();
        nodesQueue.pop_back();

        if (!node1 && !node2)
        {
            continue;
        }

        if (!node1 || !node2)
        {
            return false;
        }

        if (node1->val != node2->val)
        {
            return false;
        }

        if (node1->left || node2->right)
        {
            nodesQueue.push_back(node1->left);
            nodesQueue.push_back(node2->right);
        }

        if (node2->left || node1->right)
        {
            nodesQueue.push_back(node2->left);
            nodesQueue.push_back(node1->right);
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    bool res0 = false; // true
    bool res1 = false; // true
    bool res2 = false; // false
    bool res3 = false; // false

    {
        TreeNode node{1, new TreeNode{2, new TreeNode{3}, new TreeNode{4}}, new TreeNode{2, new TreeNode{4}, new TreeNode{3}}};
        res0 = isSymmetric(&node);
    }
    {
        TreeNode node{1, new TreeNode{2, new TreeNode{3}, new TreeNode{4}}, new TreeNode{2, new TreeNode{4}, new TreeNode{3}}};
        res1 = loopIsSimmetric(&node);
    }
    {
        TreeNode node{1, new TreeNode{2, new TreeNode{3}, new TreeNode{4}}, new TreeNode{2, new TreeNode{5}, new TreeNode{3}}};
        res2 = loopIsSimmetric(&node);
    }
    {
        TreeNode node{1, new TreeNode{2, new TreeNode{3}, new TreeNode{4}}, new TreeNode{2, nullptr, new TreeNode{3}}};
        res3 = loopIsSimmetric(&node);
    }

    return 0;
}
