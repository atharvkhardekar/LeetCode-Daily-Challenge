// LeetCode Problem No. 3005
// Daily Challenge - 22/09/2025

class Solution{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> freq(101, 0);
        int maxFreq = 0;
        for (int num : nums)
        {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (freq[i] == maxFreq)
                ans += maxFreq;
        }
        return ans;
    }
};