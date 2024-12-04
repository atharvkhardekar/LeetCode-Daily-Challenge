// LeetCode Problem No. 2825
// Daily Challenge - 04/12/2024

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
       int n1 = str1.size();
        int n2 = str2.size();
        
        if (n2 > n1) return false; 
        
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
                j++; 
            }
            i++; 
        }
        return j == n2; 
    }
};