// LeetCode Problem No. 3234
// Daily Challenge - 15/11/2025

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        vector<int> pre(n);
        int curr = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') curr++;
            pre[i] = curr;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                int one = pre[j] - (i > 0 ? pre[i - 1] : 0);
                int zero = (j - i + 1) - one;

                if (zero * zero > one) {
                    j += (zero * zero - one - 1);
                    continue;
                }

                if (zero * zero <= one) {
                    ans++;

                    int onesqrt = (int) sqrt(one);

                    if (j + onesqrt - zero >= n)
                        ans += (n - j - 1);
                    else
                        ans += (onesqrt - zero);

                    j += (onesqrt - zero);
                }
            }
        }

        return ans;
    }
};
