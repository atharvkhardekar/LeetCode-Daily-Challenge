// LeetCode Problem No. 3370
// Daily Challenge - 29/10/2025

class Solution{
public:
    int smallestNumber(int n)
    {
        while (n & (n + 1))
        {
            n |= n + 1;
        }
        return n;
    }
};