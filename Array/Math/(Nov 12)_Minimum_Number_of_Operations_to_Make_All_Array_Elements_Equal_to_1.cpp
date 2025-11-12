// LeetCode Problem No. 2654
// Daily Challenge - 12/11/2025

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);

        if (ones > 0)
            return n - ones;

        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break; 
                }
            }
        }

        if (minLen == INT_MAX)
            return -1; 

        return (minLen - 1) + (n - 1);
    }
};
