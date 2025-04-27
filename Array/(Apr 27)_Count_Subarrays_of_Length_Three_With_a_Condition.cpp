// LeetCode Problem No. 3392
// Daily Challenge - 27/04/2025

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int count = 0;
            int n = nums.size();
            
            for (int i = 0; i <= n - 3; ++i) {
                int first = nums[i];
                int second = nums[i + 1];
                int third = nums[i + 2];
                
                if (second % 2 == 0 && first + third == second / 2) {
                    count++;
                }
            }
            
            return count;
        }
};
