// LeetCode Problem No. 2900
// Daily Challenge - 15/05/2025

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;

        if (words.empty()) return result;

        result.push_back(words[0]);
        int lastGroup = groups[0];

        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i];
            }
        }

        return result;
    }
};
