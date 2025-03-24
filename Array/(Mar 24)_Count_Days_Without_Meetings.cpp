// LeetCode Problem No. 3169
// Daily Challenge - 24/03/2025

class Solution {
    #define pii pair<int, int>

 public:
    int countDays(int totalDays, vector<vector<int>>& schedules) {
        vector<pii> events;

        for (auto& schedule : schedules) {
            events.push_back(make_pair(schedule[0], 1));
            events.push_back(make_pair(schedule[1] + 1, 0));
        }

        sort(events.begin(), events.end());

        int activeMeetings = 0;
        int freeDays = events[0].first - 1;

        for (int i = 0; i < events.size() - 1; ++i) {
            if (events[i].second == 0) {
                activeMeetings--;
            } else {
                activeMeetings++;
            }

            if (activeMeetings == 0) {
                freeDays += events[i + 1].first - events[i].first;
            }
        }

        freeDays += totalDays - events.back().first + 1;
        return freeDays;
    }
};
