// LeetCode Problem No. 679
// Daily Challenge - 18/08/2025

class Solution{
public:
    bool judgePoint24(vector<int> &cards)
    {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(vector<double> &nums)
    {
        if (nums.size() == 1)
        {
            return fabs(nums[0] - 24.0) < 1e-6;
        }
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                vector<double> next;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];
                vector<double> results = {a + b, a - b, b - a, a * b};
                if (fabs(b) > 1e-6)
                    results.push_back(a / b);
                if (fabs(a) > 1e-6)
                    results.push_back(b / a);

                for (double val : results)
                {
                    next.push_back(val);
                    if (solve(next))
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};