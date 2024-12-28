// LeetCode Problem No. 689
// Daily Challenge - 28/12/2024

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0); 
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<int> leftBest(n, 0), rightBest(n, n - k);

        int maxSum = prefixSum[k] - prefixSum[0];
        for (int i = k; i < n; ++i) {
            if (prefixSum[i + 1] - prefixSum[i + 1 - k] > maxSum) {
                maxSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
                leftBest[i] = i + 1 - k;
            } else {
                leftBest[i] = leftBest[i - 1];
            }
        }

        maxSum = prefixSum[n] - prefixSum[n - k];
        for (int i = n - k - 1; i >= 0; --i) {
            if (prefixSum[i + k] - prefixSum[i] >= maxSum) {
                maxSum = prefixSum[i + k] - prefixSum[i];
                rightBest[i] = i;
            } else {
                rightBest[i] = rightBest[i + 1];
            }
        }

        vector<int> result(3, 0);
        maxSum = 0;
        for (int mid = k; mid <= n - 2 * k; ++mid) {
            int left = leftBest[mid - 1];
            int right = rightBest[mid + k];
            int currentSum = (prefixSum[mid + k] - prefixSum[mid]) + 
                             (prefixSum[left + k] - prefixSum[left]) + 
                             (prefixSum[right + k] - prefixSum[right]);
            if (currentSum > maxSum) {
                maxSum = currentSum;
                result = {left, mid, right};
            }
        }
        return result;
    }
};