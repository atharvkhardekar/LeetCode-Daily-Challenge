// LeetCode Problem No. 2874
// Daily Challenge - 03/04/2025

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long result = 0;
            
            vector<int> max_suffix(n, 0);
            max_suffix[n-1] = nums[n-1];
            for (int i = n - 2; i >= 0; --i) {
                max_suffix[i] = max(max_suffix[i + 1], nums[i]);
            }
            
            int max_i = nums[0];
            for (int j = 1; j < n - 1; ++j) {
                if (max_i > nums[j]) {
                    result = max(result, (long long)(max_i - nums[j]) * max_suffix[j + 1]);
                }
                max_i = max(max_i, nums[j]);
            }
            
            return result;
        }
};