// LeetCode Problem No. 1865
// Daily Challenge - 06/07/2025

class FindSumPairs {
    vector<int> arr1, arr2;
    unordered_map<int, int> ele_freq;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for (int ele : nums2) {
            ele_freq[ele]++;
        }
    }

    void add(int index, int val) {
        ele_freq[arr2[index]]--;
        arr2[index] += val;
        ele_freq[arr2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int ele : arr1) {
            if (ele_freq.count(tot - ele)) {
                res += ele_freq[tot - ele];
            }
        }
        return res;
    }
};
