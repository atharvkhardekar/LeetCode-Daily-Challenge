// LeetCode Problem No. 3152
// Daily Challenge - 09/12/2024

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> parityChange(n, 0);
        for (int i = 1; i < n; ++i) {
            parityChange[i] = (nums[i] % 2) != (nums[i - 1] % 2) ? 0 : 1;
        }

        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + parityChange[i];
        }

        vector<bool> result;
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];
            
            int count = (from + 1 <= to) ? prefixSum[to] - prefixSum[from] : 0;
            result.push_back(count == 0);
        }
        return result;
    }
};