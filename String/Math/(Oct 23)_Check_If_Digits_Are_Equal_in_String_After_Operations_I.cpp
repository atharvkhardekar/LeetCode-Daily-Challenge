// LeetCode Problem No. 3461
// Daily Challenge - 23/10/2025

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string t;
            for (int i = 0; i < s.size() - 1; i++) {
                int sum = (s[i] - '0') + (s[i + 1] - '0');
                t.push_back((sum % 10) + '0');
            }
            s = t;
        }
        return s[0] == s[1];
    }
};
