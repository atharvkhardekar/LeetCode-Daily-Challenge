// LeetCode Problem No. 3027
// Daily Challenge - 03/09/2025

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
        });

        int count = 0;
        for (int A = 0; A < n - 1; ++A) {
            int bottom_right_y = INT_MIN;
            for (int B = A + 1; B < n; ++B) {
                if (points[B][1] <= points[A][1] && points[B][1] > bottom_right_y) {
                    count++;
                    bottom_right_y = points[B][1];
                }
            }
        }
        return count;
    }
};