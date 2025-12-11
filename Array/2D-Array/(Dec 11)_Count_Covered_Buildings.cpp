// LeetCode Problem No. 3531
// Daily Challenge - 11/12/2025

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();
        
        vector<int> minRow(n+1, INT_MAX), maxRow(n+1, INT_MIN);
        vector<int> minCol(n+1, INT_MAX), maxCol(n+1, INT_MIN);

        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            minRow[x] = min(minRow[x], y);
            maxRow[x] = max(maxRow[x], y);
            minCol[y] = min(minCol[y], x);
            maxCol[y] = max(maxCol[y], x);
        }

        int count = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            bool hasLeft  = minRow[x] < y;
            bool hasRight = maxRow[x] > y;
            bool hasAbove = minCol[y] < x;
            bool hasBelow = maxCol[y] > x;

            if (hasLeft && hasRight && hasAbove && hasBelow)
                count++;
        }

        return count;
    }
};