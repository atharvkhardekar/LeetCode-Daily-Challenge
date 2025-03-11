// LeetCode Problem No. 1358
// Daily Challenge - 11/03/2025

class Solution {
    public:
        int numberOfSubstrings(string s) {
            vector<int> count(3, 0); 
            int left = 0, result = 0, n = s.length();
    
            for (int right = 0; right < n; right++) {
                count[s[right] - 'a']++;
    
                while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                    result += (n - right); 
                    count[s[left] - 'a']--;
                    left++;
                }
            }
    
            return result;
        }
    };
    