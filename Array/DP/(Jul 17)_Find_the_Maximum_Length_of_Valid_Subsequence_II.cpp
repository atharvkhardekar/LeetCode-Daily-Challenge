// LeetCode Problem No. 3202
// Daily Challenge - 17/07/2025

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> length(k,vector<int>(k));
        int max_len = 0;

        for(int i=0; i<n; ++i){
            int curr = nums[i]%k;
            
            for(int prev=0; prev<k; ++prev){
                length[curr][prev] = length[prev][curr] + 1;
                max_len = max(max_len,length[curr][prev]);
            }
        }

        return max_len;
    }
};
