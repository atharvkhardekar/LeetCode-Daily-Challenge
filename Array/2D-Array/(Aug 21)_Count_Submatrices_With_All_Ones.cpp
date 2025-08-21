// LeetCode Problem No. 1504
// Daily Challenge - 21/08/2025

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int count = 0, curr_count;
        vector<int> histogram(n);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==1)    histogram[j]+=1;
                else                histogram[j]=0;
            }
            stack<vector<int>> st;  
            st.push({-1,-1,0});

            for(int j=0;j<n;++j){
                while(st.top()[0]>=histogram[j])
                        st.pop();

                curr_count = histogram[j] * (j-st.top()[1]) + st.top()[2];
                st.push({histogram[j],j,curr_count});
                count += curr_count;
            }
        }
        return count;
    }
};
