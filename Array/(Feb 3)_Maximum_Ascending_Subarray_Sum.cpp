// LeetCode Problem No. 1800
// Daily Challenge - 04/02/2025

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0, currSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currSum += nums[i];  
            } else {
                maxSum = max(maxSum, currSum);
                currSum = nums[i];  
            }
        }
        return max(maxSum, currSum);  
    }
};