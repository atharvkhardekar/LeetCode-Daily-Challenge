// LeetCode Problem No. 3397
// Daily Challenge - 18/10/2025

class Solution{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        int prev = INT_MIN >> 1;
        for (int a : nums)
        {
            int low = a - k;
            int high = a + k;
            int x = prev + 1;
            if (x < low)
                x = low;
            if (x <= high)
            {
                count++;
                prev = x;
            }
        }
        return count;
    }
};
