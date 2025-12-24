// LeetCode Problem No. 3074
// Daily Challenge - 24/12/2025

class Solution{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int m = capacity.size(), az = reduce(apple.begin(), apple.end(), 0);
        uint8_t freq[51] = {0}, xMax = 0;
        for (uint8_t x : capacity)
        {
            freq[x]++;
            xMax = max(x, xMax);
        }
        int cnt = 0;
        for (int x = xMax; x > 0; x--)
        {
            int f = freq[x];
            if (f == 0)
                continue;
            if (x * f < az)
            {
                az -= x * f;
                cnt += f;
            }
            else
            {
                int q = (az + x - 1) / x; 
                return cnt + q;
            }
        }
        return -1;
    }
};

