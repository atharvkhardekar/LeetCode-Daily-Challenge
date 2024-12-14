// LeetCode Problem No. 2762
// Daily Challenge - 14/12/2024

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> window; 
        long long count = 0;
        int left = 0; 

        for (int right = 0; right < nums.size(); ++right) {
            window.insert(nums[right]);

            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                ++left;
            }
            count += (right - left + 1);
        }
        return count;
    }
};