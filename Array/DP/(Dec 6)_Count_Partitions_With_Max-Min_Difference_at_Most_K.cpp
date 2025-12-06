// LeetCode Problem No. 3578
// Daily Challenge - 06/12/2025

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0), pref(n + 1, 0);
        dp[0] = pref[0] = 1;

        deque<int> maxdq, mindq;
        int left = 0;

        for (int right = 0; right < n; right++) {

            while (!maxdq.empty() && nums[maxdq.back()] <= nums[right])
                maxdq.pop_back();
            maxdq.push_back(right);

            while (!mindq.empty() && nums[mindq.back()] >= nums[right])
                mindq.pop_back();
            mindq.push_back(right);

            while (nums[maxdq.front()] - nums[mindq.front()] > k) {
                if (maxdq.front() == left) maxdq.pop_front();
                if (mindq.front() == left) mindq.pop_front();
                left++;
            }

            long long total = pref[right];
            long long subtract = (left > 0 ? pref[left - 1] : 0);

            dp[right + 1] = (total - subtract + MOD) % MOD;
            pref[right + 1] = (pref[right] + dp[right + 1]) % MOD;
        }

        return dp[n];
    }
};