// LeetCode Problem No. 2558
// Daily Challenge - 12/12/2024

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        
        for (int i = 0; i < k; i++) {
            int maxGifts = maxHeap.top(); 
            maxHeap.pop(); 
            int remainingGifts = floor(sqrt(maxGifts)); 
            maxHeap.push(remainingGifts); 
        }
        
        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }
        return totalGifts;
    }
};