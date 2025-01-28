// LeetCode Problem No. 2658
// Daily Challenge - 28/01/2025

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        function<int(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
                return 0;
            }

            int fishCount = grid[r][c];
            grid[r][c] = 0; 

            fishCount += dfs(r + 1, c);
            fishCount += dfs(r - 1, c);
            fishCount += dfs(r, c + 1);
            fishCount += dfs(r, c - 1);

            return fishCount;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) { 
                    maxFish = max(maxFish, dfs(i, j));
                }
            }
        }
        return maxFish;
    }
};