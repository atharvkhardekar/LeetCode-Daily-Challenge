// LeetCode Problem No. 38
// Daily Challenge - 18/04/2025

class Solution {
    public:
        string countAndSay(int n) {
            if (n == 1) return "1";
            
            string result = "1";
    
            for (int i = 2; i <= n; ++i) {
                string current = "";
                int count = 1;
    
                for (int j = 1; j < result.size(); ++j) {
                    if (result[j] == result[j - 1]) {
                        count++;
                    } else {
                        current += to_string(count) + result[j - 1];
                        count = 1;
                    }
                }
                
                current += to_string(count) + result.back();
                result = current;
            }
    
            return result;
        }
};  