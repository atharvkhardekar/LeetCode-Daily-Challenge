// LeetCode Problem No. 2845
// Daily Challenge - 25/04/2025

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            unordered_map<int, long long> countMap;
            countMap[0] = 1;
            
            long long res = 0;
            int prefix = 0;
            
            for (int num : nums) {
                if (num % modulo == k)
                    prefix++;
                
                int need = (prefix - k + modulo) % modulo;
                if (countMap.find(need) != countMap.end()) {
                    res += countMap[need];
                }
                
                countMap[prefix % modulo]++;
            }
            
            return res;
        }
};    