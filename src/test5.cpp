// https://leetcode.com/problems/same-tree/

bool isSameTree(TreeNode *p, TreeNode *q)
{
    std::stack<TreeNode *> nodesQueue;
    nodesQueue.push(p);
    nodesQueue.push(q);

    while (!nodesQueue.empty())
    {
        auto node1 = nodesQueue.top();
        nodesQueue.pop();
        auto node2 = nodesQueue.top();
        nodesQueue.pop();

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

        nodesQueue.push(node1->left);
        nodesQueue.push(node2->left);

        nodesQueue.push(node1->right);
        nodesQueue.push(node2->right);
    }

    return true;
}

int main(int argc, char const *argv[])
{
    bool res0 = false;
    bool res1 = false;
    bool res2 = false;

    {
        TreeNode t1{1, new TreeNode{2}, new TreeNode{3}};
        TreeNode t2{1, new TreeNode{2}, new TreeNode{3}};

        res0 = isSameTree(&t1, &t2);
    }
    {
        TreeNode t1{1, new TreeNode{2}, nullptr};
        TreeNode t2{1, nullptr, new TreeNode{2}};

        res1 = isSameTree(&t1, &t2);
    }
    {
        TreeNode t1{1, new TreeNode{2}, new TreeNode{1}};
        TreeNode t2{1, new TreeNode{1}, new TreeNode{2}};

        res2 = isSameTree(&t1, &t2);
    }

    return 0;
}
