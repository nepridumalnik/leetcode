#pragma once

#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ListNode
{
public:
    ListNode() : val{0}, next{nullptr} {};
    ListNode(const int x) : val{x} {};
    ListNode(int x, ListNode *ptr) : val{x}, next{ptr} {};

    ListNode(const std::initializer_list<int> values)
        : val{0}, next{nullptr}
    {
        if (values.size() == 0)
        {
            return;
        }
        else if (values.size() == 1)
        {
            val = *values.begin();
            return;
        }

        auto it = values.begin();
        ListNode *current = this;
        current->val = *it;
        ++it;

        for (; it != values.end(); ++it)
        {
            int num = *it;
            current->next = new ListNode{num};
            current = current->next;
        }
    }

    ~ListNode() { delete next; }

public:
    int val;
    ListNode *next;
};

class TreeNode
{
public:
    TreeNode(int x = 0, TreeNode *left = nullptr, TreeNode *right = nullptr) : val{x}, left{left}, right{right} {}

    ~TreeNode()
    {
        delete left;
        delete right;
    }

public:
    int val;
    TreeNode *left;
    TreeNode *right;
};
