// LeetCode Problem No. 2125
// Daily Challenge - 27/10/2025

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;  
        int total = 0;

        for (string &row : bank) {
            int curr = count(row.begin(), row.end(), '1');  

            if (curr == 0) continue;  

            total += prev * curr;  
            prev = curr;           
        }

        return total;
    }
};