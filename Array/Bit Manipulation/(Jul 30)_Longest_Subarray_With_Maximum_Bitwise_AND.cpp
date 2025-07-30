// LeetCode Problem No. 2419
// Daily Challenge - 30/07/2025

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_value = *max_element(nums.begin(),nums.end());
        
        int max_len = 0;
        int curr_len = 0;
        for(int i=0; i<n; ++i){
            if(nums[i] == max_value){
                curr_len++;
                if(max_len < curr_len)
                    max_len = curr_len;
            }else{
                curr_len = 0;
            }
        }
        return max_len;
    }
};