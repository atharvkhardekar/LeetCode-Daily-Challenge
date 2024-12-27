// LeetCode Problem No. 1014
// Daily Challenge - 27/12/2024

// Hint : values[i] + values[j] + (i-j) = (values[i] + i) + (values[j] - j) = first + second
 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int first = values[0] + 0;
        int maxScore = 0;
        
        for(int j=1; j<values.size(); j++){
            int second = values[j] - j;
            maxScore = max(maxScore, first+second);
            first = max(first, values[j]+j);
        }
        return maxScore;
    }
};