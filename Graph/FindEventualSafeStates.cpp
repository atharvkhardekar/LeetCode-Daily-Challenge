// LeetCode Problem No. 802
// Daily Challenge - 24/01/2025

class Solution {
    vector<bool> safe_nodes;
    bool checkSafeState(vector<vector<int>>& graph,vector<int>& visited,int curr){
        visited[curr] = 1;
        bool is_safe = true;

        for(int nbr: graph[curr]){
            if(visited[nbr] == 0){
                is_safe &= checkSafeState(graph,visited,nbr);
            }else if(visited[nbr] == 1){
                return safe_nodes[curr] = false;
            }else if(visited[nbr] == 2){
                is_safe &= safe_nodes[nbr];
            }
        }

        visited[curr] = 2;
        return safe_nodes[curr] = is_safe;
    }

 public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        safe_nodes = vector<bool>(n,true);

        vector<int> visited(n,0);
        for(int i=0; i<n; ++i){
            if(visited[i] == 0){
                checkSafeState(graph,visited,i);
            }
        }

        vector<int> res;
        for(int i=0; i<n; ++i)
            if(safe_nodes[i] == true)
                res.push_back(i);

        return res;
    }
};