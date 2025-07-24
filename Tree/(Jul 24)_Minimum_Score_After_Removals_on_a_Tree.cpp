// LeetCode Problem No. 2322
// Daily Challenge - 24/07/2025

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int total_XOR = 0;
        vector<int> node_XOR(nums);
        for (int x : nums) {
            total_XOR ^= x;
        }

        vector<int> tin(n), tout(n);
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = timer++;
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
                node_XOR[u] ^= node_XOR[v];
            }
            tout[u] = timer++;
        };

        dfs(0, -1);

        auto isAncestor = [&](int a, int b) {
            return tin[a] <= tin[b] && tout[b] <= tout[a];
        };

        int ans = INT_MAX;
        int m = edges.size();

        for (int i = 0; i < m - 1; ++i) {
            int a = edges[i][0], b = edges[i][1];
            if (isAncestor(a, b)) {
                swap(a, b);
            }

            for (int j = i + 1; j < m; ++j) {
                int c = edges[j][0], d = edges[j][1];
                if (isAncestor(c, d)) {
                    swap(c, d);
                }

                int x1, x2, x3;

                if (isAncestor(a, c)) {
                    x1 = total_XOR ^ node_XOR[a];
                    x2 = node_XOR[a] ^ node_XOR[c];
                    x3 = node_XOR[c];
                } else if (isAncestor(c, a)) {
                    x1 = total_XOR ^ node_XOR[c];
                    x2 = node_XOR[c] ^ node_XOR[a];
                    x3 = node_XOR[a];
                } else {
                    x1 = total_XOR ^ node_XOR[a] ^ node_XOR[c];
                    x2 = node_XOR[a];
                    x3 = node_XOR[c];
                }

                int mx = max({x1, x2, x3});
                int mn = min({x1, x2, x3});
                ans = min(ans, mx - mn);
            }
        }

        return ans;
    }
};
