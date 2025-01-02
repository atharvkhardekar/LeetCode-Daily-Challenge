// LeetCode Problem No. 2559
// Daily Challenge - 02/01/2025

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            char start = words[i][0];
            char end = words[i].back();
            if (vowels.count(start) && vowels.count(end)) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            ans.push_back(prefixSum[r + 1] - prefixSum[l]);
        }
        return ans;
    }
};