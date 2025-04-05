// LeetCode Problem No. 1863
// Daily Challenge - 05/04/2025

class Solution {
    public:
       int subsetXORSum(vector<int>& nums) {
           return dfs(nums, 0, 0);
       }
   
    private:
       int dfs(const vector<int>& nums, int index, int currentXor) {
           if (index == nums.size()) {
               return currentXor;
           }
           
           int include = dfs(nums, index + 1, currentXor ^ nums[index]);
          
           int exclude = dfs(nums, index + 1, currentXor);
           return include + exclude;
       }
};