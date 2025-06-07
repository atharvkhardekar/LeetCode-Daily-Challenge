// LeetCode Problem No. 3170
// Daily Challenge - 07/06/2025

class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> char_pos(26);

        for (int i = 0; s[i]; ++i) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; ++j) {
                    if (!char_pos[j].empty()) {
                        s[char_pos[j].back()] = '*';
                        char_pos[j].pop_back();
                        break;
                    }
                }
            } else {
                char_pos[s[i] - 'a'].push_back(i);
            }
        }

        string res;
        for (char c : s) {
            if (c != '*') {
                res.push_back(c);
            }
        }

        return res;
    }
};
