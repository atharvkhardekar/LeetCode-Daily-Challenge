// LeetCode Problem No. 840
// Daily Challenge - 30/12/2025

class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
  
        if (grid[r+1][c+1] != 5) return false;

        vector<bool> seen(10, false);

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || seen[val]) 
                    return false;
                seen[val] = true;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != 15)
                return false;
            if (grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != 15)
                return false;
        }

        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != 15)
            return false;
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};