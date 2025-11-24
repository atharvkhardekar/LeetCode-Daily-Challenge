// LeetCode Problem No. 1018
// Daily Challenge - 24/11/2025

class Solution{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        int val = 0;
        vector<bool> res;

        for (auto &n : nums)
        {
            val = ((val << 1) + n) % 5;
            res.push_back(val == 0);
        }

        return res;
    }
};
