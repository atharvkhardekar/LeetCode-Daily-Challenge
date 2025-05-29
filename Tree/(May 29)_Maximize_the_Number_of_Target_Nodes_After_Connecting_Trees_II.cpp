// LeetCode Problem No. 3373
// Daily Challenge - 29/05/2025

class Solution {
    #define pii pair<int, int>

    int bfs(int start, const vector<vector<int>>& adj, vector<bool>* included = nullptr) {
        queue<pii> q;
        q.push({start, -1});
        int count = 0;
        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            if (level % 2 == 0) {
                count += size;
            }

            while (size--) {
                auto [curr, parent] = q.front();
                q.pop();

                if (included && level % 2 == 0) {
                    (*included)[curr] = true;
                }

                for (int v : adj.at(curr)) {
                    if (v == parent) {
                        continue;
                    }
                    q.push({v, curr});
                }
            }
            ++level;
        }

        return count;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        vector<vector<int>> adj1(n1 + 1), adj2(n2 + 1);

        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int even_count2 = bfs(0, adj2);
        int odd_count2 = n2 - even_count2;
        int best2 = max(even_count2, odd_count2);

        vector<bool> included(n1, false);
        int even_count1 = bfs(0, adj1, &included);

        vector<int> ans(n1);
        for (int i = 0; i < n1; ++i) {
            if (included[i]) {
                ans[i] = even_count1 + best2;
            } else {
                ans[i] = (n1 - even_count1) + best2;
            }
        }

        return ans;
    }
};