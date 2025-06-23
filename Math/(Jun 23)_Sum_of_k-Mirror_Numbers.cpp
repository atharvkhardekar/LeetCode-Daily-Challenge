// LeetCode Problem No. 2081
// Daily Challenge - 23/06/2025

class Solution {
public:
    long long kMirror(int base, int count) {
        long long sum = 0;

        for (int length = 1; ; ++length) {
            int start = pow(10, (length - 1) / 2);
            int end = pow(10, (length + 1) / 2);

            for (int i = start; i < end; ++i) {
                long long palindrome = i;

                for (int j = (length % 2 == 0 ? i : i / 10); j > 0; j /= 10) {
                    palindrome = palindrome * 10 + j % 10;
                }

                if (isPalindrome(convertToBase(palindrome, base))) {
                    sum += palindrome;
                    if (--count == 0) {
                        return sum;
                    }
                }
            }
        }
    }

private:
    string convertToBase(long long num, int base) {
        string result;
        while (num > 0) {
            result += '0' + (num % base);
            num /= base;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
