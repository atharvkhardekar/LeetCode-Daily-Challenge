// LeetCode Problem No. 1980
// Daily Challenge - 20/02/2025

class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            string result = "";
            
            for (int i = 0; i < n; i++) {
                result += (nums[i][i] == '0') ? '1' : '0';
            }
            
            return result;
        }
};

// Construct a new binary string by flipping the diagonal elements (nums[i][i]).
// This ensures the new string is different from every string in nums at least in one position.

// Since nums contains n unique binary strings of length n, there are 2ⁿ possible binary strings.
// The given list has only n strings, meaning at least one string is missing.
// The diagonalization method ensures the result differs from every string at at least one index, making it unique.

// Example 1 :
Input: nums = ["01", "10"]
Diagonal elements: nums[0][0] = '0', nums[1][1] = '0'
Flipping: "0" → "1", "0" → "1"
Output: "11"

// Example 2 :
Input: nums = ["00", "01"]
Diagonal elements: nums[0][0] = '0', nums[1][1] = '1'
Flipping: "0" → "1", "1" → "0"
Output: "10"


    
