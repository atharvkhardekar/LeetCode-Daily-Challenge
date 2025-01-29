// LeetCode Problem No. 684
// Daily Challenge - 29/01/2025

class Solution {
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == -1)
            return node;
        return parent[node] = findParent(parent, parent[node]); 
    }

 public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, -1);
        vector<int> rank(n + 1, 0); 

        for (auto& edge : edges) {
            int rootA = findParent(parent, edge[0]);
            int rootB = findParent(parent, edge[1]);

            if (rootA == rootB)
                return edge;

            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
        return {0, 0};
    }
};