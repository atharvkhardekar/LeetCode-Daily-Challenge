// LeetCode Problem No. 1298
// Daily Challenge - 03/06/2025

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;

        for (int start : initialBoxes) {
            q.push(start);
        }

        unordered_set<int> closed;
        int total = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (status[curr] == 0) {
                closed.insert(curr);
                continue;
            }

            for (int open : keys[curr]) {
                status[open] = 1;
                if (closed.count(open)) {
                    q.push(open);
                    closed.erase(open);
                }
            }

            total += candies[curr];

            for (int nbr : containedBoxes[curr]) {
                q.push(nbr);
            }
        }

        return total;
    }
};