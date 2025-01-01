// LeetCode Problem No. 1422
// Daily Challenge - 01/01/2025

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int totalOnes = 0;
        
        for (char c : s) {
            if (c == '1') {
                totalOnes++;
            }
        }

        int maxScore = 0;
        int leftZeros = 0;
        int rightOnes = totalOnes;

        for (int i = 0; i < n - 1; i++) { 
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }
   
            int currentScore = leftZeros + rightOnes;
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};