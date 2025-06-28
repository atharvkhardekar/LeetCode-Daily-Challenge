// LeetCode Problem No. 2099
// Daily Challenge - 28/06/2025

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < nums.size(); ++i) {
            indexed_nums.push_back({nums[i], i});
        }

        sort(indexed_nums.begin(), indexed_nums.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        vector<pair<int, int>> top_k(indexed_nums.begin(), indexed_nums.begin() + k);

        sort(top_k.begin(), top_k.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> result;
        for (auto &p : top_k) {
            result.push_back(p.first);
        }

        return result;
    }
};
