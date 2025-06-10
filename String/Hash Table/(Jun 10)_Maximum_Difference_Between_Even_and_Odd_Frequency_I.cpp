// LeetCode Problem No. 3442
// Daily Challenge - 10/06/2025

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
       
        for (char c : s) {
            freq[c]++;
        }

        int maxOdd = -1;
        int minEven = 101; 

        for (auto& entry : freq) {
            int count = entry.second;
            if (count % 2 == 1) {
                maxOdd = max(maxOdd, count);
            } else {
                minEven = min(minEven, count);
            }
        }

        if (maxOdd == -1 || minEven == 101) {
            return 0; 
        }

        return maxOdd - minEven;
    }
};
