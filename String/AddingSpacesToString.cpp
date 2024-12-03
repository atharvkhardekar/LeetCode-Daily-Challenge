// LeetCode Problem No. 2109
// Daily Challenge - 03/12/2024

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int m=s.size();
        int n=spaces.size();

        string result;
        int i=0;
        int j=0;

        while(i<m){
            if(j<n and i == spaces[j]){
                result.push_back(' ');
                j++;
            }
            result.push_back(s[i]);
            i++;
        }
        return result;
    }
};