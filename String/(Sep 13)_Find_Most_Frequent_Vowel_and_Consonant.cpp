// LeetCode Problem No. 3541
// Daily Challenge - 13/09/2025

class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);

        for(char c : s) {
            freq[c - 'a']++;
        }

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxVowel = 0, maxConsonant = 0;

        for(int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if(vowels.count(c)) {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }

        return maxVowel + maxConsonant;
    }
};