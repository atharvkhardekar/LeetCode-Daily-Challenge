// LeetCode Problem No. 2661
// Daily Challenge - 20/01/2025

class Solution {
    #define pii pair<int,int>
    
 public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<pii> lookup(m*n+1);
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                lookup[mat[i][j]]=make_pair(i,j);

        vector<int> row_count(m,0);
        vector<int> col_count(n,0);

        for(int i=0;i<m*n;++i){
            pii coordinate = lookup[arr[i]];
            int x = coordinate.first;
            int y = coordinate.second;
            
            row_count[x]++;
            col_count[y]++;
            if(row_count[x]==n or col_count[y]==m)
                return i;
        }
        return 0;
    }
};