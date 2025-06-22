// LeetCode Problem No. 2138
// Daily Challenge - 22/06/2025

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();
   
        while (s.length() % k != 0) {
            s += fill;
        }
        
        for (int i = 0; i < s.length(); i += k) {
            result.push_back(s.substr(i, k));
        }
        
        return result;
    }
};
