// LeetCode Problem No. 2483
// Daily Challenge - 26/12/2025

class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--;   
            } else {
                penalty++;   
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }
        return bestHour;
    }
};