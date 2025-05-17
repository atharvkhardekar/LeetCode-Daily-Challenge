// LeetCode Problem No. 75
// Daily Challenge - 17/05/2025

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;             
        int mid = 0;             
        int high = nums.size() - 1;  

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else { 
                swap(nums[mid], nums[high--]);
            }
        }
    }
};