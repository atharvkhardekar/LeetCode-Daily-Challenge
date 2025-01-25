// LeetCode Problem No. 2948
// Daily Challenge - 25/01/2025

class Solution {
    #define pii pair<int,int>

 public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<pii> copy;
        for(int i=0; i<n; ++i){
            copy.push_back(make_pair(nums[i],i));
        }
        sort(copy.begin(), copy.end());

        int left=0, right=1;
        while(right<n){
            vector<int> pos={copy[left].second};

            while(right<n and abs(copy[right].first-copy[right-1].first) <= limit){
                pos.push_back(copy[right].second);
                right++;
            }
            sort(pos.begin(), pos.end());

            for(int i=0; i<right-left; ++i){
                nums[pos[i]] = copy[left+i].first;
            }
            left = right;
            right++;
        }
        return nums;
    }
};