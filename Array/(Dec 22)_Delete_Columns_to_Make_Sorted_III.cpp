// LeetCode Problem No. 960
// Daily Challenge - 22/12/2025

class Solution{
public:
    int solve(int i, int prev, vector<string> &strs, vector<vector<int>> &dp)
    {
        if (i == strs[0].size())
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int pick = 0;
        int skip = solve(i + 1, prev, strs, dp);
        if(prev == -1) {
            pick = 1 + solve(i + 1, i, strs, dp);
        } else {
            bool flag = true;
            for(int j = 0; j < strs.size(); j++) {
                if(strs[j][i] < strs[j][prev]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                pick = 1 + solve(i + 1, i, strs, dp);
            }
        }

        return dp[i][prev + 1] = max(pick, skip);   
    }

    int minDeletionSize(vector<string> &strs)
    {
        int m = strs[0].size();
        int n = strs.size();
        vector<vector<int>> dp(m, vector<int>(m + 1, -1));
        return m - solve(0, -1, strs, dp);
    }
};