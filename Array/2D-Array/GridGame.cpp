// LeetCode Problem No. 2017
// Daily Challenge - 21/01/2025

class Solution {
    #define ll long long

 public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n<2) return 0;

        ll top_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        ll bottom_sum = 0;
        
        ll min_sum = LONG_MAX;
        for(int pp=0; pp<n; ++pp){
            top_sum -= grid[0][pp];
            min_sum = min(min_sum, max(top_sum, bottom_sum));
            bottom_sum += grid[1][pp];
        }
        return min_sum;
    }
};