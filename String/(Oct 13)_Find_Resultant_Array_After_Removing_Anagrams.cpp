// LeetCode Problem No. 2273
// Daily Challenge - 13/10/2025

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]); 
        
        for (int i = 1; i < words.size(); i++) {
            string prev = result.back(); 
            string curr = words[i];
            
            string s1 = prev, s2 = curr;
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            
            if (s1 != s2) {
                result.push_back(curr);
            }
        }
        
        return result;
    }
};