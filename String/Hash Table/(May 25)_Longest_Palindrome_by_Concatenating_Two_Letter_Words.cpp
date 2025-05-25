// LeetCode Problem No. 2131
// Daily Challenge - 25/05/2025

class Solution {
public:
    int longestPalindrome(vector<string>& input) {
        unordered_map<string, int> freq;

        for (const string& str : input) {
            freq[str]++;
        }

        int totalLength = 0;

        for (const string& str : input) {
            if (freq[str] <= 0) {
                continue;
            }

            string reversed = string{str[1], str[0]};

            if (reversed[0] == reversed[1] && freq[reversed] == 1) {
                continue;
            }

            if (freq.count(reversed) && freq[reversed] > 0) {
                totalLength += 4;
                freq[str]--;
                freq[reversed]--;
            }
        }

        for (const auto& entry : freq) {
            const string& key = entry.first;
            if (entry.second > 0 && key[0] == key[1]) {
                totalLength += 2;
                break;
            }
        }

        return totalLength;
    }
};