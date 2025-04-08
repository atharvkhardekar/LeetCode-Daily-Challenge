// LeetCode Problem No. 3396
// Daily Challenge - 08/04/2025

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int operations = 0;
    
            while (true) {
                unordered_set<int> s(nums.begin(), nums.end());
                if (s.size() == nums.size()) {
                    break;
                }
    
                int removeCount = min(3, (int)nums.size());
                nums.erase(nums.begin(), nums.begin() + removeCount);
    
                operations++;
            }
    
            return operations;
        }
};
    