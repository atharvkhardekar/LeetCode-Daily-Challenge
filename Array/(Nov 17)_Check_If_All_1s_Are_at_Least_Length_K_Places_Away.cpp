// LeetCode Problem No. 1437
// Daily Challenge - 17/11/2025

class Solution{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int zeros = k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (zeros < k)
                    return false;
                zeros = 0;
            }
            else
            {
                zeros++;
            }
        }
        return true;
    }
};