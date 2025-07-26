// LeetCode Problem No. 3480
// Daily Challenge - 26/07/2025

class Solution {
    #define ll long long
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();

        for (int i = 0; i < m; ++i) {
            if (conflictingPairs[i][0] > conflictingPairs[i][1]) {
                swap(conflictingPairs[i][0], conflictingPairs[i][1]);
            }
        }

        sort(conflictingPairs.begin(), conflictingPairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        ll blocked = 0;
        ll profit = 0;
        ll max_profit = 0;
        ll max1 = 0;
        ll max2 = 0;

        for (int i = 0; i < m; ++i) {
            int start = conflictingPairs[i][0];
            int bottom = (i < m - 1) ? conflictingPairs[i + 1][1] : n + 1;
            int gap = bottom - conflictingPairs[i][1];

            if (start > max1) {
                max2 = max1;
                max1 = start;
                profit = 0;
            } else if (start > max2) {
                max2 = start;
            }

            profit += 1LL * (max1 - max2) * gap;

            if (profit > max_profit) {
                max_profit = profit;
            }

            blocked += 1LL * max1 * gap;
        }

        ll total_subarrays = 1LL * n * (n + 1) / 2;
        return total_subarrays - blocked + max_profit;
    }
};