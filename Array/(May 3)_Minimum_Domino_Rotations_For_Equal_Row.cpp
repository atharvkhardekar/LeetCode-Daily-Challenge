// LeetCode Problem No. 1007
// Daily Challenge - 03/05/2025

class Solution {
    int tryRotationMatching(int number, vector<int>& first, vector<int>& second) {
        int count = 0;
        for (int i = 0; i < first.size(); ++i) {
            if (first[i] == number) {
                continue;
            } else if (second[i] == number) {
                count++;
            } else {
                return INT_MAX;
            }
        }
        return count;
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int min_rotations = INT_MAX;

        for (int number = 1; number <= 6; number++) {
            int count_tops = tryRotationMatching(number, tops, bottoms);
            int count_bottoms = INT_MAX;

            if (count_tops != INT_MAX) {
                count_bottoms = tryRotationMatching(number, bottoms, tops);
            }

            min_rotations = min(min_rotations, min(count_tops, count_bottoms));
        }

        return min_rotations == INT_MAX ? -1 : min_rotations;
    }
};