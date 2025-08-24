// LeetCode Problem No. 1493
// Daily Challenge - 24/08/2025

class Solution{
public:
    int longestSubarray(vector<int> &nums)
    {
        const int n = nums.size();
        int zeros = 0, ans = 0;
        for (int l = 0, r = 0; r < n; r++)
        {
            zeros += (nums[r] == 0);
            while (zeros > 1 && nums[l++] == 0)
            {
                zeros--;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};