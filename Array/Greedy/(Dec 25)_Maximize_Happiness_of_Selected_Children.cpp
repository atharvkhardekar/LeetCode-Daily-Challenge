// LeetCode Problem No. 3075
// Daily Challenge - 25/12/2025

class Solution{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            int currSelected = happiness[i] - i;
            if (currSelected <= 0)
            {
                break;
            }
            ans += currSelected;
        }
        return ans;
    }
};
