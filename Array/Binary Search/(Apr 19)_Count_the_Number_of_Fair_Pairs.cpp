// LeetCode Problem No. 2563
// Daily Challenge - 19/04/2025

class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(), nums.end());
            long long count = 0;
            int n = nums.size();
    
            for (int i = 0; i < n; ++i) {
                int left = lower - nums[i];
                int right = upper - nums[i];
                
                auto low = lower_bound(nums.begin() + i + 1, nums.end(), left);
                auto high = upper_bound(nums.begin() + i + 1, nums.end(), right);
                
                count += (high - low);
            }
    
            return count;
        }
};