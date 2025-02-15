// LeetCode Problem No. 2698
// Daily Challenge - 15/02/2025

class Solution {
    bool isValid(string& sq, int pos, int sum, int& val) {
        if (pos >= sq.size()) {
            return sum == val;
        }

        for (int i = 0; i + pos < sq.size(); ++i) {
            int curr_val = stoi(sq.substr(pos, i + 1));
            if (isValid(sq, i + pos + 1, sum + curr_val, val)) {
                return true;
            }
        }
        return false;
    }

 public:
    int punishmentNumber(int n) {
        int punishment_number = 1;

        for (int i = 2; i <= n; ++i) {
            string sq = to_string(i * i);
            if (isValid(sq, 0, 0, i)) {
                punishment_number += i * i;
            }
        }
        return punishment_number;
    }
};
