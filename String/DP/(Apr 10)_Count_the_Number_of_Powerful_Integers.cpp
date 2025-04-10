// LeetCode Problem No. 2999
// Daily Challenge - 10/04/2025

class Solution {
    #define ll long long
    #define MAX_DIGITS 17
    ll dp[MAX_DIGITS][2];

    static bool checkSubtract(const string& num_str, ll num_digits, const string& suffix, int limit) {
        if (num_digits < suffix.size()) return false;

        string suffix_of_num = num_str.substr(num_digits - suffix.size());
        bool subtract = stoll(suffix_of_num) < stoll(suffix);

        if (subtract) {
            for (int i = 0; i < num_digits - suffix.size(); ++i) {
                if ((num_str[i] - '0') > limit) {
                    subtract = false;
                    break;
                }
            }
        }

        return subtract;
    }

    ll countValidNumbers(const string& number_str, ll idx, ll max_digits,
                         bool is_tight, int limit, const string& suffix) {
        if (idx == max_digits) {
            return 1;
        }

        if (dp[idx][is_tight] != -1) {
            return dp[idx][is_tight];
        }

        ll low = 0, high;
        ll suffix_len = suffix.size();

        if (idx >= max_digits - suffix_len) {
            ll suffix_idx = idx - (max_digits - suffix_len);
            low = high = suffix[suffix_idx] - '0';
        } else {
            high = is_tight ? min<ll>(limit, number_str[idx] - '0') : limit;
        }

        ll total = 0;

        for (ll digit = low; digit <= high; ++digit) {
            bool new_tight = is_tight && (digit == number_str[idx] - '0');
            total += countValidNumbers(number_str, idx + 1, max_digits, new_tight, limit, suffix);
        }

        return dp[idx][is_tight] = total;
    }

    ll solveUpTo(const string& num_str, ll num_digits, int limit, const string& suffix) {
        memset(dp, -1, sizeof(dp));
        ll result = countValidNumbers(num_str, 0, num_digits, true, limit, suffix);

        if (checkSubtract(num_str, num_digits, suffix, limit)) {
            result--;
        }

        return result;
    }

 public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suffix) {
        ll suffix_val = stoll(suffix);
        string finish_str = to_string(finish);
        string start_str = to_string(start - 1);

        ll finish_digits = finish_str.size();
        ll start_digits = start_str.size();

        ll upto_finish = (finish >= suffix_val) ? solveUpTo(finish_str, finish_digits, limit, suffix) : 0;
        ll upto_start  = (suffix_val < start) ? solveUpTo(start_str, start_digits, limit, suffix) : 0;

        return upto_finish - upto_start;
    }
};