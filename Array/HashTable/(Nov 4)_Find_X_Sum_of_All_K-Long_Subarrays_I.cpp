// LeetCode Problem No. 3318
// Daily Challenge - 04/11/2025

class Solution{
public:
    void insert(unordered_map<int, int> &freq,
                multiset<pair<int, int>> &ms, int num)
    {
        if (freq[num] > 0)
        {
            auto it = ms.find({freq[num], num});
            if (it != ms.end())
            {
                ms.erase(it);
            }
        }
        freq[num]++;
        ms.insert({freq[num], num});
    }

    void remove(unordered_map<int, int> &freq,
                multiset<pair<int, int>> &ms, int num)
    {

        ms.erase(ms.find({freq[num], num}));
        freq[num]--;
        if (freq[num] == 0)
        {
            freq.erase(num);
        }
        else
        {
            ms.insert({freq[num], num});
        }
    }

    int getSum(multiset<pair<int, int>> &ms, int x)
    {

        int sum = 0;

        for (auto i = ms.rbegin(); i != ms.rend(); i++)
        {
            x--;
            if (x < 0)
            {
                break;
            }
            sum += i->second * i->first;
        }

        return sum;
    }
    vector<int> findXSum(vector<int> &freq, int k, int x)
    {
        unordered_map<int, int> mp;
        multiset<pair<int, int>> ms;

        vector<int> ans;
        int n = freq.size();

        for (int i = 0; i < k; i++)
        {
            insert(mp, ms, freq[i]);
        }

        ans.push_back(getSum(ms, x));

        for (int i = k; i < n; i++)
        {
            insert(mp, ms, freq[i]);
            remove(mp, ms, freq[i - k]);

            ans.push_back(getSum(ms, x));
        }

        return ans;
    }
};