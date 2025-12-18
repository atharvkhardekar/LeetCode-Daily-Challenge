// LeetCode Problem No. 3652
// Daily Challenge - 18/12/2025

const int N = 1e5 + 1;
long long sum[N] = {0};

class Solution{
public:
    static long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        const int n = prices.size(), k2 = k / 2;
        long long modify = 0;
        for (int i = 0; i < n; i++)
        {
            const int x = prices[i];
            sum[i + 1] = sum[i] + strategy[i] * x;
            modify += (-(i >= k2 & i < k) & x);
        }
        long long profit = max(sum[n], modify + sum[n] - sum[k]);

        for (int i = 1; i + k <= n; i++)
        {
            modify += prices[i + k - 1] - prices[i + k2 - 1];
            profit = max(profit, modify + sum[n] - sum[i + k] + sum[i]);
        }
        return profit;
    }
};
