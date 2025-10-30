// LeetCode Problem No. 1526
// Daily Challenge - 30/10/2025

class Solution{
public:
    int minNumberOperations(vector<int> &target)
    {
        int count = target[0];
        for (int i = 1; i < target.size(); i++)
            count += max(target[i] - target[i - 1], 0);
        return count;
    }
};
