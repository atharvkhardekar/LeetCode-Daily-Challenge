// LeetCode Problem No. 2503
// Daily Challenge - 28/03/2025

class Solution {
    public:
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
        vector<int> maxPoints(vector<vector<int>>& matrix, vector<int>& thresholds) {
            int rows = matrix.size();
            int cols = matrix[0].size();
    
            int numQueries = thresholds.size();
            vector<int> output(numQueries, 0);
    
            vector<pair<int, int>> indexedQueries;
            for(int i = 0; i < numQueries; i++) {
                indexedQueries.push_back({thresholds[i], i});
            }
    
            sort(begin(indexedQueries), end(indexedQueries));
    
            priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            int count = 0;
            minHeap.push({matrix[0][0], 0, 0});
            visited[0][0] = true;
    
            for(int i = 0; i < numQueries; i++) {
                int queryVal = indexedQueries[i].first;
                int queryIndex = indexedQueries[i].second;
                
                while(!minHeap.empty() && minHeap.top()[0] < queryVal) {
                    int x = minHeap.top()[1];
                    int y = minHeap.top()[2];
                    minHeap.pop();
                    count++;
    
                    for(auto &dir : directions) {
                        int newX = x + dir[0];
                        int newY = y + dir[1];
                        if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY]) {
                            minHeap.push({matrix[newX][newY], newX, newY});
                            visited[newX][newY] = true;
                        }
                    }
                }
                output[queryIndex] = count;
            }
            
            return output;
        }
};
    