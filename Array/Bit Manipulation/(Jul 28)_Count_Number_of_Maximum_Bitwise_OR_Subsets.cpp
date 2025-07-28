// LeetCode Problem No. 2044
// Daily Challenge - 28/07/2025

class Solution {
    int solve(vector<int>& nums, int idx, int currOR, const int& maxOR, vector<vector<int>>& mem) {
        if (idx >= nums.size()) {
            return currOR == maxOR;
        }

        if (mem[idx][currOR] != -1) {
            return mem[idx][currOR];
        }

        int exclude = solve(nums, idx + 1, currOR, maxOR, mem);
        int include = solve(nums, idx + 1, currOR | nums[idx], maxOR, mem);

        return mem[idx][currOR] = exclude + include;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;

        for (int& ele : nums) {
            maxOR |= ele;
        }

        vector<vector<int>> mem(n, vector<int>(maxOR + 1, -1));
        return solve(nums, 0, 0, maxOR, mem);
    }
};
