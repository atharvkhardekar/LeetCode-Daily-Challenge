// LeetCode Problem No. 2154
// Daily Challenge - 19/11/2025

class Solution{
public:
    int findFinalValue(vector<int> &nums, int k)
    {
        int bits = 0;
        for (auto &n : nums)
        {
            if (n % k != 0)
                continue;
            n /= k;
            if ((n & (n - 1)) == 0)
                bits |= n;
        }
        bits++;
        return k * (bits & -bits);
    }
};
