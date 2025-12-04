// LeetCode Problem No. 2211
// Daily Challenge - 04/12/2025

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;
        
        while (i < n && directions[i] == 'L') i++;
     
        while (j >= 0 && directions[j] == 'R') j--;
        
        int collisions = 0;
        
        for (int k = i; k <= j; k++) {
            if (directions[k] == 'L' || directions[k] == 'R')
                collisions++;
        }
        
        return collisions;
    }
};