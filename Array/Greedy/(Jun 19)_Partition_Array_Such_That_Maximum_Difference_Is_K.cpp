// LeetCode Problem No. 2294
// Daily Challenge - 19/06/2025

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int subsequences = 1;
        int min_val = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] - min_val > k) {
                min_val = nums[i];
                subsequences++;
            }
        }

        return subsequences;
    }
};
