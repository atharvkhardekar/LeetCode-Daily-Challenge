// LeetCode Problem No. 166
// Daily Challenge - 24/09/2025

class Solution{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";

        string ans;
      
        if ((numerator < 0) ^ (denominator < 0))
            ans += '-';
    
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);

        int g = gcd(num, den);
        num /= g, den /= g; 

        long long q = num / den;
        long long r = num % den;
        ans += to_string(q);

        if (r == 0)
            return ans;

        int factor_wo2_5 = den;
        int bz = __builtin_ctzll(factor_wo2_5);
        factor_wo2_5 >>= bz;
        while (factor_wo2_5 % 5 == 0)
            factor_wo2_5 /= 5;
        bool finteDecimal = factor_wo2_5 == 1;

        ans += '.';
        unordered_map<long long, int> mp;
        string frac;

        for (int i = 0; r != 0; i++)
        {
            if (!finteDecimal)
            {
                auto it = mp.find(r);
                if (it != mp.end())
                {
                    frac.insert(it->second, "(");
                    frac += ')';
                    break;
                }
                mp[r] = i;
            }
            r *= 10;
            frac += ('0' + r / den);
            r %= den;
        }

        return ans + frac;
    }
};