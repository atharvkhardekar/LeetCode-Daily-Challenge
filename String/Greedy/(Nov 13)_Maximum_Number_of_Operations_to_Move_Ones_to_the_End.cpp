// LeetCode Problem No. 3228
// Daily Challenge - 13/11/2025

class Solution{
public:
    int maxOperations(string s)
    {
        int operations = 0;
        int ones_count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                ones_count++;
            }
            else if (i > 0 && s[i - 1] == '1')
            {

                operations += ones_count;
            }
        }

        return operations;
    }
};
