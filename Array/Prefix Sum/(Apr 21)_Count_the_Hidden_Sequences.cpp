// LeetCode Problem No. 2145
// Daily Challenge - 21/04/2025

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long min_val = 0, max_val = 0, current = 0;
            
            for (int diff : differences) {
                current += diff;
                min_val = min(min_val, current);
                max_val = max(max_val, current);
            }
            
            long long start = lower - min_val;
            long long end = upper - max_val;
            
            return max(0LL, end - start + 1);
        }
};
    