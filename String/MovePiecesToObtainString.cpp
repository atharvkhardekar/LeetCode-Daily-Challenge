// LeetCode Problem No. 2337
// Daily Challenge - 05/12/2024

class Solution {
    void skipSpaces(string& s, int& pos) {
        while (pos < s.size() && s[pos] == '_') pos++;
    }

public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            skipSpaces(start, i);
            skipSpaces(target, j);

            if (i == n && j == n) return true;

            if (i == n || j == n) return false;

            if (start[i] != target[j]) return false;

            if (start[i] == 'L' && i < j) return false; 
            if (start[i] == 'R' && i > j) return false; 

            i++;
            j++;
        }
        return true;
    }
};
