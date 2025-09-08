// LeetCode Problem No. 1317
// Daily Challenge - 08/09/2025

class Solution {
public:
    bool isNoZero(int x) {
        while (x > 0) {
            if (x % 10 == 0) return false; 
            x /= 10;
        }
        return true;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (isNoZero(a) && isNoZero(b)) {
                return {a, b};
            }
        }
        return {}; 
    }
};