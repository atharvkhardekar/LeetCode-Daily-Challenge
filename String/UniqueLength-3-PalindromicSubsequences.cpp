// LeetCode Problem No. 1930
// Daily Challenge - 04/01/2025

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<string> uniquePalindromes;
        vector<int> suffixCount(26, 0);
        unordered_set<char> prefixSet;

        for (char c : s) {
            suffixCount[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            char mid = s[i];
            suffixCount[mid - 'a']--;

            for (char c = 'a'; c <= 'z'; c++) {
                if (prefixSet.count(c) > 0 && suffixCount[c - 'a'] > 0) {
                    string palindrome = string(1, c) + mid + c;
                    uniquePalindromes.insert(palindrome);
                }
            }
            prefixSet.insert(mid);
        }
        return uniquePalindromes.size();
    }
};