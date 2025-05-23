// LeetCode Problem No. 3068
// Daily Challenge - 23/05/2025

class Solution {
    #define ll long long
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll ans = 0;
        ll count=0;
        ll discardedNode = INT_MAX;
        
        for(ll num: nums){
            ans += max(num,num^k);
            count += (num^k)>num;
            discardedNode = min(discardedNode,abs(num-(num^k)));
        }
        return count%2==0?ans:(ans-discardedNode);
    }
};
