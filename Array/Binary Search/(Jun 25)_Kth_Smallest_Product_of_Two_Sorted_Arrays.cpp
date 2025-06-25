// LeetCode Problem No. 2040
// Daily Challenge - 25/06/2025

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -10000000000LL;
        long long right = 10000000000LL;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countProducts(nums1, nums2, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

private:
    long long countProducts(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count = 0;

        for (int num1 : nums1) {
            if (num1 == 0) {
                if (target >= 0) {
                    count += nums2.size();
                }
                continue;
            }

            int low = 0;
            int high = nums2.size();

            while (low < high) {
                int mid = low + (high - low) / 2;
                long long product = (long long) num1 * nums2[mid];

                if (product <= target) {
                    if (num1 > 0) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                } else {
                    if (num1 > 0) {
                        high = mid;
                    } else {
                        low = mid + 1;
                    }
                }
            }

            if (num1 > 0) {
                count += low;
            } else {
                count += nums2.size() - low;
            }
        }

        return count;
    }
};