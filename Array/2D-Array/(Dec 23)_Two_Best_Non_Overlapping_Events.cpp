// LeetCode Problem No. 2054
// Daily Challenge - 23/12/2025

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> timeline; 
        for (auto& event : events) {
            int startTime = event[0]; 
            int endTime = event[1];   
            int value = event[2];     
            timeline.push_back({startTime, 1, value});
            timeline.push_back({endTime + 1, -1, value});
        }
        
        sort(timeline.begin(), timeline.end());

        int max_val = 0; 
        int max_seen = 0;
       
        for (auto& point : timeline) {
            int time = point[0];      
            int eventType = point[1]; 
            int value = point[2];

            if (eventType == 1) 
                max_val = max(max_val, max_seen + value);
            if (eventType == -1)
                max_seen = max(max_seen, value);
        }
        return max_val;
    }
};
