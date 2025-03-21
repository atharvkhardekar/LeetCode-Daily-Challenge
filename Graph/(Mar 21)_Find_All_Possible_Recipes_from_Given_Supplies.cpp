// LeetCode Problem No. 2115
// Daily Challenge - 21/03/2025

// Kahn’s algorithm (BFS-based Topological Sorting)

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, vector<string>> adj;
            unordered_map<string, int> indegree;
            unordered_set<string> supply(supplies.begin(), supplies.end());
    
            for (int i = 0; i < recipes.size(); ++i) {
                indegree[recipes[i]] = 0;
                for (string& ingredient : ingredients[i]) {
                    if (supply.count(ingredient) == 0) {
                        adj[ingredient].push_back(recipes[i]);
                        indegree[recipes[i]]++;
                    }
                }
            }
    
            queue<string> q;
            for (auto& [recipe, indeg] : indegree) {
                if (indeg == 0) {
                    q.push(recipe);
                }
            }
    
            vector<string> res;
            while (!q.empty()) {
                string curr_recipe = q.front();
                q.pop();
                res.push_back(curr_recipe);
    
                for (string& next_recipe : adj[curr_recipe]) {
                    indegree[next_recipe]--;
                    if (indegree[next_recipe] == 0) {
                        q.push(next_recipe);
                    }
                }
            }
    
            return res;
        }
    };
    