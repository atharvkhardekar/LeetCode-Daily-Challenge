// LeetCode Problem No. 3355
// Daily Challenge - 20/05/2025

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(auto& query: queries){
            int start = query[0];
            int end = query[1];
            diff[start]++;
            diff[end+1]--;
        }
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=diff[i];
            if(sum<nums[i])
                return false;
        }
        return true;
    }
};