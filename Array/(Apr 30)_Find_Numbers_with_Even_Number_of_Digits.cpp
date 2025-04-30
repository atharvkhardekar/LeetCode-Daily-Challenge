// LeetCode Problem No. 1295
// Daily Challenge - 30/04/2025

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count = 0;
            for (int num : nums) {
                int digits = 0;
                while (num > 0) {
                    num /= 10;
                    digits++;
                }
                if (digits % 2 == 0) {
                    count++;
                }
            }
            return count;
        }
    };
    