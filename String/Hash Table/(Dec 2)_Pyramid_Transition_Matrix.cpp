// LeetCode Problem No. 756
// Daily Challenge - 29/12/2025

class Solution{
public:
    bool solve(string bottom, string curr, int i, int j,
               unordered_map<string, int> &mp,
               unordered_map<string, bool> &dp)
    {

        if (i == 0)
            return true;

        if (curr.empty() && dp.count(bottom))
            return dp[bottom];

        if (curr.size() == i - 1)
        {
            bool res = solve(curr, "", i - 1, 0, mp, dp);
            dp[bottom] = res;
            return res;
        }

        for (int k = 0; k < 6; k++)
        {
            char c = 'A' + k;
            string pattern;
            pattern += bottom[j];
            pattern += bottom[j + 1];
            pattern += c;

            if (mp.count(pattern))
            {
                if (solve(bottom, curr + c, i, j + 1, mp, dp))
                    return true;
            }
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        unordered_map<string, int> mp;
        for (auto i : allowed)
        {
            mp[i]++;
        }
        unordered_map<string, bool> dp;
        return solve(bottom, "", bottom.size(), 0, mp, dp);
    }
};

