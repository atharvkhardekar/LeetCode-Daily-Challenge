// LeetCode Problem No. 368
// Daily Challenge - 06/04/2025

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            if (nums.empty()) return {};
            
            int n = nums.size();
            sort(nums.begin(), nums.end());
    
            vector<int> dp(n, 1);    
            vector<int> prev(n, -1);    
            int maxSize = 1, maxIndex = 0;
    
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if (dp[i] > maxSize) {
                    maxSize = dp[i];
                    maxIndex = i;
                }
            }
    
            vector<int> result;
            int k = maxIndex;
            while (k >= 0) {
                result.push_back(nums[k]);
                k = prev[k];
            }
    
            reverse(result.begin(), result.end());
            return result;
        }
};  