// LeetCode Problem No. 3342
// Daily Challenge - 08/05/2025

class Solution
{
    struct Pair
    {
        int time, i, j, stepCost;
        Pair(int t, int x, int y, int s) : time(t), i(x), j(y), stepCost(s) {}

        bool operator>(const Pair &other) const
        {
            return time > other.time;
        }
    };

public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int r = moveTime.size(), c = moveTime[0].size();
        vector<vector<int>> minimumTime(r, vector<int>(c, INT_MAX));
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        pq.emplace(0, 0, 0, 1);  
        minimumTime[0][0] = 0;

        while (!pq.empty())
        {
            Pair top = pq.top();
            pq.pop();

            int i = top.i, j = top.j, moveCost = top.stepCost, currTime = top.time;

            if (i == r - 1 && j == c - 1)
                return currTime;

            int nextMoveCost = (moveCost == 1 ? 2 : 1);

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto &dir : directions)
            {
                int ni = i + dir.first;
                int nj = j + dir.second;

                if (ni >= 0 && ni < r && nj >= 0 && nj < c)
                {
                    int waitTime = max(currTime, moveTime[ni][nj]);
                    int newTime = waitTime + moveCost;
                    if (minimumTime[ni][nj] > newTime)
                    {
                        minimumTime[ni][nj] = newTime;
                        pq.emplace(newTime, ni, nj, nextMoveCost);
                    }
                }
            }
        }

        return -1;
    }
};