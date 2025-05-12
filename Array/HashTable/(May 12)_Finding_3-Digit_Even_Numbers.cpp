// LeetCode Problem No. 2094
// Daily Challenge - 12/05/2025

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int digit : digits) {
            freq[digit]++;
        }

        vector<int> result;

        for (int num = 100; num <= 999; ++num) {
            if (num % 2 != 0) continue; 

            int hundreds = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;

            vector<int> tempFreq = freq;

            if (--tempFreq[hundreds] >= 0 &&
                --tempFreq[tens] >= 0 &&
                --tempFreq[units] >= 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};
