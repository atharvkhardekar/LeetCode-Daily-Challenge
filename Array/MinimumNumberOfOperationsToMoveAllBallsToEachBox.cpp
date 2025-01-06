// LeetCode Problem No. 1769
// Daily Challenge - 06/01/2025

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int balls = 0, operations = 0;
        
        for (int i = 0; i < n; ++i) {
            ans[i] += operations;
            balls += boxes[i] - '0'; 
            operations += balls;   
        }
        
        balls = 0;
        operations = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] += operations;
            balls += boxes[i] - '0'; 
            operations += balls;  
        }
        return ans;
    }
};
