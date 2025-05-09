// LeetCode Problem No. 3343
// Daily Challenge - 09/05/2025

class Solution {
    using ll = long long;
    int mod = 1e9 + 7;
    int tot_ways_to_permute;

    vector<int> fact;
    vector<int> inverse_fact;
    vector<int> freq;
    int mem[10][42][370]; 

    int modMul(int& a, int& b) {
        return ((ll)(a % mod) * (b % mod)) % mod;
    }

    void computeFactorial(int n) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = modMul(fact[i - 1], i);
        }
    }

    int binaryExponentiation(int a, int b) {
        int res = 1;
        while (b > 0) {
            if (b & 1) {
                res = modMul(res, a);
            }
            a = modMul(a, a);
            b /= 2;
        }
        return res;
    }

    void computeInverseFactorial(int n) {
        for (int i = 0; i <= n; ++i) {
            inverse_fact[i] = binaryExponentiation(fact[i], mod - 2);
        }
    }

    int countPermutation(int digit, int leftover, int target) {
        if (digit == 10) {
            if (leftover == 0) {
                return target == 0 ? tot_ways_to_permute : 0;
            } else {
                return 0;
            }
        }

        if (mem[digit][leftover][target] != -1) {
            return mem[digit][leftover][target];
        }

        int include_count = min({leftover, freq[digit], digit > 0 ? target / digit : INT_MAX});
        ll ans = 0;

        for (int i = 0; i <= include_count; ++i) {
            ll ways_for_current_digit = modMul(inverse_fact[i], inverse_fact[freq[digit] - i]);
            ans += (ways_for_current_digit * countPermutation(digit + 1, leftover - i, target - digit * i)) % mod;
            ans %= mod;
        }

        return mem[digit][leftover][target] = ans;
    }

public:
    int countBalancedPermutations(string num) {
        int n = num.size();
        int sum = 0;
        freq = vector<int>(10);

        for (int i = 0; num[i] != '\0'; ++i) {
            sum += num[i] - '0';
            freq[num[i] - '0']++;
        }

        if (sum & 1) {
            return 0;
        }

        int target = sum / 2;
        fact = vector<int>(n + 1);
        computeFactorial(n);

        inverse_fact = vector<int>(n + 1);
        computeInverseFactorial(n);

        tot_ways_to_permute = modMul(fact[n / 2], fact[(n + 1) / 2]);
        memset(mem, -1, sizeof(mem));

        return countPermutation(0, n / 2, target);
    }
};
