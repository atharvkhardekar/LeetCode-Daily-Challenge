// LeetCode Problem No. 3201
// Daily Challenge - 16/07/2025

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odd_count = nums[0]%2==1;
        int even_count = nums[0]%2==0;
        int alternate_count = 1;
        bool expecting_even = nums[0]&1 ? true : false;
        
        for(int i=1;i<n;++i){
            if((expecting_even==true and nums[i]%2==0) or (expecting_even==false and nums[i]%2==1)){
                alternate_count++;
                expecting_even = !expecting_even;
            }
            
            if(nums[i]&1)   odd_count++;
            else            even_count++;
        }
        return max({even_count,odd_count,alternate_count});
    }
};