// LeetCode Problem No. 407
// Daily Challenge - 19/01/2025

class Solution {
    #define pip pair<int,pair<int,int>>

    bool isValid(int& x,int& y,int& m,int& n){
        return (x>=0 and x<m and y>=0 and y<n);
    }

 public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        if(m<3 or n<3)  
            return 0;

        priority_queue<pip,vector<pip>,greater<pip>> minheap;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i==0 or i==m-1 or j==0 or j==n-1){
                    minheap.push(make_pair(heightMap[i][j],make_pair(i,j)));
                    visited[i][j]=true;
                }
            }
        }

        int level=0;
        int trapped_water = 0;
        vector<int> dir = {-1,0,1,0,-1};
        
        while(!minheap.empty()){
            pip curr = minheap.top();
            minheap.pop();

            int height = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            level = max(level,height);
            
            for(int i=0;i<4;++i){
                int newX = x + dir[i];
                int newY = y + dir[i+1];
                if(isValid(newX,newY,m,n) and !visited[newX][newY]){
                    visited[newX][newY] = true;
                    minheap.push(make_pair(heightMap[newX][newY],make_pair(newX,newY)));
                    if(heightMap[newX][newY] < level)
                        trapped_water += level - heightMap[newX][newY];
                }
            }
        }
        return trapped_water;
    }
};