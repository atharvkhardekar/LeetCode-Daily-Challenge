// LeetCode Problem No. 2127
// Daily Challenge - 26/01/2025

class Solution {
    int kahnsTopologicalSort(vector<int>& adj,vector<int>& indegree,vector<bool>& visited,int source){
        queue<int> q;
        q.push(source);

        int last_node;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited[curr]=true;
            last_node = curr;

            int nbr=adj[curr];
            indegree[nbr]-=1;
            if(indegree[nbr]==0 and !visited[nbr])
                q.push(nbr);
        }
        return adj[last_node];
    }
    
    int maxDepthBFS(vector<vector<int>>& adj,vector<bool>& orig_visited,int n,int source,int avoid){
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(source);
        visited[source]=true;
        visited[avoid]=true;

        int levels=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                int curr = q.front();
                q.pop();
                orig_visited[curr]=true;

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
   
    int bfs(vector<int>& adj,vector<bool>& visited,int source){
        queue<int> q;
        q.push(source);
        visited[source]=true;

        int count=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(!visited[adj[curr]]){
                visited[adj[curr]]=true;
                q.push(adj[curr]);
            }
            count++;
        }
        return count;
    }

 public:
    int maximumInvitations(vector<int>& adj) {
        int n=adj.size();
        vector<vector<int>> reverse_adj(n);
        vector<int> indegree(n,0);

        for(int i=0;i<n;++i){
            reverse_adj[adj[i]].push_back(i);
            indegree[adj[i]]++;
        }

        int tot_tail_len = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            if(indegree[i]==0 and !visited[i]){
                int node = kahnsTopologicalSort(adj,indegree,visited,i);
                if(adj[adj[node]]==node){
                    int len_tail = maxDepthBFS(reverse_adj,visited,n,node,adj[node])-1;
                    tot_tail_len += len_tail;
                    visited[node]=false;
                }
            }
        }
       
        int two_size_cycles=0;
        int max_cycle_size=0;
        for(int i=0;i<n;++i){
            if(!visited[i]){
                int cycle_size = bfs(adj,visited,i);
                if(cycle_size==2)
                    two_size_cycles++;
                else
                    max_cycle_size = max(max_cycle_size,cycle_size);
            }
        }
        
        int cyclesize_2 = tot_tail_len + 2*two_size_cycles;
        return max(cyclesize_2,max_cycle_size);
    }
};