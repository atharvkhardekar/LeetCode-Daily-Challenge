// LeetCode Problem No. 3350
// Daily Challenge - 15/10/2025

class Solution{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int up = 1, preUp = 0, res = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                up++;
            else
            {
                preUp = up;
                up = 1;
            }
            int half = up >> 1;
            int m = min(preUp, up);
            int candidate = max(half, m);
            if (candidate > res)
                res = candidate;
        }
        return res;
    }
};