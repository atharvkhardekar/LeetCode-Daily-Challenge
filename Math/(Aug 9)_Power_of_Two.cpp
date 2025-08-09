// LeetCode Problem No. 231
// Daily Challenge - 09/08/2025

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        for (int i = 0; i <= 30; i++)
        {
            int ans = pow(2, i);
            if (ans == n)
            {
                return true;
            }
        }
        return false;
    }
};
