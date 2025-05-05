// LeetCode Problem No. 790
// Daily Challenge - 05/05/2025

class Solution {
    public:
        int numTilings(int n) {
            const int MOD = 1e9 + 7;
            vector<long long> dp(n + 1);
            dp[0] = 1;
            if (n >= 1) dp[1] = 1;
            if (n >= 2) dp[2] = 2;
            
            long long sum = dp[0]; 
            
            for (int i = 3; i <= n; ++i) {
                dp[i] = (dp[i - 1] + dp[i - 2] + 2 * sum) % MOD;
                sum = (sum + dp[i - 2]) % MOD;
            }
    
            return dp[n];
        }
};
