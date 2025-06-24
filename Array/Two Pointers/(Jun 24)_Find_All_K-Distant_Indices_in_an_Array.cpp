// LeetCode Problem No. 2200
// Daily Challenge - 24/06/2025

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> result;
        int n = nums.size();
      
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for (int j = start; j <= end; ++j) {
                    result.insert(j);
                }
            }
        }
   
        return vector<int>(result.begin(), result.end());
    }
};
