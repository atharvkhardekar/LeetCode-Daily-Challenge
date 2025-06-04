// LeetCode Problem No. 3403
// Daily Challenge - 04/06/2025

class Solution {
public:
    int bestStartingPoint(string &word, int n) {
        int i = 0; 
        int j = 1; 

        while(j < n) {
            int k = 0;

            while( j+k < n && word[i+k] == word[j+k]) {
                k++;
            }

            if(j+k < n && word[j+k] > word[i+k]) {
                i = j; 
                j = j+1;
            } else {
                j = j + k + 1; 
            }
        }

        return i;
    }

    string answerString(string word, int numFriends) {
        int n = word.length();

        if(numFriends == 1)
            return word;

        int i = bestStartingPoint(word, n);

        int longestPossibleLength = n - (numFriends-1);
        int canTakePossible       = min(longestPossibleLength, n-i);

        return word.substr(i, canTakePossible);

    }
};