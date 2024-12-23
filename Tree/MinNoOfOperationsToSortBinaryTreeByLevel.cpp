// LeetCode Problem No. 2471
// Daily Challenge - 23/12/2024

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
    int calculateMinimumSwaps(vector<int>& levelValues) {
        int totalSwaps = 0;

        map<int, int> valueToIndexMap;
        int n = levelValues.size();
        for (int i = 0; i < n; ++i)
            valueToIndexMap[levelValues[i]] = i;

        sort(levelValues.begin(), levelValues.end());

        vector<bool> processed(n, false); 
        int currentIndex = 0; 

        for (auto& [value, index] : valueToIndexMap) {
            if (processed[index]) { 
                currentIndex++;
                continue;
            }

            processed[index] = true;
            int cycleLength = 1; 

            while (index != currentIndex) {
                index = valueToIndexMap[levelValues[index]];
                processed[index] = true;
                cycleLength++;
            }

            totalSwaps += cycleLength - 1; 
            currentIndex++;
        }

        return totalSwaps;
    }

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int totalSwaps = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();

                levelValues.push_back(currentNode->val);
                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }

            totalSwaps += calculateMinimumSwaps(levelValues);
        }
        return totalSwaps;
    }
};