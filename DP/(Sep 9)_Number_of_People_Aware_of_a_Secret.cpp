// LeetCode Problem No. 2327
// Daily Challenge - 09/09/2025

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int MOD = 1e9+7;
        vector<int> dp(n+1);
        dp[1] = 1;
        int win_count = 0;
        for(int curr=2;curr<=n;++curr){
            if(curr-delay > 0)
                win_count = (win_count + dp[curr-delay]) % MOD;
            if(curr-forget > 0)
                win_count = (win_count - dp[curr-forget] + MOD) % MOD;
            
            dp[curr] = win_count;
        }
        int total = 0;
        for(int i=n-forget+1;i<=n;++i)
            total = (total + dp[i]) % MOD;
        
        return total;
    }
};