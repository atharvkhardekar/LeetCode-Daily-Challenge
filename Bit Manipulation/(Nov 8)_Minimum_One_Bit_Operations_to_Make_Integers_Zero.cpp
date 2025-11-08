// LeetCode Problem No. 1611
// Daily Challenge - 08/11/2025

class Solution{
public:
    int minimumOneBitOperations(int n)
    {
        int res = 0;
        while (n)
        {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};