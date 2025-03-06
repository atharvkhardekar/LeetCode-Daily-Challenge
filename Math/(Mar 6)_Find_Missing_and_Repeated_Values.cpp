// LeetCode Problem No. 2965
// Daily Challenge - 06/03/2025

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            long long N = 1LL * n * n;  
    
            long long expectedSum = (N * (N + 1)) / 2;
            long long expectedSquareSum = (N * (N + 1) * (2 * N + 1)) / 6;
    
            long long actualSum = 0, actualSquareSum = 0;
            unordered_map<int, int> count;
    
            int duplicate = -1, missing = -1;
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int val = grid[i][j];
                    actualSum += val;
                    actualSquareSum += 1LL * val * val;  
    
                    count[val]++;
                    if (count[val] == 2) {
                        duplicate = val;
                    }
                }
            }
    
            long long diff1 = expectedSum - actualSum; 
            long long diff2 = expectedSquareSum - actualSquareSum; 
    
            missing = duplicate + diff1;
    
            return {duplicate, missing};
        }
    };
    