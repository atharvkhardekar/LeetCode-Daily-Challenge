// LeetCode Problem No. 2901
// Daily Challenge - 16/05/2025

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);         
        vector<int> prev(n, -1);    

        auto hamming = [](const string& a, const string& b) -> int {
            if (a.size() != b.size()) return -1;
            int dist = 0;
            for (int i = 0; i < a.size(); ++i)
                dist += (a[i] != b[i]);
            return dist;
        };

        int max_len = 1, last_index = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && 
                    words[i].size() == words[j].size() && 
                    hamming(words[i], words[j]) == 1) {

                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                last_index = i;
            }
        }

        vector<string> result;
        while (last_index != -1) {
            result.push_back(words[last_index]);
            last_index = prev[last_index];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
