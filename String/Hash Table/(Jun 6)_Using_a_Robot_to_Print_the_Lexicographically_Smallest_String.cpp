// LeetCode Problem No. 2434
// Daily Challenge - 06/06/2025

class Solution {
    inline char smallest(vector<int>& right_freq) {
        for (int i = 0; i < 26; ++i) {
            if (right_freq[i] > 0) {
                return char(97 + i);
            }
        }
        return 'z';
    }

 public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> right_freq(26, 0);

        for (int i = 0; i < n; ++i) {
            right_freq[s[i] - 'a']++;
        }

        string t, res;
        int pos = 0;

        while (pos < n) {
            t.push_back(s[pos]);
            right_freq[s[pos] - 'a']--;

            while (!t.empty() && t.back() <= smallest(right_freq)) {
                res.push_back(t.back());
                t.pop_back();
            }

            pos++;
        }

        return res;
    }
};
