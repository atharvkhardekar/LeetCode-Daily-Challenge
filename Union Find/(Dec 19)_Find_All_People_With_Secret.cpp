// LeetCode Problem No. 2092
// Daily Challenge - 19/12/2025

class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rankv[x] < rankv[y]) swap(x, y);
        parent[y] = x;
        if (rankv[x] == rankv[y]) rankv[x]++;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        unite(0, firstPerson);

        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> involved;

            int j = i;
            while (j < meetings.size() && meetings[j][2] == time) {
                unite(meetings[j][0], meetings[j][1]);
                involved.push_back(meetings[j][0]);
                involved.push_back(meetings[j][1]);
                j++;
            }

            unordered_set<int> good;
            for (int p : involved) {
                if (find(p) == find(0))
                    good.insert(find(p));
            }

            for (int p : involved) {
                if (!good.count(find(p))) {
                    parent[p] = p;
                }
            }

            i = j;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0))
                ans.push_back(i);
        }
        return ans;
    }
};