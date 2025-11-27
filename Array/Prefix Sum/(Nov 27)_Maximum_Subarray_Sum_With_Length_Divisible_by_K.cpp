// LeetCode Problem No. 3381
// Daily Challenge - 27/11/2025

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPref(k, LLONG_MAX);  
        
        long long pref = 0;
        minPref[0] = 0;  
        
        long long ans = LLONG_MIN;
        
        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int mod = (i + 1) % k;
            
            if (minPref[mod] != LLONG_MAX) {
                ans = max(ans, pref - minPref[mod]);
            }
            
            minPref[mod] = min(minPref[mod], pref);
        }
        return ans;
    }
};