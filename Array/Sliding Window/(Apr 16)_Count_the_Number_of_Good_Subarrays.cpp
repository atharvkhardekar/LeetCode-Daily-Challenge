// LeetCode Problem No. 2537
// Daily Challenge - 16/04/2025

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            unordered_map<int, int> freq;
            long long count = 0;
            long long pairs = 0;
            int left = 0;
    
            for (int right = 0; right < nums.size(); ++right) {
                pairs += freq[nums[right]];
                freq[nums[right]]++;
    
                while (pairs >= k) {
                    count += nums.size() - right; 
                    freq[nums[left]]--;
                    pairs -= freq[nums[left]];
                    left++;
                }
            }
    
            return count;
        }
};
