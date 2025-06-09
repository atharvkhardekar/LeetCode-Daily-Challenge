// LeetCode Problem No. 440
// Daily Challenge - 09/06/2025

class Solution
{
public:
    int getReqNum(long a, long b, long &n)
    {
        int gap = 0;
        while (a <= n)
        {
            gap += std::min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }

    int findKthNumber(long n, long k)
    {
        long num = 1;
        for (int i = 1; i < k;)
        {
            int req = getReqNum(num, num + 1, n);
            if (i + req <= k)
            {
                i += req;
                num++;
            }
            else
            {
                i++;
                num *= 10;
            }
        }
        return num;
    }
};
