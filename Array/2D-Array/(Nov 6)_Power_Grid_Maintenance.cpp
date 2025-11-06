// LeetCode Problem No. 3607
// Daily Challenge - 06/11/2025

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1), size(c + 1, 1);
        iota(parent.begin(), parent.end(), 0);
      
        vector<bool> online(c + 1, true);
      
        vector<set<int>> comp(c + 1);
        for (int i = 1; i <= c; i++)
            comp[i].insert(i);
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;

            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];

            if (comp[b].size() > 0) {
                comp[a].insert(comp[b].begin(), comp[b].end());
                comp[b].clear();
            }
        };

        for (auto &e : connections)
            unite(e[0], e[1]);

        vector<int> result;

        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = find(x);

            if (type == 1) {
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (!comp[root].empty())
                        result.push_back(*comp[root].begin());
                    else
                        result.push_back(-1);
                }
            } else { 
                if (online[x]) {
                    online[x] = false;
                    comp[root].erase(x);
                }
            }
        }

        return result;
    }
};