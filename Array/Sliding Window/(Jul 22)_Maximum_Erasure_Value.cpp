// LeetCode Problem No. 1695
// Daily Challenge - 22/07/2025

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        unordered_map<int, bool> val_idx;

        int max_sum = INT_MIN;
        int win_sum = 0;

        while (right < n) {
            if (val_idx.count(nums[right])) {
                val_idx.erase(nums[left]);
                win_sum -= nums[left];
                left++;
            } else {
                win_sum += nums[right];
                val_idx[nums[right]] = true;
                right++;
                max_sum = max(max_sum, win_sum);
            }
        }

        return max_sum;
    }
};