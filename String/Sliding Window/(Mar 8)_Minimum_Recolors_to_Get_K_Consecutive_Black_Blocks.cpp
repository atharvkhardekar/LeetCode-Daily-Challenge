// LeetCode Problem No. 2379
// Daily Challenge - 08/03/2025

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size();
            int minOperations = k; 
            int whiteCount = 0;
    
            for (int i = 0; i < k; i++) {
                if (blocks[i] == 'W') {
                    whiteCount++;
                }
            }
            minOperations = whiteCount;
    
            for (int i = k; i < n; i++) {
                if (blocks[i - k] == 'W') whiteCount--; 
                if (blocks[i] == 'W') whiteCount++; 
    
                minOperations = min(minOperations, whiteCount);
            }
    
            return minOperations;
        }
};
    
