// LeetCode Problem No. 889
// Daily Challenge - 23/02/2025

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
    int pre_idx=0;
    int post_idx=0;
 
 public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* curr = new TreeNode(preorder[pre_idx]);
        pre_idx++;

        if(curr->val != postorder[post_idx])
            curr->left = constructFromPrePost(preorder,postorder);
        if(curr->val != postorder[post_idx])
            curr->right = constructFromPrePost(preorder,postorder);
        
        post_idx++;
        return curr;
    }
};