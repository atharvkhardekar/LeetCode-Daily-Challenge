// LeetCode Problem No. 1394
// Daily Challenge - 05/07/2025

class Solution{
 public:
    int findLucky(vector<int> &arr)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        
        for(auto i : arr) {
            mp[i]++;
        }

        for(auto m : mp) {
            if(m.first == m.second) {
                ans = max(ans, m.first);
            }
        }

        return ans ? ans : -1;
    }
};
