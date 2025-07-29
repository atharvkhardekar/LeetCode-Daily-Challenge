// LeetCode Problem No. 2411
// Daily Challenge - 29/07/2025

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxval = *max_element(nums.begin(), nums.end());
        int bits = maxval == 0 ? 0 : 1 + log2(maxval);

        vector<int> nearest_setbit(bits, n);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i) {
            int nearest = i;
            for (int j = 0; j < bits; ++j) {
                if (nums[i] & (1 << j)) {
                    nearest_setbit[j] = i;
                } else if (nearest_setbit[j] != n) {
                    nearest = max(nearest, nearest_setbit[j]);
                }
            }
            ans[i] = nearest - i + 1;
        }

        return ans;
    }
};
