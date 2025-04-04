// LeetCode Problem No. 1123
// Daily Challenge - 04/04/2025

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    public:
        
        pair<int, TreeNode*> dfs(TreeNode* node) {
            if (!node) return {0, nullptr};
    
            auto left = dfs(node->left);
            auto right = dfs(node->right);
    
            if (left.first == right.first) {
                return {left.first + 1, node};
            } else if (left.first > right.first) {
                return {left.first + 1, left.second};
            } else {
                return {right.first + 1, right.second};
            }
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return dfs(root).second;
        }
};