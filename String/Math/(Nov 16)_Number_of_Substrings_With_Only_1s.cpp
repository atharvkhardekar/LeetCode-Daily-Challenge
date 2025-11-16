// LeetCode Problem No. 1513
// Daily Challenge - 16/11/2025

class Solution{
public:
    int numSub(string s)
    {
        int ans = 0;
        int mod = 1e9 + 7;

        int continuesOnes = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                continuesOnes++;
            }
            else
            {
                continuesOnes = 0;
            }

            ans = (ans + continuesOnes) % mod;
        }

        return ans;
    }
};
