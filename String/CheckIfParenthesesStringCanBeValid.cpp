// LeetCode Problem No. 2116
// Daily Challenge - 12/01/2025

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 != 0) return false;

        int openCount = 0, placeholderCount = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') ++openCount;
                else --openCount; 
            } else {
                ++placeholderCount; 
            }

            if (openCount + placeholderCount < 0) return false;
        }

        openCount = 0;
        placeholderCount = 0;

        for (int i = s.length() - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                if (s[i] == ')') ++openCount;
                else --openCount; 
            } else {
                ++placeholderCount; 
            }

            if (openCount + placeholderCount < 0) return false;
        }
        return true;
    }
};
