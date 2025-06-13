// LeetCode Problem No. 2616
// Daily Challenge - 13/06/2025

class Solution {
    bool isPossible(vector<int>& nums,const int& val,const int& p){
        int count = 0;
        int i=1;
        while(i<nums.size()){
            if(nums[i]-nums[i-1] <= val){
                count++;
                i+=2;
            }else{
                i++;
            }
        }
        return count>=p;
    }
    
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low = 0, high = nums.back(), mid;
        int ans = INT_MAX;
        while(low<=high){
            mid = low + (high-low)/2;
            if(isPossible(nums,mid,p)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
