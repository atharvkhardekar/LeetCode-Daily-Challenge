// LeetCode Problem No. 3375
// Daily Challenge - 09/04/2025

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            for (int num : nums) {
                if (num < k) return -1;
            }
    
            sort(nums.begin(), nums.end(), greater<int>());
    
            unordered_set<int> seen;
            for (int num : nums) {
                if (num > k) {
                    seen.insert(num);
                }
            }
    
            return seen.size();
        }
};
    