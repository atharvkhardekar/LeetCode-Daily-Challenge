// LeetCode Problem No. 1639
// Daily Challenge - 29/12/2024

class Solution {
    #define ll long long

    int mem[1001][1001];
    int MOD = 1000000007;
    int target_size;
    int word_size;
    int n;
    vector<vector<int>> char_freq;
    
    int countWays(vector<string>& words,int idx,string& target,int tpos){
        if(tpos==target_size) 
            return idx<=word_size;
        if(idx>=word_size or (word_size - idx < target_size - tpos))
            return 0;
        if(mem[idx][tpos]!=-1)  
            return mem[idx][tpos];
        
        char curr = target[tpos];
        
        ll ways_by_not_matching = countWays(words,idx+1,target,tpos);
        ll ways_by_matching = countWays(words,idx+1,target,tpos+1)%MOD;
        ll total_ways = (ways_by_not_matching + (ll)char_freq[idx][curr-'a'] * ways_by_matching) % MOD;
        
        return mem[idx][tpos] = total_ways;
    }

public:
    int numWays(vector<string>& words, string target) {
        target_size = target.size();
        word_size = words[0].size();
        n = words.size();
        char_freq = vector<vector<int>>(word_size,vector<int>(26,0));

        for(int i=0;i<n;++i){
            for(int j=0;j<word_size;++j){
                char curr = words[i][j];
                char_freq[j][curr-'a']++;
            }
        }
        memset(mem,-1,sizeof(mem));
        return countWays(words,0,target,0);
    }
};