// LeetCode Problem No. 2381
// Daily Challenge - 05/01/2025

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0); 
        
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int value = (direction == 1) ? 1 : -1;
            diff[start] += value;
            diff[end + 1] -= value;
        }
 
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += diff[i];
            int shift = (cumulativeShift % 26 + 26) % 26; 
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return s;
    }
};
