// LeetCode Problem No. 494
// Daily Challenge - 26/12/2024

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum + target) % 2 != 0 || (totalSum + target) < 0) {
            return 0;
        }

        int posSum = (totalSum + target)/2;

        vector<int> dp(posSum + 1, 0);
        dp[0] = 1;

        for (int i : nums) {
            for (int j = posSum; j >= i; j--) {
                dp[j] += dp[j - i];
            }
        }
        return dp[posSum];
    }
};