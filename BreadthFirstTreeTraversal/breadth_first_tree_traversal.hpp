#pragma once

#include <vector>

// https://leetcode.com/problems/binary-tree-level-order-traversal/

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result(2000);
    helper(root, result);
    auto it = result.begin();
    for (; it != result.end(); ++it) {
      if ((*it).empty())
        break;
    }
    return vector<vector<int>>(result.begin(), it);
  }
  void helper(TreeNode *root, vector<vector<int>> &result, int level = 0) {
    if (root) {
      result[level].push_back(root->val);
      if (root->left) {
        helper(root->left, result, level + 1);
      }
      if (root->right) {
        helper(root->right, result, level + 1);
      }
    }
  }
};