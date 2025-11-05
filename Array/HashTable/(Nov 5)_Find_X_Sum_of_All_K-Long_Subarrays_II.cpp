// LeetCode Problem No. 3321
// Daily Challenge - 05/11/2025

class Solution{
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<long long> ans(n - k + 1);
        unordered_map<int, int> freq;

        auto cmp = [&](int a, int b)
        {
            if (freq[a] != freq[b])
            {
                return freq[a] < freq[b];
            }
            return a < b;
        };

        set<int, decltype(cmp)> topX(cmp), rest(cmp);
        long long sumTop = 0;

        auto rebalance = [&]()
        {
            while ((int)topX.size() < min(x, (int)freq.size()) && !rest.empty())
            {
                int best = *prev(rest.end());
                rest.erase(prev(rest.end()));
                topX.insert(best);
                sumTop += 1LL * freq[best] * best;
            }

            while ((int)topX.size() > x)
            {
                int worst = *topX.begin();
                topX.erase(topX.begin());
                rest.insert(worst);
                sumTop -= 1LL * freq[worst] * worst;
            }

            while (!topX.empty() && !rest.empty())
            {
                int worstTop = *topX.begin();
                int bestRest = *prev(rest.end());
                int fw = freq[worstTop], fr = freq[bestRest];

                if (fr > fw || (fr == fw && bestRest > worstTop))
                {
                    topX.erase(topX.begin());
                    rest.erase(prev(rest.end()));
                    topX.insert(bestRest);
                    rest.insert(worstTop);
                    sumTop += 1LL * fr * bestRest - 1LL * fw * worstTop;
                }
                else
                {
                    break;
                }
            }
        };

        for (int i = 0; i < n; ++i)
        {
            int v = nums[i];
            int old = freq[v];

            if (old > 0)
            {
                if (topX.erase(v))
                {
                    sumTop -= 1LL * old * v;
                }
                else
                {
                    rest.erase(v);
                }
            }

            freq[v] = old + 1;
            rest.insert(v);
            rebalance();

            if (i >= k)
            {
                int u = nums[i - k];
                int oldU = freq[u];

                if (topX.erase(u))
                {
                    sumTop -= 1LL * oldU * u;
                }
                else
                {
                    rest.erase(u);
                }

                if (oldU == 1)
                {
                    freq.erase(u);
                }
                else
                {
                    freq[u] = oldU - 1;
                    rest.insert(u);
                }
                rebalance();
            }

            if (i >= k - 1)
            {
                ans[i - k + 1] = sumTop;
            }
        }

        return ans;
    }
};
