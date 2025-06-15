// LeetCode Problem No. 1432
// Daily Challenge - 15/06/2025

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        string maxS = s;
        for (char d : s) {
            if (d != '9') {
                char from = d;
                for (char& c : maxS) {
                    if (c == from) c = '9';
                }
                break;
            }
        }
        int a = stoi(maxS);

        string minS = s;
        if (s[0] != '1') {
            char from = s[0];
            for (char& c : minS) {
                if (c == from) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char from = s[i];
                    for (char& c : minS) {
                        if (c == from) c = '0';
                    }
                    break;
                }
            }
        }
        int b = stoi(minS);

        return a - b;
    }
};
