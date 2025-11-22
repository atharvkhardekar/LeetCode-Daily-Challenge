// LeetCode Problem No. 3190
// Daily Challenge - 22/11/2025

class Solution{
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 3 != 0) {
                operations++;
            }
        }
        return operations;
    }
};