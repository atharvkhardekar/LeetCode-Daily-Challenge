// LeetCode Problem No. 781
// Daily Challenge - 20/04/2025

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int, int> count;
            int result = 0;
    
            for (int ans : answers) {
                count[ans]++;
            }
    
            for (auto& [x, freq] : count) {
                int groupSize = x + 1;
                int groups = ceil((double)freq / groupSize); 
                result += groups * groupSize;
            }
    
            return result;
        }
};