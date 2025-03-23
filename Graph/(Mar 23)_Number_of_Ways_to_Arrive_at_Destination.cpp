// LeetCode Problem No. 1976
// Daily Challenge - 23/03/2025

// Shortest Path (Dijkstra's Algorithm)

class Solution {
    #define ll long long
    #define pll pair<ll, ll>
    #define MOD 1000000007

 public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> adj(n);
        
        for (auto& road : roads) {
            adj[road[0]].push_back(make_pair(road[1], road[2]));
            adj[road[1]].push_back(make_pair(road[0], road[2]));
        }

        priority_queue<pll, vector<pll>, greater<pll>> minheap;
        minheap.push(make_pair(0, 0));

        vector<bool> processed(n, false);
        vector<ll> count_ways(n, 0);
        vector<ll> min_cost(n, LONG_MAX);
        
        count_ways[0] = 1;
        min_cost[0] = 0;
        
        while (!minheap.empty()) {
            pll curr = minheap.top();
            minheap.pop();
            
            ll cost = curr.first;
            ll curr_node = curr.second;
            
            if (processed[curr_node]) {
                continue;
            }
            
            processed[curr_node] = true;
            
            for (auto& [nbr, weight] : adj[curr_node]) {
                if (!processed[nbr]) {
                    if (cost + weight == min_cost[nbr]) {
                        count_ways[nbr] = (count_ways[nbr] + count_ways[curr_node]) % MOD;
                    } else if (cost + weight < min_cost[nbr]) {
                        min_cost[nbr] = cost + weight;
                        count_ways[nbr] = count_ways[curr_node];
                        minheap.push(make_pair(cost + weight, nbr));
                    }
                }
            }
        }
        
        return count_ways[n - 1];
    }
};
