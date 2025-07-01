// LeetCode Problem No. 3330
// Daily Challenge - 01/07/2025

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 1; 

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word[j] == word[i]) {
                j++;
            }
            int len = j - i;
            if (len > 1) {
                count += (len - 1);
            }
            i = j;
        }

        return count;
    }
};
