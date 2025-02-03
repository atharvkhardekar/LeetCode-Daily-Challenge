// LeetCode Problem No. 3105
// Daily Challenge - 03/02/2025

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int incLen = 1, decLen = 1, maxLen = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incLen++;
                decLen = 1; 
            } else if (nums[i] < nums[i - 1]) {
                decLen++;
                incLen = 1;
            } else {
                incLen = decLen = 1; 
            }
            maxLen = max(maxLen, max(incLen, decLen));
        }
        return maxLen;
    }
};
