// LeetCode Problem No. 2873
// Daily Challenge - 02/04/2025

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long result = 0;
          
            vector<int> prefixMax(n, 0);
            prefixMax[0] = nums[0];
            for (int i = 1; i < n; ++i) {
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            }
           
            vector<int> suffixMax(n, 0);
            suffixMax[n - 1] = nums[n - 1];
            for (int k = n - 2; k >= 0; --k) {
                suffixMax[k] = max(suffixMax[k + 1], nums[k]);
            }
         
            for (int j = 1; j < n - 1; ++j) {
                if (prefixMax[j - 1] > nums[j] && suffixMax[j + 1] > 0) {
                    result = max(result, (long long)(prefixMax[j - 1] - nums[j]) * suffixMax[j + 1]);
                }
            }
            
            return result;
        }
};