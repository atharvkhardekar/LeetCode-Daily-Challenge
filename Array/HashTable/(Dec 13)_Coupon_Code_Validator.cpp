// LeetCode Problem No. 3606
// Daily Challenge - 13/12/2025

class Solution{
public:
    vector<string> validateCoupons(vector<string> &code,
                                   vector<string> &businessLine,
                                   vector<bool> &isActive)
    {

        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}};

        vector<pair<int, string>> valid;

        for (int i = 0; i < code.size(); i++)
        {
            if (isActive[i] &&
                priority.count(businessLine[i]) &&
                isValidCode(code[i]))
            {

                valid.push_back({priority[businessLine[i]], code[i]});
            }
        }

        sort(valid.begin(), valid.end());

        vector<string> result;
        for (auto &p : valid)
        {
            result.push_back(p.second);
        }

        return result;
    }

private:
    bool isValidCode(const string &s)
    {
        if (s.empty())
            return false;
        for (char c : s)
        {
            if (!isalnum(c) && c != '_')
                return false;
        }
        return true;
    }
};
