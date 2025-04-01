// LeetCode Problem No. 2140
// Daily Challenge - 01/04/2025

class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n + 1, 0); 
            
            for (int i = n - 1; i >= 0; --i) {
                int points = questions[i][0];
                int brainpower = questions[i][1];
                
                int nextIndex = i + brainpower + 1;
                long long take = points + (nextIndex < n ? dp[nextIndex] : 0);
                
                long long skip = dp[i + 1];
                
                dp[i] = max(take, skip);
            }
            
            return dp[0]; 
        }
};