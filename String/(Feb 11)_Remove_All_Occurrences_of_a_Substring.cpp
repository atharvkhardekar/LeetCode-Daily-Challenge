// LeetCode Problem No. 1910
// Daily Challenge - 11/02/2025

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            while (s.find(part) != string::npos) {  
                s.erase(s.find(part), part.size()); 
            }
            return s;
        }
    };

    
// Optimal Solution

class Solution {
    void calculateLPS(string& part,int& n,vector<int>& lps){
        int i=0,j=1;

        while(j<n){
            if(part[i]==part[j]){
                lps[j]=1+i;
                i++;
                j++;
            }else{
                if(i>0)     i=lps[i-1];
                else        j++;
            }
        }
    }

    void removeSubstrings(string& s,string& part,vector<int>& lps){
        int m=s.size();
        int n=part.size();
        int i=0;
        int j=0;

        while(i<m){
            if(s[i]==part[j]){
                i++;
                j++;
            }
            if(j==n){
                s = s.substr(0,i-n) + s.substr(i);
                m = s.size();
                i = max(0,i-2*n);
                j=0;
            }
            if(s[i]!=part[j]){
                if(j==0)    i++;
                else        j=lps[j-1];
            }
        }
    }

 public:
    string removeOccurrences(string s, string part) {
        int n=part.size();
        vector<int> lps(n,0);
        
        calculateLPS(part,n,lps);
        removeSubstrings(s,part,lps);
        return s;
    }
};