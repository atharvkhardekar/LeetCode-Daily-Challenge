// LeetCode Problem No. 1323
// Daily Challenge - 16/08/2025

class Solution{
public:
    int maximum69Number(int num)
    {
        string s = to_string(num);
        for (char &c : s)
        {
            if (c == '6')
            {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};
