// LeetCode Problem No. 2401
// Daily Challenge - 18/03/2025

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int left = 0, right = 0;
            int bitMask = 0, maxLen = 0;
            
            while (right < nums.size()) {
                while ((bitMask & nums[right]) != 0) {
                    bitMask ^= nums[left]; 
                    left++;
                }
                
                bitMask |= nums[right];
                maxLen = max(maxLen, right - left + 1);
                right++; 
            }
            
            return maxLen;
        }
    };
    