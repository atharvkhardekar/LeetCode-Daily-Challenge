// LeetCode Problem No. 2210
// Daily Challenge - 27/07/2025

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        vector<int> clean;
        clean.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                clean.push_back(nums[i]);
            }
        }

        for (int i = 1; i < clean.size() - 1; ++i) {
            if (clean[i] > clean[i - 1] && clean[i] > clean[i + 1]) {
                count++; 
            } else if (clean[i] < clean[i - 1] && clean[i] < clean[i + 1]) {
                count++; 
            }
        }

        return count;
    }
};
