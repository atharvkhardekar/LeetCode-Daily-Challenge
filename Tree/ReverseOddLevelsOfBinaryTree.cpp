// LeetCode Problem No. 2415
// Daily Challenge - 20/12/2024


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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int currentLevel = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<TreeNode*> currentLevelNodes;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currentLevelNodes.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (currentLevel % 2 == 1) { // Odd level
                int n = currentLevelNodes.size();
                for (int j = 0; j < n / 2; ++j)
                    swap(currentLevelNodes[j]->val, currentLevelNodes[n - j - 1]->val);
            }
            currentLevel++;
        }
        return root;
    }
};
