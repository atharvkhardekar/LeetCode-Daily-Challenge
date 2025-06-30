// LeetCode Problem No. 594
// Daily Challenge - 30/06/2025

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int longest = 0;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& [num, count] : freq) {
            if (freq.count(num + 1)) {
                longest = max(longest, count + freq[num + 1]);
            }
        }

        return longest;
    }
};
