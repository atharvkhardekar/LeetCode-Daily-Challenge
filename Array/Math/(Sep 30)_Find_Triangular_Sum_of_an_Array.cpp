// LeetCode Problem No. 2221
// Daily Challenge - 30/09/2025

class Solution {
public:
    int triangularSum(std::vector<int>& nums) {
        int n = nums.size();
        
        for (int current_size = n; current_size > 1; --current_size) {
            for (int i = 0; i < current_size - 1; ++i) {
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
        }

        return nums[0];
    }
};
