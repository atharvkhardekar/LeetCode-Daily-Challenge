// LeetCode Problem No. 3085
// Daily Challenge - 21/06/2025

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        vector<int> counts;
        for (auto& entry : freq) {
            counts.push_back(entry.second);
        }

        sort(counts.begin(), counts.end());

        int n = counts.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int target = counts[i]; 
            int deletions = 0;
            for (int j = 0; j < n; ++j) {
                if (counts[j] < target) {
                    deletions += counts[j];
                } else if (counts[j] > target + k) {
                    deletions += counts[j] - (target + k);
                }
            }
            ans = min(ans, deletions);
        }

        return ans;
    }
};
