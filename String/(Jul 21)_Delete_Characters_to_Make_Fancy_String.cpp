// LeetCode Problem No. 1957
// Daily Challenge - 21/07/2025

class Solution {
public:
    string makeFancyString(string s) {
        string result;

        for (char c : s) {
            int n = result.size();
            if (n >= 2 && result[n - 1] == c && result[n - 2] == c) {
                continue; 
            }
            result += c; 
        }

        return result;
    }
};
