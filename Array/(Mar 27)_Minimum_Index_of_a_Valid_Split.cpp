// LeetCode Problem No. 2780
// Daily Challenge - 27/03/2025

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
    
            int candidate = nums[0], count = 0;
            for (int num : nums) {
                if (num == candidate) {
                    count++;
                } else {
                    count--;
                    if (count == 0) {
                        candidate = num;
                        count = 1;
                    }
                }
            }
    
            int totalCount = count_if(nums.begin(), nums.end(), [&](int num) { return num == candidate; });
            if (totalCount * 2 <= n) return -1; 
    
            int leftCount = 0, rightCount = totalCount;
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == candidate) {
                    leftCount++;
                    rightCount--;
                }
    
                if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                    return i;
                }
            }
            
            return -1;
        }
};    