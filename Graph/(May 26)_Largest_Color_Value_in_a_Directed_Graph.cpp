// LeetCode Problem No. 1857
// Daily Challenge - 26/05/2025

class Solution {
    int dfs(int curr, vector<vector<int>>& adj, vector<int>& visited, vector<vector<int>>& longest, string& colors) {
        if (visited[curr] == 1) {
            return INT_MAX;
        }

        if (visited[curr] == 0) {
            visited[curr] = 1;

            for (int nbr : adj[curr]) {
                int res = dfs(nbr, adj, visited, longest, colors);
                if (res == INT_MAX) {
                    return INT_MAX;
                }

                for (int i = 0; i < 26; ++i) {
                    longest[i][curr] = max(longest[i][curr], longest[i][nbr]);
                }
            }

            longest[colors[curr] - 'a'][curr]++;
            visited[curr] = 2;
        }

        return longest[colors[curr] - 'a'][curr];
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> longest(26, vector<int>(n));
        int max_color_length = 0;
        vector<int> visited(n);

        for (int i = 0; i < n; ++i) {
            int res = dfs(i, adj, visited, longest, colors);
            if (res == INT_MAX) {
                return -1;
            }
            max_color_length = max(max_color_length, res);
        }

        return max_color_length;
    }
};