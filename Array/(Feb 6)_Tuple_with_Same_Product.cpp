// LeetCode Problem No. 1726
// Daily Challenge - 06/02/2025

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        for (auto& pair : productCount) {
            int count = pair.second;
            if (count > 1) {
                result += (count * (count - 1) / 2) * 8; 
            }
        }
        return result;
    }
};