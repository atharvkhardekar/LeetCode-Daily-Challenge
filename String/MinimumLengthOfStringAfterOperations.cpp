// LeetCode Problem No. 3223
// Daily Challenge - 13/01/2025

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0); 
        
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int length = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] & 1) {
                length += 1;
            } else {
                length += min(2, freq[i]);
            }
        }
        return length;
    }
};