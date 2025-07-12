// LeetCode Problem No. 1900
// Daily Challenge - 12/07/2025

class Solution {
    bool seen[28][28][28];
    int n;
    int min_rounds = INT_MAX;
    int max_rounds = INT_MIN;

    void allPossibleMatchups(int mask, int left, int right, int p1, int p2, int rounds, int l, int m, int r) {
        if (left >= right) {
            allPossibleMatchups(mask, 0, n - 1, p1, p2, rounds + 1, l, m, r);
        } 
        else if ((mask & (1 << left)) == 0) {
            allPossibleMatchups(mask, left + 1, right, p1, p2, rounds, l, m, r);
        } 
        else if ((mask & (1 << right)) == 0) {
            allPossibleMatchups(mask, left, right - 1, p1, p2, rounds, l, m, r);
        } 
        else if (left == p1 && right == p2) {
            min_rounds = min(min_rounds, rounds);
            max_rounds = max(max_rounds, rounds);
        } 
        else if (!seen[l][m][r]) {
            seen[l][m][r] = true;

            if (left != p1 && left != p2) {
                allPossibleMatchups(
                    mask ^ (1 << left), left + 1, right - 1, p1, p2, rounds,
                    l - (left < p1),
                    m - (left > p1 && left < p2),
                    r - (left > p2)
                );
            }

            if (right != p1 && right != p2) {
                allPossibleMatchups(
                    mask ^ (1 << right), left + 1, right - 1, p1, p2, rounds,
                    l - (right < p1),
                    m - (right > p1 && right < p2),
                    r - (right > p2)
                );
            }
        }
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int mask = (1 << n) - 1;
        firstPlayer -= 1;
        secondPlayer -= 1;

        memset(seen, false, sizeof(seen));
        this->n = n;

        allPossibleMatchups(mask, 0, n - 1, firstPlayer, secondPlayer, 1,
                            firstPlayer, secondPlayer - firstPlayer - 1, n - 1 - secondPlayer);

        return {min_rounds, max_rounds};
    }
};