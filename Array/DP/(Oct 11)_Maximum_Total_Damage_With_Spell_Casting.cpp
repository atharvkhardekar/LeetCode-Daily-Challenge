// LeetCode Problem No. 3186
// Daily Challenge - 11/10/2025\

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> counts;
        for (int p : power) {
            counts[p]++;
        }

        vector<int> unique_powers;
        for (auto const& [p, count] : counts) {
            unique_powers.push_back(p);
        }

        int n = unique_powers.size();
        if (n == 0) {
            return 0;
        }

        vector<long long> dp(n, 0);

        dp[0] = static_cast<long long>(unique_powers[0]) * counts[unique_powers[0]];

        for (int i = 1; i < n; ++i) {
            int current_power = unique_powers[i];
            
            long long damage_if_cast = static_cast<long long>(current_power) * counts[current_power];
            int required_prev_power = current_power - 3;
            
            auto it = upper_bound(unique_powers.begin(), unique_powers.begin() + i, required_prev_power);
            
            if (it != unique_powers.begin()) {
                it--;
                int prev_idx = distance(unique_powers.begin(), it);
                damage_if_cast += dp[prev_idx];
            }

            long long damage_if_not_cast = dp[i - 1];

            dp[i] = max(damage_if_cast, damage_if_not_cast);
        }

        return dp[n - 1];
    }
};