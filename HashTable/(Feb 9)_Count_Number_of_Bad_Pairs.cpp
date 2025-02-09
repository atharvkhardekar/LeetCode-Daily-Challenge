// LeetCode Problem No. 2364
// Daily Challenge - 09/02/2025

class Solution {
    #define ll long long
 
 public:
    long long countBadPairs(vector<int>& nums) {
        ll n = nums.size();
        
        unordered_map<int,int> freq;
        ll good_pairs = 0;
        for(int i=0; i<n; ++i){
            if(freq.count(nums[i]-i))
                good_pairs += freq[nums[i]-i];
            freq[nums[i]-i]++;
        }
        ll bad_pairs = n*(n-1)/2 - good_pairs;
        return bad_pairs;
    }
};
