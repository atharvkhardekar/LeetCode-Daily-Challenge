// LeetCode Problem No. 1922
// Daily Challenge - 13/04/2025

class Solution {
    public:
        const int MOD = 1e9 + 7;
    
        long long power(long long base, long long exp) {
            long long result = 1;
            base %= MOD;
    
            while (exp > 0) {
                if (exp % 2 == 1) {
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
                exp /= 2;
            }
    
            return result;
        }
    
        int countGoodNumbers(long long n) {
            long long evenPos = (n + 1) / 2;
            long long oddPos = n / 2;
    
            long long evenChoices = power(5, evenPos);
            long long oddChoices = power(4, oddPos);
    
            return (evenChoices * oddChoices) % MOD;
        }
    };
    