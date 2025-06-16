// LeetCode Problem No. 2016
// Daily Challenge - 16/06/2025

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSoFar = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minSoFar) {
                maxDiff = max(maxDiff, nums[i] - minSoFar);
            } else {
                minSoFar = nums[i]; 
            }
        }

        return maxDiff;
    }
};
