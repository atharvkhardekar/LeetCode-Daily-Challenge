// LeetCode Problem No. 3440
// Daily Challenge - 10/07/2025

class Solution {
    #define pii pair<int, int>

    int getFreeTimeByRescheduling(int& i, vector<pii>& top3, vector<int>& startTime, vector<int>& endTime) {
        int last_end = (i == 0) ? 0 : endTime[i - 1];

        if ((top3[2].first >= endTime[i] - startTime[i]) && (top3[2].second != i && top3[2].second != i + 1)) {
            return startTime[i + 1] - last_end;
        } else if ((top3[1].first >= endTime[i] - startTime[i]) && (top3[1].second != i && top3[1].second != i + 1)) {
            return startTime[i + 1] - last_end;
        } else if ((top3[0].first >= endTime[i] - startTime[i]) && (top3[0].second != i && top3[0].second != i + 1)) {
            return startTime[i + 1] - last_end;
        }

        return (startTime[i + 1] - last_end) - (endTime[i] - startTime[i]);
    }

public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        int n = startTime.size();

        vector<pii> top3(3, { -1, -1 });
        top3[0] = { startTime[0] - 0, 0 };

        for (int i = 1; i < n; ++i) {
            pii gap = { startTime[i] - endTime[i - 1], i };

            if (gap.first > top3[2].first) {
                top3[2] = gap;
            }
            if (top3[2].first > top3[1].first) {
                swap(top3[1], top3[2]);
            }
            if (top3[1].first > top3[0].first) {
                swap(top3[0], top3[1]);
            }
        }

        int max_free_time = 0;

        for (int i = 0; i < n - 1; ++i) {
            int free_time = getFreeTimeByRescheduling(i, top3, startTime, endTime);
            max_free_time = max(max_free_time, free_time);
        }

        return max_free_time;
    }
};
