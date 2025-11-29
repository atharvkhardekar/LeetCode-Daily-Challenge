// LeetCode Problem No. 3512
// Daily Challenge - 29/11/2025

class Solution{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum % k;
    }
};