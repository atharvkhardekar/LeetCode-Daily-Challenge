// LeetCode Problem No. 2110
// Daily Challenge - 15/12/2025

class Solution{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long ans = 0;
        int count = 1;

        for (int i = 0; i < prices.size(); i++)
        {
            if (i == 0)
            {
                ans += count;
                continue;
            }

            if (prices[i] == prices[i - 1] - 1)
            {
                count++;
            }
            else
            {
                count = 1;
            }

            ans += count;
        }

        return ans;
    }
};