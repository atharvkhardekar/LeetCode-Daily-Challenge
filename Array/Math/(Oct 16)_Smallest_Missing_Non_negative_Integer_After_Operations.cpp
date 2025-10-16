// LeetCode Problem No. 2598
// Daily Challenge - 16/10/2025

int mod[100000] = {0};

class Solution{
public:
    static int findSmallestInteger(vector<int> &nums, int value)
    {
        const int n = nums.size();
        memset(mod, 0, value * 4);
        for (int x : nums)
        {
            x %= value;
            if (x < 0)
                x += value;
            mod[x]++;
        }
        for (int i = 0; i < n; i++)
            if (--mod[i % value] < 0)
                return i;
        return n;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();