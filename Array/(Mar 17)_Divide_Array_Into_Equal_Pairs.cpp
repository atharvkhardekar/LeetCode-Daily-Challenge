// LeetCode Problem No. 2206
// Daily Challenge - 17/03/2025

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> freq;
         
            for (int num : nums) {
                freq[num]++;
            }
            
            for (auto& pair : freq) {
                if (pair.second % 2 != 0) {
                    return false;
                }
            }
            
            return true;
        }
    };
    