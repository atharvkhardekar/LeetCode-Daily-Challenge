// LeetCode Problem No. 1128
// Daily Challenge - 04/05/2025

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<int, int> count;
            int result = 0;
    
            for (auto& d : dominoes) {
                int a = min(d[0], d[1]);
                int b = max(d[0], d[1]);
                int key = a * 10 + b;  
                result += count[key];
                count[key]++;
            }
    
            return result;
        }
    };
    