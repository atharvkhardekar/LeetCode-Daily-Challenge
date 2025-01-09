// LeetCode Problem No. 2185
// Daily Challenge - 09/01/2025

class Solution {
public:
    
    bool find(string w, string pref) {
        for(int i = 0; i < pref.length(); i++) {
            if(w[i] != pref[i]) {
                return false;
            }
        }

        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for(auto w : words) {
            if(find(w, pref)) {
                ans++;
            }
        }

        return ans;
    }
};