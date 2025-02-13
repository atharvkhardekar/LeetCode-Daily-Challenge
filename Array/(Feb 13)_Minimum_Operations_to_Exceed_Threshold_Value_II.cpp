// LeetCode Problem No. 3066
// Daily Challenge - 13/02/2025

class Solution {
    #define ll long long
 
 public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> minheap(nums.begin(),nums.end());
        
        int count = 0;
        while(!minheap.empty()){
            ll min1 = minheap.top();
            minheap.pop();
            if(min1>=k)
                break;
            ll min2 = minheap.top();
            minheap.pop();
            
            minheap.push(2*min(min1,min2)+max(min1,min2));
            count++;
        }
        return count;
    }
};