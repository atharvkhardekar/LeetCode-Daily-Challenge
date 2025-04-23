// LeetCode Problem No. 1399
// Daily Challenge - 23/04/2025

class Solution {
    public:
        int countLargestGroup(int n) {
            vector<int> count(37, 0); 
            for (int i = 1; i <= n; ++i) {
                int sum = digitSum(i);
                count[sum]++;
            }
    
            int maxSize = *max_element(count.begin(), count.end());
            int result = 0;
            for (int c : count) {
                if (c == maxSize) result++;
            }
    
            return result;
        }
    
    private:
        int digitSum(int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
};
    