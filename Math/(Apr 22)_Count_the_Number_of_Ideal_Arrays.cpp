// LeetCode Problem No. 2338
// Daily Challenge - 22/04/2025

class Solution {
    #define ll long long

    ll count[15][10005];
    ll prefix_sum[15][10005];
    ll options[15];
    int MOD = 1e9 + 7;

    void countUniqueSequences(int curr, int idx, int& maxValue) {
        options[idx] += 1;
        for (int j = 2; curr * j <= maxValue; ++j) {
            countUniqueSequences(curr * j, idx + 1, maxValue);
        }
    }

 public:
    int idealArrays(int n, int maxValue) {
        memset(count, 0, sizeof(count));
        memset(prefix_sum, 0, sizeof(prefix_sum));
        memset(options, 0, sizeof(options));

        for (int i = 1; i <= 10000; ++i) {
            count[1][i] = 1;
            prefix_sum[1][i] = i;
        }

        for (int i = 2; i <= 14; ++i) {
            for (int j = i; j <= 10000; ++j) {
                count[i][j] = prefix_sum[i - 1][j - 1];
                prefix_sum[i][j] = count[i][j] + prefix_sum[i][j - 1];
                count[i][j] %= MOD;
                prefix_sum[i][j] %= MOD;
            }
        }

        for (int i = 1; i <= maxValue; ++i) {
            countUniqueSequences(i, 1, maxValue);
        }

        ll ans = 0;
        ll ways;

        for (int i = 1; i <= 14; ++i) {
            ways = count[i][n] * options[i];
            ways %= MOD;
            ans += ways;
            ans %= MOD;
        }

        return ans;
    }
};
