// LeetCode Problem No. 2106
// Daily Challenge - 03/08/2025

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<vector<int>> left;
        int i = 0;
        for (; i < n && fruits[i][0] <= startPos; ++i) {
            left.push_back({ startPos - fruits[i][0], fruits[i][1] });
        }
        reverse(left.begin(), left.end());

        vector<vector<int>> right;
        for (; i < n; ++i) {
            right.push_back({ fruits[i][0] - startPos, fruits[i][1] });
        }

        vector<int> psum_left(left.size() + 1);
        vector<int> psum_right(right.size() + 1);

        for (int j = 0; j < (int)left.size(); ++j) {
            psum_left[j + 1] = psum_left[j] + left[j][1];
        }

        for (int j = 0; j < (int)right.size(); ++j) {
            psum_right[j + 1] = psum_right[j] + right[j][1];
        }

        auto count_le = [&](const vector<vector<int>>& A, int steps) {
            return upper_bound(
                A.begin(), A.end(), steps,
                [](int t, const vector<int>& v) {
                    return t < v[0];
                }
            ) - A.begin();
        };

        int max_collection = 0;

        for (i = 0; i <= k; ++i) {
            int ub_left = count_le(left, i);
            int ub_right = count_le(right, k - 2 * i);
            max_collection = max(max_collection, psum_left[ub_left] + psum_right[ub_right]);

            ub_right = count_le(right, i);
            ub_left = count_le(left, k - 2 * i);
            max_collection = max(max_collection, psum_left[ub_left] + psum_right[ub_right]);
        }

        return max_collection;
    }
};
