// LeetCode Problem No. 1304
// Daily Challenge - 07/09/2025

class Solution {
public:

    vector<int> sumZero(int n) {
        vector<int> res;
    
        if (n % 2 == 1) {
            res.push_back(0);
            n--; 
        }
        
        for (int i = 1; i <= n / 2; i++) {
            res.push_back(i);
            res.push_back(-i);
        }
        return res;
    }
};