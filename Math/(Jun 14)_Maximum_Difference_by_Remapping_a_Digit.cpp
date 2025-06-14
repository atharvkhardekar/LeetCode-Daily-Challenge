// LeetCode Problem No. 2566
// Daily Challenge - 14/06/2025

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maxi = num, mini = num;

        for (char d = '0'; d <= '9'; ++d) {
            string temp = s;
            for (char& c : temp) {
                if (c == d) c = '9';
            }
            maxi = max(maxi, stoi(temp));
        }

        for (char d = '0'; d <= '9'; ++d) {
            string temp = s;
            for (char& c : temp) {
                if (c == d) c = '0';
            }
            mini = min(mini, stoi(temp));
        }

        return maxi - mini;
    }
};
