// LeetCode Problem No. 2179
// Daily Challenge - 15/04/2025

class Solution {
    using ll = long long;
    vector<ll> seg_tree;

    void updateSegTree(ll st_idx,ll start,ll end,ll& query_idx){
        if(end<query_idx or start>query_idx)
            return;
        if(start==end){
            seg_tree[st_idx]++;
            return;
        }

        ll mid = start + (end-start)/2;
        updateSegTree(2*st_idx,start,mid,query_idx);
        updateSegTree(2*st_idx+1,mid+1,end,query_idx);
        seg_tree[st_idx] = seg_tree[2*st_idx] + seg_tree[2*st_idx+1];
    }
    int rangeSumQuery(ll st_idx,ll start,ll end,ll qs,ll qe){
        if(qs>end or qe<start)  return 0;
        if(start>=qs and end<=qe)   return seg_tree[st_idx];

        ll mid = start + (end-start)/2;
        ll left_sum = rangeSumQuery(2*st_idx,start,mid,qs,qe);
        ll right_sum = rangeSumQuery(2*st_idx+1,mid+1,end,qs,qe);
        return left_sum + right_sum;
    }

public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        seg_tree = vector<ll>(4*n+1,0);

        unordered_map<ll,ll> nums2_val_idx;
        for(ll i=0;i<n;++i)
            nums2_val_idx[nums2[i]] = i;
        
        updateSegTree(1,0,n-1,nums2_val_idx[nums1[0]]);
        
        ll count_good_triplets = 0;
        for(int i=1;i<n-1;++i){
            ll nums2_idx = nums2_val_idx[nums1[i]];
            ll common_left_elements = rangeSumQuery(1,0,n-1,0,nums2_idx);
            ll uncommon_left_elements = (i-common_left_elements);
            ll common_right_elements = (n-nums2_idx-1) - uncommon_left_elements;
            count_good_triplets += common_left_elements * common_right_elements;

            updateSegTree(1,0,n-1,nums2_idx);
        }
        return count_good_triplets;
    }
};