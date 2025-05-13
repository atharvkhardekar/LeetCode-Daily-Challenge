// LeetCode Problem No. 3335
// Daily Challenge - 13/05/2025

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int step = 0; step < t; ++step) {
            vector<long long> nextFreq(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (freq[i] == 0) continue;

                if (i == 25) {
                    nextFreq[0] = (nextFreq[0] + freq[i]) % MOD; 
                    nextFreq[1] = (nextFreq[1] + freq[i]) % MOD; 
                } else {
                    nextFreq[i + 1] = (nextFreq[i + 1] + freq[i]) % MOD;
                }
            }
            freq = nextFreq;
        }

        long long totalLength = 0;
        for (int i = 0; i < 26; ++i) {
            totalLength = (totalLength + freq[i]) % MOD;
        }

        return (int)totalLength;
    }
};