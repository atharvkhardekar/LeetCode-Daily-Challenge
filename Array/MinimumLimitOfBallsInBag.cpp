// LeetCode Problem No. 1760
// Daily Challenge - 07/12/2024

class Solution {
    bool canAchievePenalty(vector<int>& nums, int penalty, int maxOperations) {
        int operations = 0;
        for (int& num : nums) {
            if (num > penalty)
                operations += ceil((double)(num - penalty) / penalty);
        }
        return operations <= maxOperations;
    }
 public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int mid;
        int result = INT_MAX;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (canAchievePenalty(nums, mid, maxOperations)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
