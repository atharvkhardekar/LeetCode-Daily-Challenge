// LeetCode Problem No. 2264
// Daily Challenge - 14/08/2025

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        vector<string> p = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
        for (int i = 0; i < p.size(); i++)
        {
            if (num.find(p[i]) != string::npos)
            {
                return p[i];
            }
        }
        return "";
    }
};
