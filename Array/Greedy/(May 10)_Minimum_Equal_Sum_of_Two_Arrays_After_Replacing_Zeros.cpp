// LeetCode Problem No. 2918
// Daily Challenge - 10/05/2025

class Solution {
    using ll = long long;

    void calculate(ll& min_sum, int& zero_count, vector<int>& nums) {
        for (int ele : nums) {
            if (ele == 0) {
                zero_count++;
                min_sum++;
            } else {
                min_sum += ele;
            }
        }
    }

public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll min_sum1 = 0;
        int zero_count1 = 0;
        calculate(min_sum1, zero_count1, nums1);

        ll min_sum2 = 0;
        int zero_count2 = 0;
        calculate(min_sum2, zero_count2, nums2);

        if ((min_sum1 < min_sum2 && zero_count1 == 0) || 
            (min_sum2 < min_sum1 && zero_count2 == 0)) {
            return -1;
        }

        return max<ll>(min_sum1, min_sum2);
    }
};
