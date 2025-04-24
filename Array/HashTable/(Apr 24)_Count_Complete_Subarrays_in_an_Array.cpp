// LeetCode Problem No. 2799
// Daily Challenge - 24/04/2025

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_set<int> allDistinct(nums.begin(), nums.end());
            int totalDistinct = allDistinct.size();
            
            int n = nums.size();
            int count = 0;
            
            for (int i = 0; i < n; ++i) {
                unordered_set<int> subarraySet;
                for (int j = i; j < n; ++j) {
                    subarraySet.insert(nums[j]);
                    if (subarraySet.size() == totalDistinct) {
                        count++;
                    }
                }
            }
            
            return count;
        }
};    