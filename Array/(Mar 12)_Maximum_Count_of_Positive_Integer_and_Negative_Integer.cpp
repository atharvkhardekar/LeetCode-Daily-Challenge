// LeetCode Problem No. 2529
// Daily Challenge - 12/03/2025

class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int maxCnt = 0, pos = 0, neg = 0;
    
            for(int i=0; i<nums.size(); i++){
                if(nums[i]<0) neg++;
    
                if(nums[i]>0) pos++;
            }
    
            maxCnt = max(pos, neg);
            return maxCnt;
        }
    };