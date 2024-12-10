// LeetCode Problem No. 2981
// Daily Challenge - 10/12/2024

class Solution {
    int &findMin(int &x, int &y, int &z) {
        if (x <= y && x <= z) return x;
        if (y <= x && y <= z) return y;
        return z;
    }
 
 public:
    int maximumLength(string str) {
        int length = str.size();
        vector<vector<int>> charTop3Freq(26, vector<int>(3, -1));

        char prevChar = '*';
        int currentLength = 0;

        for (char &currentChar : str) {
            int index = currentChar - 'a';
            currentLength = currentChar == prevChar ? currentLength + 1 : 1;
            prevChar = currentChar;

            int &minLength = findMin(charTop3Freq[index][0], charTop3Freq[index][1],charTop3Freq[index][2]);
            if (currentLength > minLength) {
                minLength = currentLength;
            }
        }

        int maxLength = -1;
        for (int i = 0; i < 26; ++i) {
            maxLength = max(maxLength, min({charTop3Freq[i][0], charTop3Freq[i][1], charTop3Freq[i][2]}));
        }

        return maxLength;
    }
};
