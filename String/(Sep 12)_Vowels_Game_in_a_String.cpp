// LeetCode Problem No. 3227
// Daily Challenge - 12/09/2025

class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for (char ch : s) {
            if (vowels.find(ch) != string::npos) {
                return true; 
            }
        }
        return false;
    }
};