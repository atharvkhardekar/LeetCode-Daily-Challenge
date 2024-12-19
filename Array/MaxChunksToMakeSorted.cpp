// LeetCode Problem No. 769
// Daily Challenge - 19/12/2024

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxSoFar = -1;
        int chunks = 0; 

        for (int i = 0; i < arr.size(); ++i) {
            maxSoFar = max(maxSoFar, arr[i]);

            if (maxSoFar == i) {
                ++chunks;
            }
        }
        return chunks;
    }
};