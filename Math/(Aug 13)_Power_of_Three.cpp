// LeetCode Problem No. 326
// Daily Challenge - 13/08/2025

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
