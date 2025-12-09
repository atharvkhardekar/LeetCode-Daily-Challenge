// LeetCode Problem No. 3583
// Daily Challenge - 09/12/2025

class Solution{
public:
    int specialTriplets(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        unordered_map<int, int> prefix;
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i : nums)
        {

            int total = mp[2 * i];
            int left = prefix[2 * i];
            int right = total - left;
            if (i == 0)
            {
                right--;
            }

            prefix[i]++;

            ans = (ans + left * 1LL * right) % mod;
        }

        return ans;
    }
};