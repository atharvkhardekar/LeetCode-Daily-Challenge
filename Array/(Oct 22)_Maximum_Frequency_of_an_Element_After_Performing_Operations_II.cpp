// LeetCode Problem No. 3347
// Daily Challenge - 22/10/2025

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;
        map<int, int> diff;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxVal);
            diff[l]++;
            diff[r + 1]--;
            diff[nums[i]] += 0;
        }

        int result = 1;
        int cumSum = 0;
        for (auto it = diff.begin(); it != diff.end(); it++) {
            int target = it->first;
            it->second += cumSum;
            int targetFreq = freq[target];
            int needConversion = it->second - targetFreq;
            int maxPossibleFreq = min(needConversion, numOperations);
            result = max(result, targetFreq + maxPossibleFreq);
            cumSum = it->second;
        }

        return result;
    }
};