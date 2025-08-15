// LeetCode Problem No. 342
// Daily Challenge - 15/08/2025

class Solution {
public:
    bool isPowerOfFour(int n) {
        // Condition 1: n > 0
        // Condition 2: Only one bit is set (power of 2)
        // Condition 3: That bit is at an even position (mask 0x55555555)
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
    }
};