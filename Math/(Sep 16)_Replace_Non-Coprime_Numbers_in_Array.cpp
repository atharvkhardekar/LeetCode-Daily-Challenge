// LeetCode Problem No. 2197
// Daily Challenge - 16/09/2025

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            result.push_back(num);
            while (result.size() > 1) {
                int a = result.back();
                int b = result[result.size() - 2];
                int g = gcd(a, b);
                if (g > 1) {
                    result.pop_back();
                    result.pop_back();
                    long long lcm = (long long)a / g * b;
                    result.push_back((int)lcm);
                } else {
                    break;
                }
            }
        }
        return result;
    }
};
