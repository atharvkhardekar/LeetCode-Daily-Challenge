// LeetCode Problem No. 3573
// Daily Challenge - 17/12/2025

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = -1e18;

        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;

        for (int price : prices) {
            vector<vector<long long>> ndp = dp;

            for (int t = 0; t <= k; t++) {
                if (dp[t][0] != NEG) {
                    ndp[t][1] = max(ndp[t][1], dp[t][0] - price);
                    ndp[t][2] = max(ndp[t][2], dp[t][0] + price);
                }

                if (dp[t][1] != NEG && t + 1 <= k) {
                    ndp[t + 1][0] = max(ndp[t + 1][0], dp[t][1] + price);
                }

                if (dp[t][2] != NEG && t + 1 <= k) {
                    ndp[t + 1][0] = max(ndp[t + 1][0], dp[t][2] - price);
                }
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for (int t = 0; t <= k; t++) {
            ans = max(ans, dp[t][0]);  
        }
        return ans;
    }
};
