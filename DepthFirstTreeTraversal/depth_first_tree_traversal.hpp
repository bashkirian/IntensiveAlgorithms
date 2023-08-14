#pragma once

#include <cstddef>
#include <vector>

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, vector<int>> node_adj;
    vector<int> vertices;
    unordered_set<int> visited;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, root->left);
        dfs(root, root->right);  
        neighbors(target->val, k);
        return vertices;     
    }

    void dfs(TreeNode* parent, TreeNode* child) {
        if (parent == NULL || child == NULL) return;
        node_adj[parent->val].push_back(child->val);
        node_adj[child->val].push_back(parent->val);
        dfs(child, child->left);
        dfs(child, child->right);
    }

    void neighbors(int val, int distance) {
        if (visited.count(val)) {
            return;
        }
        visited.insert(val);
        if (distance == 0) {
            vertices.push_back(val);
            return;
        }
        else {
            for (auto neighbor : node_adj[val]) {
                neighbors(neighbor, distance - 1);
            }
        }
    }
};