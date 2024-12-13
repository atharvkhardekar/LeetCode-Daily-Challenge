// LeetCode Problem No. 2593
// Daily Challenge - 13/12/2024

class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int, int>> sortedSet;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            sortedSet.emplace(nums[i], i);
        }

        long long score = 0;
        set<int> marked; 

        while (!sortedSet.empty()) {
            auto [value, index] = *sortedSet.begin();
            sortedSet.erase(sortedSet.begin());

            if (marked.count(index)) continue;

            score += value;
            marked.insert(index);
            if (index > 0) marked.insert(index - 1);
            if (index < n - 1) marked.insert(index + 1);
        }
        return score;
    }
};
