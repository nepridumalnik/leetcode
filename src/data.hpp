#pragma once

#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>

using namespace std;

struct ListNode
{
    int val;

    ListNode *next;

    ListNode() : val{0}, next{nullptr} {};
    ListNode(int x, ListNode *node = nullptr) : val{x}, next{node} {};
    ~ListNode() { delete next; }
};

struct TreeNode
{
    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x = 0, TreeNode *left = nullptr, TreeNode *right = nullptr) : val{x}, left{left}, right{right} {}

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};
