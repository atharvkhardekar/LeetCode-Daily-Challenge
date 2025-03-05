// LeetCode Problem No. 2579
// Daily Challenge - 05/03/2025

class Solution {
    #define ll long long
 
 public:
    long long coloredCells(int n) {
        ll count=1;
        ll jump_size=4;
        
        while(n>1){
            count += jump_size;
            jump_size += 4;
            n--;
        }
        return count;
    }
};

// OR

class Solution {
    public:
        long long coloredCells(int n) {
            return 1 + 4*((long long)n*(n-1)/2);
        }
};