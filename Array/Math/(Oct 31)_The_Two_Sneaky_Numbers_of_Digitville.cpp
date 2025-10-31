// LeetCode Problem No. 3289
// Daily Challenge - 31/10/2025

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        vector<int> count(n, 0);
        vector<int> result;
        
        for (int num : nums) {
            count[num]++;
            if (count[num] == 2)
                result.push_back(num);
        }
        
        return result;
    }
};
