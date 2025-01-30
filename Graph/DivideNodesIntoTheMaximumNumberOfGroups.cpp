// LeetCode Problem No. 2493
// Daily Challenge - 30/01/2025

class Solution {
    bool isComponentBipartite(vector<vector<int>>& adj,vector<int>& state,int start){
        queue<int> q;
        q.push(start);
        state[start]=1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int nbr: adj[curr]){
                if(state[nbr]==0){
                    state[nbr] = (-1) * state[curr];
                    q.push(nbr);
                }else if(state[nbr]==state[curr])
                    return false;
            }
        }
        return true;
    }

    bool checkBipartiteGraph(vector<vector<int>>& adj,int n){
        vector<int> state(n+1,0);
        for(int i=1;i<=n;++i){
            if(state[i]==0 and !isComponentBipartite(adj,state,i))
                return false;
        }
        return true;
    }

    int countLevels(vector<vector<int>>& adj,int n,int source){
        vector<bool> visited(n+1,false);
        queue<int> q;
        q.push(source);
        visited[source]=true;

        int levels=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                int curr = q.front();
                q.pop();

                for(int nbr: adj[curr]){
                    if(!visited[nbr]){
                        visited[nbr]=true;
                        q.push(nbr);
                    }
                }
            }
            levels++;
        }
        return levels;
    }

    int findMaxLevelsBFS(vector<int>& max_distance,vector<vector<int>>& adj,vector<bool>& visited,int source){
        queue<int> q;
        q.push(source);
        visited[source]=true;

        int max_levels=-1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            max_levels = max(max_levels,max_distance[curr]);
            for(int nbr: adj[curr]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
        return max_levels;
    }
 
 public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if(!checkBipartiteGraph(adj,n))
            return -1;
        
        vector<int> max_distance(n+1);
        for(int i=1;i<=n;++i)
            max_distance[i] = countLevels(adj,n,i);

        vector<bool> visited(n+1,false);
        int total_levels=0;
        for(int i=1;i<=n;++i){
            if(!visited[i])
                total_levels += findMaxLevelsBFS(max_distance,adj,visited,i);
        }
        return total_levels;
    }
};