// LeetCode Problem No. 1733
// Daily Challenge - 10/09/2025

class Solution{
public:
    static int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        int m = languages.size(); 

        vector<bitset<501>> know(m);
        for (int i = 0; i < m; i++)
            for (int l : languages[i])
                know[i][l] = 1;

        bitset<501> need = 0;
        for (auto &f : friendships)
        {
            int a = f[0] - 1, b = f[1] - 1;
            if ((know[a] & know[b]).any())
                continue; 
            need[a] = need[b] = 1;
        }

        if (need.count() == 0)
            return 0;

        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++)
        { 
            int cnt = 0;
            for (int i = 0; i < m; i++)
            {
                if (need[i] & !know[i][lang])
                    cnt++;
            }
            ans = min(ans, cnt);
        }

        return ans;
    }
};