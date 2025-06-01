// LeetCode Problem No. 2929
// Daily Challenge - 01/06/2025

class Solution {
 public:
    long long count(int sum) {
        if (sum < 0) return 0;
        return 1LL * (sum + 2) * (sum + 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long total = count(n);

        long long over1 = 3 * count(n - (limit + 1));

        long long over2 = 3 * count(n - 2 * (limit + 1));

        long long over3 = count(n - 3 * (limit + 1));

        return total - over1 + over2 - over3;
    }
};
