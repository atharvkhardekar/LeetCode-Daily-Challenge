// LeetCode Problem No. 1079
// Daily Challenge - 17/02/2025

class Solution {
    public:
        int numTilePossibilities(string tiles) {
            vector<int> count(26, 0);
        
            for (char c : tiles) {
                count[c - 'A']++;
            }
    
            return backtrack(count);
        }
        
     private:
        int backtrack(vector<int>& count) {
            int sum = 0;
            
            for (int i = 0; i < 26; ++i) {
                if (count[i] == 0) continue;
                
                count[i]--;
                
                sum += 1 + backtrack(count);
              
                count[i]++;
            }
            return sum;
        }
    };
    