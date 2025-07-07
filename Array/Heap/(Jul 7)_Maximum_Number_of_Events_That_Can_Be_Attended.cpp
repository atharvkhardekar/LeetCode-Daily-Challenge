// LeetCode Problem No. 1353
// Daily Challenge - 07/07/2025

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());

        int n = events.size();
        int pos = 0;
        int time = 1;
        int attended = 0;
        priority_queue<int,vector<int>,greater<int>> minheap;
        while(pos<n or !minheap.empty()){
            if(minheap.empty())
                time = max(time,events[pos][0]);
        
            while(pos<n and events[pos][0]==time){
                minheap.push(events[pos][1]);
                pos++;
            }
         
            while(!minheap.empty() and minheap.top()<time)
                minheap.pop();
          
            if(!minheap.empty()){
                minheap.pop();
                attended++;
            }
            time++;
        }
        return attended;
    }
};