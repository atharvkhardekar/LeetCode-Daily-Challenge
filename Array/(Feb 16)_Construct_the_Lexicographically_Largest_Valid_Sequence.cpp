// LeetCode Problem No. 1718
// Daily Challenge - 16/02/2025

class Solution {
    bool findLargestArray(vector<int>& res, vector<bool>& used, int pos, int n) {
        if (pos == 2 * n - 1) {
            return true;
        }

        if (res[pos] != 0) {
            return findLargestArray(res, used, pos + 1, n);
        }

        for (int i = n; i >= 1; --i) {
            if (used[i] == true) {
                continue;
            }

            used[i] = true;
            res[pos] = i;

            if (i == 1 && findLargestArray(res, used, pos + 1, n)) {
                return true;
            }

            if (i > 1 && (pos + i) < (2 * n - 1) && res[pos + i] == 0) {
                res[pos + i] = i;

                if (findLargestArray(res, used, pos + 1, n)) {
                    return true;
                }

                res[pos + i] = 0;
            }

            used[i] = false;
            res[pos] = 0;
        }

        return false;
    }

 public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> used(n + 1, false);

        findLargestArray(res, used, 0, n);
        return res;
    }
};
