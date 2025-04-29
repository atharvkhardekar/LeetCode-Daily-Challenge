// LeetCode Problem No. 2962
// Daily Challenge - 29/04/2025

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            int maxVal = *max_element(nums.begin(), nums.end());
            long long result = 0;
            int left = 0, count = 0;
    
            for (int right = 0; right < n; ++right) {
                if (nums[right] == maxVal) {
                    count++;
                }
    
                while (count >= k) {
                    if (nums[left] == maxVal) {
                        count--;
                    }
                    left++;
                }
    
                result += left;
            }
    
            return result;
        }
};
    